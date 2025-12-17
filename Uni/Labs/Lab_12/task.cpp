#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode *root;
    
    void inOrderHelper(BSTNode *p);
    void preOrderHelper(BSTNode *p);
    void postOrderHelper(BSTNode *p);
    BSTNode *findMin(BSTNode *node);
    BSTNode *deleteNode(BSTNode *root, int node);
    
    int countNodes(BSTNode *b) {
        if (b == nullptr) return 0;
        return 1 + countNodes(b->left) + countNodes(b->right);
    }
    
    bool recSearch(BSTNode *b, int key) {
        if (b == nullptr) return false;
        if (b->data == key) return true;
        if (key < b->data) return recSearch(b->left, key);
        else return recSearch(b->right, key);
    }
    
    int getHeight(BSTNode *b) {
        if (b == nullptr) return -1;
        int leftH = getHeight(b->left);
        int rightH = getHeight(b->right);
        return 1 + max(leftH, rightH);
    }
    
    BSTNode *constructHelper(vector<int> &in_order, vector<int> &pre_order, 
                             int inStart, int inEnd, int &preIdx) {
        if (inStart > inEnd) return nullptr;
        
        BSTNode *node = new BSTNode(pre_order[preIdx++]);
        
        int inIdx = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (in_order[i] == node->data) {
                inIdx = i;
                break;
            }
        }
        
        node->left = constructHelper(in_order, pre_order, inStart, inIdx - 1, preIdx);
        node->right = constructHelper(in_order, pre_order, inIdx + 1, inEnd, preIdx);
        
        return node;
    }
    
    void createBalancedHelper(int *arr, int start, int end) {
        if (start > end) return;
        
        int mid = (start + end) / 2;
        insert(arr[mid]);
        createBalancedHelper(arr, start, mid - 1);
        createBalancedHelper(arr, mid + 1, end);
    }
    
    void destroyHelper(BSTNode *node) {
        if (node == nullptr) return;
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
    
    void rightRotate(BSTNode *parent, BSTNode *child) {
        if (parent->left == child) {
            parent->left = child->right;
            child->right = parent;
        }
    }

    void leftRotate(BSTNode *parent, BSTNode *child) {
        if (parent->right == child) {
            parent->right = child->left;
            child->left = parent;
        }
    }

    void createBackboneHelper(BSTNode *root) {
        BSTNode *tmp = root;
        while (tmp != nullptr) {
            if (tmp->left != nullptr) {
                BSTNode *child = tmp->left;
                rightRotate(tmp, child);
                tmp = child;
            } else {
                tmp = tmp->right;
            }
        }
    }
    
    void createPerfectHelper(BSTNode *root, int n) {
        int m = (int)pow(2, floor(log2(n + 1))) - 1;
        int rotations = n - m;
        
        BSTNode *tmp = root;
        for (int i = 0; i < rotations; i++) {
            BSTNode *child = tmp->right;
            leftRotate(tmp, child);
            tmp = child->left;
        }
        
        while (m > 1) {
            m = m / 2;
            tmp = root;
            for (int i = 0; i < m; i++) {
                BSTNode *child = tmp->right;
                leftRotate(tmp, child);
                tmp = child->left;
            }
        }
    }

public:
    BST() : root(nullptr) {}
    
    void insert(int node);
    bool search(int node);
    void display_in_order();
    void display_pre_order();
    void display_post_order();
    void deleteMethod(int p);
    
    bool recSearch(int key) {
        return recSearch(root, key);
    }
    
    int countNodes() {
        return countNodes(root);
    }
    
    int getHeight() {
        return getHeight(root);
    }
    
    void construct_from_traversals(vector<int> in_order, vector<int> pre_order) {
        int preIdx = 0;
        root = constructHelper(in_order, pre_order, 0, in_order.size() - 1, preIdx);
    }
    
    void createBalancedTree(int *arr, int start, int end) {
        destroyHelper(root);
        root = nullptr;
        createBalancedHelper(arr, start, end);
    }
    
    void convertToBackbone() {
        createBackboneHelper(root);
    }
    
    void createPerfectBST() {
        convertToBackbone();
        int n = countNodes();
        createPerfectHelper(root, n);
    }
};

void BST::insert(int node) {
    BSTNode *newNode = new BSTNode(node);
    
    if (root == nullptr) {
        root = newNode;
    } else {
        BSTNode *current = root;
        BSTNode *parent = nullptr;
        
        while (current != nullptr) {
            parent = current;
            if (node < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (node < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

BSTNode *BST::findMin(BSTNode *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BSTNode *BST::deleteNode(BSTNode *root, int node) {
    if (root == nullptr) return root;
    
    if (node < root->data) {
        root->left = deleteNode(root->left, node);
    } else if (node > root->data) {
        root->right = deleteNode(root->right, node);
    } else {
        if (root->left == nullptr) {
            BSTNode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BSTNode *temp = root->left;
            delete root;
            return temp;
        }
        
        BSTNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void BST::deleteMethod(int node) {
    root = deleteNode(root, node);
}

bool BST::search(int node) {
    BSTNode *current = root;
    while (current != nullptr) {
        if (current->data == node) return true;
        else if (node < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

void BST::inOrderHelper(BSTNode *p) {
    if (p != nullptr) {
        inOrderHelper(p->left);
        cout << p->data << " ";
        inOrderHelper(p->right);
    }
}

void BST::display_in_order() {
    inOrderHelper(root);
    cout << endl;
}

void BST::preOrderHelper(BSTNode *p) {
    if (p != nullptr) {
        cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }
}

void BST::display_pre_order() {
    preOrderHelper(root);
    cout << endl;
}

void BST::postOrderHelper(BSTNode *p) {
    if (p != nullptr) {
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << p->data << " ";
    }
}

void BST::display_post_order() {
    postOrderHelper(root);
    cout << endl;
}