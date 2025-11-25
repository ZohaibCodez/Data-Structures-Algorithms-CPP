#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include <queue>
#include <stack>
#include "Node.h"

using namespace std;

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;

    void preOrderHelper(Node<T> *curr)
    {
        if (curr == 0)
            return;
        cout << curr->info << " ";
        preOrderHelper(curr->left);
        preOrderHelper(curr->right);
    }

    void displayParenthesizedHelper(Node<T> *curr)
    {
        if (curr == 0)
            return;
        cout << curr->info;
        Node<T> *leftChild = curr->left;
        Node<T> *rightChild = curr->right;

        bool hasLeft = curr->left ? true : false;
        bool hasRight = curr->right ? true : false;

        if (hasLeft || hasRight)
        {
            cout << "(";
            if (hasLeft)
            {
                displayParenthesizedHelper(leftChild);
            }
            if (hasRight)
            {
                cout << ",";
                displayParenthesizedHelper(rightChild);
            }
            cout << ")";
        }
    }

    void postOrderHelper(Node<T> *curr)
    {
        if (curr == 0)
            return;
        postOrderHelper(curr->left);
        postOrderHelper(curr->right);
        cout << curr->info << " ";
    }
    void inOrderHelper(Node<T> *curr)
    {
        if (curr == 0)
            return;
        inOrderHelper(curr->left);
        cout << curr->info << " ";
        inOrderHelper(curr->right);
    }

    void displayDescendentsHelper(Node<T> *curr, T v)
    {
        if (curr == 0)
            return;
        if (curr->info != v)
            cout << curr->info << " ";
        preOrderHelper(curr->left);
        preOrderHelper(curr->right);
    }

    int sizeHelper(Node<T> *node)
    {
        if (!node)
            return 0;
        return 1 + sizeHelper(node->left) + sizeHelper(node->right);
    }

    int countLeavesHelper(Node<T> *node)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return 1;
        return countLeavesHelper(node->left) + countLeavesHelper(node->right);
    }

    int heightHelper(Node<T> *node)
    {
        if (!node)
            return 0;

        int lHeight = heightHelper(node->left);
        int rHeight = heightHelper(node->right);

        return 1 + max(lHeight, rHeight);
    }

    void deleteTree(Node<T> *node)
    {
        if (!node)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinaryTree()
    {
        root = 0;
    }
    void setRoot(T v)
    {
        root = new Node<T>(v);
    }
    T getRoot()
    {
        if (!root)
        {
            cout << "No root present" << endl;
            return;
        }
        return root->info;
    }
    Node<T> *search(Node<T> *curr, T p)
    {
        if (curr == 0)
        {
            return 0;
        }
        if (curr->info == p)
        {
            return curr;
        }
        Node<T> *t = search(curr->left, p);
        if (t == 0)
        {
            t = search(curr->right, p);
        }
        return t;
    }
    void setLeftChild(T p, T v)
    {
        Node<T> *n = search(root, p);
        {
            if (n != 0 && !n->left)
            {
                n->left = new Node<T>(v);
            }
        }
    }
    void setRightChild(T p, T v)
    {
        Node<T> *n = search(root, p);
        {
            if (n != 0 && !n->right)
            {
                n->right = new Node<T>(v);
            }
        }
    }

    void preOrder()
    {
        preOrderHelper(root);
    }
    void postOrder()
    {
        postOrderHelper(root);
    }
    void inOrder()
    {
        inOrderHelper(root);
    }

    void levelOrder()
    {
        if (!root)
            return;
        queue<Node<T> *> q;
        q.push(root);
        while (!q.empty())
        {
            Node<T> *curr = q.front();
            q.pop();
            cout << curr->info << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    void displayDescendents(T node)
    {
        Node<T> *requiredNode = findNode(root, node);
        displayDescendentsHelper(requiredNode, requiredNode->info);
    }

    void displayParenthesizedView()
    {
        if (!root)
        {
            cout << "Tree is empty";
        }
        else
        {
            displayParenthesizedHelper(root);
        }
        cout << endl;
    }

    void reverseLevelOrder()
    {
        if (!root)
            return;
        queue<Node<T> *> q;
        stack<Node<T> *> s;
        q.push(root);
        while (!q.empty())
        {
            Node<T> *curr = q.front();
            q.pop();
            s.push(curr);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        while (!s.empty())
        {
            cout << s.top->info << " ";
            s.pop();
        }
    }

    T getParent(T node)
    {
        return findParent(root, node)->info;
    }

    Node<T> *findParent(Node<T> *curr, T childvalue)
    {
        if (!curr)
            return nullptr;

        if ((curr->left && curr->left->info == childvalue) || (curr->right && curr->right->info == childvalue))
        {
            return curr;
        }
        Node<T> *leftSearch = findParent(curr->left, childvalue);
        if (leftSearch)
            return leftSearch;
        return findParent(curr->right, childvalue);
    }

    Node<T> *findNode(Node<T> *curr, T node)
    {
        if (!curr)
        {
            return nullptr;
        }
        if (curr->info == node)
        {
            return curr;
        }
        Node<T> *leftSearch = findNode(curr->left, node);
        if (leftSearch)
            return leftSearch;
        return findNode(curr->right, node);
    }

    bool isInternalNode(T node)
    {
        Node<T> *requiredNode = findNode(root, node);
        if (requiredNode->left || requiredNode->right)
        {
            return true;
        }
        return false;
    }

    bool isExternalNode(T node)
    {
        Node<T> *requiredNode = findNode(root, node);
        if (!requiredNode->left && !requiredNode->right)
        {
            return true;
        }
        return false;
    }

    T findNodeSiblings(T node)
    {
        // Node<T> *temp = root;
        Node<T> *requiredNode = findParent(root, node);
        if (requiredNode->left || requiredNode->right)
        {
            cout << requiredNode->info << endl;
            if (requiredNode->left->info == node)
            {
                return requiredNode->right->info;
            }
            else if (requiredNode->right->info == node)
            {
                return requiredNode->left->info;
            }
            else
            {
                cout << "No Siblings" << endl;
                return 0;
            }
        }
    }

    void removeSubTree(Node<T> *&node)
    {
        if (!node)
            return;

        removeSubTree(node->left);
        removeSubTree(node->right);

        delete node;
        node = nullptr;
    }

    void removeByValue(T value)
    {
        if (!root)
            return;

        if (root->info == value)
        {
            removeSubTree(root);
            return;
        }

        Node<T> *parent = findParent(root, value);
        if (!parent)
        {
            cout << "Parent not Found" << endl;
            return;
        }

        if (parent->left && parent->left->info == value)
        {
            removeSubTree(parent->left);
        }
        else if (parent->right && parent->right->info == value)
        {
            removeSubTree(parent->right);
        }
    }

    int size()
    {
        return size(root);
    }

    int countLeaves()
    {
        return countLeaves(root);
    }

    int countInternalNodes()
    {
        return size() - countLeaves();
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    int height()
    {
        return heightHelper(root);
    }

    ~BinaryTree()
    {
        deleteTree(root);
    }

    // void mirror(Node *node)
    // {
    //     if (!node)
    //         return;
    //     mirror(node->left);
    //     mirror(node->right);
    //     swap(node->left, node->right);
    // }

    // BinaryTree<T> operator=(BinaryTree<T> &)
    // {

    //     if (!root)
    //         return;
    //     queue<Node<T> *> q;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         Node<T> *curr = q.front();
    //         q.pop();
    //         cout << curr->info << " ";

    //         if (curr->left)
    //             q.push(curr->left);
    //         if (curr->right)
    //             q.push(curr->right);
    //     }
    // }

    BinaryTree(BinaryTree<T> &other)
    {
        root = nullptr;
        if (other.root)
        {
            root = copyTreeHelper(other.root);
        }
    }


    BinaryTree<T> &operator=(BinaryTree<T> &other)
    {
        if (this == &other)
            return *this;

        deleteTree(root);
        root = nullptr;

        if (other.root)
        {
            root = copyTreeHelper(other.root);
        }

        return *this;
    }

    Node<T> *copyTreeHelper(Node<T> *node)
    {
        if (!node)
            return nullptr;

        Node<T> *newNode = new Node<T>(node->info);
        newNode->left = copyTreeHelper(node->left);
        newNode->right = copyTreeHelper(node->right);

        return newNode;
    }

    BinaryTree<T> getMirrorImage()
    {
        BinaryTree<T> mirrorTree;
        mirrorTree.root = mirrorHelper(root);
        return mirrorTree;
    }

    Node<T> *mirrorHelper(Node<T> *node)
    {
        if (!node)
            return nullptr;

        Node<T> *newNode = new Node<T>(node->info);

        newNode->left = mirrorHelper(node->right);
        newNode->right = mirrorHelper(node->left);

        return newNode;
    }
};

#endif