#include <iostream>
// #include <algorithm>
using namespace std;
class BSTNode
{
public:
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST
{
private:
    BSTNode *root;
    void inOrderHelper(BSTNode *p);
    void preOrderHelper(BSTNode *p);
    void postOrderHelper(BSTNode *p);
    BSTNode *findMin(BSTNode *node);              // Helper function to find the minimum node in a subtree
    BSTNode *deleteNode(BSTNode *root, int node); // Helper function to delete a node
    int countNodes(BSTNode *b)
    {
        if (b == nullptr)
            return 0;
        return 1 + countNodes(b->left) + countNodes(b->right);
    }
    bool recSearch(BSTNode *b, int key)
    {
        if (b == nullptr)
            return false;
        if (b->data == key)
            return true;

        if (key < b->data)
            return recSearch(b->left, key);
        else
            return recSearch(b->right, key);
    }
    int getHeight(BSTNode *b)
    {
        if (b == nullptr)
            return -1;
        int leftH = getHeight(b->left);
        int rightH = getHeight(b->right);
        return 1 + max(leftH, rightH);
    }

    void doubleTreeHelper(BSTNode *p)
    {
        if (p != nullptr)
        {
            doubleTreeHelper(p->left);
            std::cout << p->data << " ";
            // std::cout << p->data << " ";
            // this->insert(p->data);
            doubleTreeHelper(p->right);
            BSTNode *newNode = new BSTNode(p->data);
            newNode = p->left;
            p->left = newNode;
        }
    }

public:
    BST() : root(nullptr) {}
    void insert(int node);
    bool search(int node);
    void inOrder();
    void preOrder();
    void postOrder();
    void deleteMethod(int p);
    bool recSearch(int key)
    {
        return recSearch(root, key);
    }
    int countNodes()
    {
        return countNodes(root);
    }
    int getHeight()
    {
        return getHeight(root);
    }
    void doubleTree()
    {
        doubleTreeHelper(root);
        std::cout << std::endl;
    }
    void printAllPaths() {}
};
void BST::insert(int node)
{
    BSTNode *newNode = new BSTNode(node);

    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        BSTNode *current = root;
        BSTNode *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (node < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (node < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
}

// Helper function to find the minimum node in a subtree
BSTNode *BST::findMin(BSTNode *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

// Helper function to delete a node
BSTNode *BST::deleteNode(BSTNode *root, int node)
{
    if (root == nullptr)
    {
        return root;
    }

    if (node < root->data)
    {
        root->left = deleteNode(root->left, node);
    }
    else if (node > root->data)
    {
        root->right = deleteNode(root->right, node);
    }
    else
    {
        // BSTNode with only one child or no child
        if (root->left == nullptr)
        {
            BSTNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            BSTNode *temp = root->left;
            delete root;
            return temp;
        }

        // BSTNode with two children: Get the inorder successor (smallest in the right subtree)
        BSTNode *temp = findMin(root->right);
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Public function
void BST::deleteMethod(int node)
{
    root = deleteNode(root, node);
}
bool BST::search(int node)
{
    BSTNode *current = root;
    while (current != nullptr)
    {
        if (current->data == node)
        {
            return true;
        }
        else if (node < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}
void BST::inOrderHelper(BSTNode *p)
{
    if (p != nullptr)
    {
        inOrderHelper(p->left);
        std::cout << p->data << " ";
        inOrderHelper(p->right);
    }
}

// Public function
void BST::inOrder()
{
    inOrderHelper(root);
    std::cout << std::endl;
}
void BST::preOrderHelper(BSTNode *p)
{
    if (p != nullptr)
    {
        std::cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }
}

// Public function
void BST::preOrder()
{
    preOrderHelper(root);
    std::cout << std::endl;
}
void BST::postOrderHelper(BSTNode *p)
{
    if (p != nullptr)
    {
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        std::cout << p->data << " ";
    }
}

// Public function
void BST::postOrder()
{
    postOrderHelper(root);
    std::cout << std::endl;
}