#include <iostream>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int k) {
        key = k;
        left = right = nullptr;
    }
};

class BST {
private:
    BSTNode *root;

    // ====== helper functions ======

    void clear(BSTNode *node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    // Normal insert (duplicates go to LEFT so that BST property matches your statement)
    BSTNode* insert(BSTNode *node, int key) {
        if (node == nullptr) {
            return new BSTNode(key);
        }
        if (key <= node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

    // Non-recursive search (normal search)
    bool search(BSTNode *node, int key) {
        while (node != nullptr) {
            if (key == node->key) return true;
            else if (key < node->key) node = node->left;
            else node = node->right;
        }
        return false;
    }

    // ===== Task 2.1: recursive search workhorse =====
    bool recSearch(BSTNode *node, int key) {
        if (node == nullptr) return false;
        if (key == node->key) return true;
        else if (key < node->key) return recSearch(node->left, key);
        else return recSearch(node->right, key);
    }

    // ===== Task 2.2: count nodes workhorse =====
    int countNodes(BSTNode *node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // ===== Task 2.3: height workhorse =====
    // Here: height = number of levels in longest root-to-leaf path
    // empty tree = 0, single node = 1
    int getHeight(BSTNode *node) {
        if (node == nullptr) return 0;
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        return 1 + (lh > rh ? lh : rh);
    }

    // ===== Task 2.4: doubleTree workhorse =====
    void doubleTree(BSTNode *node) {
        if (node == nullptr) return;

        // Save original left child
        BSTNode *oldLeft = node->left;

        // Create duplicate node and insert as LEFT child
        node->left = new BSTNode(node->key);
        node->left->left = oldLeft;   // duplicate's left points to old left subtree

        // Now recursively double the original left subtree and right subtree
        doubleTree(oldLeft);
        doubleTree(node->right);
    }

    // ===== Task 2.5: print all paths workhorse =====
    void printAllPaths(BSTNode *node, int path[], int pathLen) {
        if (node == nullptr) return;

        // add current node to the path
        path[pathLen] = node->key;
        pathLen++;

        // if leaf, print this path
        if (node->left == nullptr && node->right == nullptr) {
            for (int i = 0; i < pathLen; i++) {
                cout << path[i];
                if (i != pathLen - 1) cout << " -> ";
            }
            cout << endl;
        } else {
            // otherwise go down
            printAllPaths(node->left, path, pathLen);
            printAllPaths(node->right, path, pathLen);
        }
    }

    // ===== remove (delete) a key from BST =====
    BSTNode* findMin(BSTNode *node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    BSTNode* remove(BSTNode *node, int key) {
        if (node == nullptr) return nullptr;

        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            // node to delete found
            if (node->left == nullptr && node->right == nullptr) {
                // no child
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                // one right child
                BSTNode *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                // one left child
                BSTNode *temp = node->left;
                delete node;
                return temp;
            } else {
                // two children: replace with inorder successor
                BSTNode *succ = findMin(node->right);
                node->key = succ->key;
                node->right = remove(node->right, succ->key);
            }
        }
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        clear(root);
    }

    // ==== public driver functions ====

    void insert(int key) {
        root = insert(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    // Task 2.1
    bool recSearch(int key) {
        return recSearch(root, key);
    }

    // Task 2.2
    int countNodes() {
        return countNodes(root);
    }

    // Task 2.3
    int getHeight() {
        return getHeight(root);
    }

    // Task 2.4
    void doubleTree() {
        doubleTree(root);
    }

    // Task 2.5
    void printAllPaths() {
        int path[100];          // max length = 100 as given
        printAllPaths(root, path, 0);
    }
};

// ============= Example usage / test =============
int main() {
    BST tree;

    tree.insert(50);
    tree.insert(40);
    tree.insert(25);
    tree.insert(75);
    tree.insert(65);
    tree.insert(80);

    cout << "recSearch(65): " << tree.recSearch(65) << endl;
    cout << "Node count: " << tree.countNodes() << endl;
    cout << "Height: " << tree.getHeight() << endl;

    cout << "All root-to-leaf paths:" << endl;
    tree.printAllPaths();

    cout << "\nDouble tree..." << endl;
    tree.doubleTree();
    cout << "All root-to-leaf paths after doubleTree:" << endl;
    tree.printAllPaths();

    return 0;
}