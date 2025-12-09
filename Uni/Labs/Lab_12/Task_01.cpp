#include <iostream>
#include <vector>
#include <cmath>
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

    BSTNode *constructHelper(vector<int> &in_order, vector<int> &pre_order,
                             int inStart, int inEnd, int &preIdx)
    {
        if (inStart > inEnd)
            return nullptr;

        BSTNode *node = new BSTNode(pre_order[preIdx++]);

        int inIdx = -1;
        for (int i = inStart; i <= inEnd; i++)
        {
            if (in_order[i] == node->data)
            {
                inIdx = i;
                break;
            }
        }

        node->left = constructHelper(in_order, pre_order, inStart, inIdx - 1, preIdx);
        node->right = constructHelper(in_order, pre_order, inIdx + 1, inEnd, preIdx);

        return node;
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

    void destroyHelper(BSTNode *node)
    {
        if (node == nullptr)
            return;
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }

    void rightRotate(BSTNode *pr, BSTNode *ch)
    {
        if (pr->left == ch)
        {
            pr->left = ch->right;
            ch->right = pr;
        }
    }
    void leftRotate(BSTNode *pr, BSTNode *ch)
    {
        // if()
        if (pr->right == ch)
        {
            pr->right = ch->left;
            ch->left = pr;
        }
    }

    void createBackbone(BSTNode *root)
    {
        BSTNode *tmp = root;
        while (tmp != nullptr)
        {
            if (tmp->left != nullptr)
            {
                BSTNode *ch = tmp->left;
                tmp->left = ch->right;
                ch->right = tmp;
                tmp = ch;
                // rightRotate(tmp, lch);
                // tmp = lch;
            }
            else
            {
                tmp = tmp->right;
            }
        }
    }

    void createPerfectTree(BSTNode *&r)
    {
        int n = countNodes();
        cout << n;
        int m = pow(2, floor(log2(n + 1))) - 1;
        int rotations = n - m;
        // cout << rotations;

        BSTNode *tmp = r;
        for (int i = 0; i < rotations; i++)
        {
            if (tmp->right != nullptr)
            {
                // BSTNode *child = tmp->right;
                BSTNode *ch = tmp->right;
                tmp->right = ch->left;
                ch->left = tmp;
                tmp = ch;
                // leftRotate(tmp, child);
                // cout << rotations;
                // tmp = child->left;
            }
        }

        while (m > 1)
        {
            m = m / 2;
            tmp = r;
            for (int i = 0; i < rotations; i++)
            {
                // BSTNode *child = tmp->right;
                // leftRotate(tmp, child);
                if (tmp->right != nullptr)
                {
                    BSTNode *ch = tmp->right;
                    tmp->right = ch->left;
                    ch->left = tmp;
                    tmp = ch;
                    // tmp = child->left;
                }
            }
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
    void construct_from_traversals(vector<int> in_order, vector<int> pre_order);
    void createBalancedTree(int *arr, int start, int end);
    void convertToBackbone();
    void createPerfectBST();
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

// void BST::construct_from_traversals(vector<int> in_order, vector<int> pre_order)
// {
//     BSTNode *rootNode = new BSTNode(pre_order[0]);
//     for (int i = 0; i < in_order.size(); i++)
//     {
//         if (in_order[i] == pre_order[0])
//         {
//             BSTNode *curr = new BSTNode(in_order[i]);
//         }
//         // rootNode->left = construct_from_traversals();
//     }
// }

void BST::createBalancedTree(int *arr, int start, int end)
{
    if (start > end)
        return;

    int mid = (start + end) / 2;
    insert(arr[mid]);
    createBalancedTree(arr, start, mid - 1);
    createBalancedTree(arr, mid + 1, end);
}

void BST::convertToBackbone()
{
    createBackbone(root);
}

void BST::createPerfectBST()
{
    convertToBackbone();
    // int nodesCount = countNodes();
    createPerfectTree(root);
    // cout << nodesCount;
}

void BST::construct_from_traversals(vector<int> in_order, vector<int> pre_order)
{
    int preIdx = 0;
    root = constructHelper(in_order, pre_order, 0, in_order.size() - 1, preIdx);
}