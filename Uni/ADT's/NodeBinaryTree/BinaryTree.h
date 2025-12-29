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
        cout << curr->info;
        preOrderHelper(curr->left);
        preOrderHelper(curr->right);
    }
    void postOrderHelper(Node<T> *curr)
    {
        if (curr == 0)
            return;
        postOrderHelper(curr->left);
        postOrderHelper(curr->right);
        cout << curr->info;
    }
    void inOrderHelper(Node<T> *curr)
    {
        if (curr == 0)
            return;
        inOrderHelper(curr->left);
        cout << curr->info;
        inOrderHelper(curr->right);
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

public:
    BinaryTree()
    {
        root = 0;
    }
    void setRoot(T v)
    {
        root = new Node<T>(v);
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
        return sizeHelper(root);
    }

    int countLeaves()
    {
        return countLeavesHelper(root);
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
        return height(root);
    }
};

#endif