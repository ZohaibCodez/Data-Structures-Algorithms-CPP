#include <iostream>
#include <string>
using namespace std;

class StudentNode
{
public:
    int rollNo;        // Student’s roll number (must be unique)
    string name;       // Student’s name
    double cgpa;       // Student’s CGPA
    StudentNode *left; // Pointer to the left subtree of a node
    StudentNode *right;
    // Node(T value) : data(value), left(nullptr), right(nullptr) {}
    StudentNode(int _rollNo, string _name, double _cgpa) : rollNo(_rollNo), name(_name), cgpa(_cgpa), left(nullptr), right(nullptr) {}
};
class StudentBST
{
private:
    // Pointer to the right subtree of a node
    StudentNode *root;

    void InOrder(StudentNode *s)
    {
        if (s != nullptr)
        {
            InOrder(s->left);
            cout << "Roll No: " << s->rollNo << endl;
            cout << "Name: " << s->name << endl;
            cout << "CGPA: " << s->cgpa << endl;
            InOrder(s->right);
        }
    }

    void displayInRangeHelper(double cgpaStart, double cgpaEnd, StudentNode *s)
    {
        if (s != nullptr)
        {
            displayInRangeHelper(cgpaStart, cgpaEnd, s->left);
            if (s->cgpa >= cgpaStart && s->cgpa <= cgpaEnd)
            {
                cout << "Roll No: " << s->rollNo << endl;
                cout << "Name: " << s->name << endl;
                cout << "CGPA: " << s->cgpa << endl;
            }
            displayInRangeHelper(cgpaStart, cgpaEnd, s->right);
        }
    }

    void destroy(StudentNode *s)
    {
        if (s == nullptr)
        {
            return;
        }
        destroy(s->left);
        destroy(s->right);
        delete s;
    }

    //     template<class T>
    // Node<T>* BST<T>::findMin(Node<T>* node) {
    //     while (node->left != nullptr) {
    //         node = node->left;
    //     }
    //     return node;
    // }

    StudentNode *findMin(StudentNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // // Helper function to delete a node
    // template <class T>
    // Node<T> *BST<T>::deleteNode(Node<T> *root, T node)
    // {
    //     if (root == nullptr)
    //     {
    //         return root;
    //     }

    //     if (node < root->data)
    //     {
    //         root->left = deleteNode(root->left, node);
    //     }
    //     else if (node > root->data)
    //     {
    //         root->right = deleteNode(root->right, node);
    //     }
    //     else
    //     {
    //         // Node with only one child or no child
    //         if (root->left == nullptr)
    //         {
    //             Node<T> *temp = root->right;
    //             delete root;
    //             return temp;
    //         }
    //         else if (root->right == nullptr)
    //         {
    //             Node<T> *temp = root->left;
    //             delete root;
    //             return temp;
    //         }

    //         // Node with two children: Get the inorder successor (smallest in the right subtree)
    //         Node<T> *temp = findMin(root->right);
    //         root->data = temp->data;

    //         // Delete the inorder successor
    //         root->right = deleteNode(root->right, temp->data);
    //     }
    //     return root;
    // }

    StudentNode *removeNode(StudentNode *root, int rn)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (rn < root->rollNo)
        {
            root->left = removeNode(root->left, rn);
        }
        else if (rn > root->rollNo)
        {
            root->right = removeNode(root->right, rn);
        }
        else
        {
            // Node with only one child or no child
            if (root->left == nullptr)
            {
                StudentNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                StudentNode *temp = root->left;
                delete root;
                return temp;
            }

            StudentNode *temp = findMin(root->right);
            root->rollNo = temp->rollNo;
            root->name = temp->name;
            root->cgpa = temp->cgpa;

            // Delete the inorder successor
            root->right = removeNode(root->right, temp->rollNo);
        }
        return root;
    }

public:
    // Pointer to the root node of the tree
    StudentBST() : root(nullptr) {}

    bool insert(int _rollNo, string _name, double _cgpa)
    {
        if (search(_rollNo))
        {
            return false;
        }
        StudentNode *newNode = new StudentNode(_rollNo, _name, _cgpa);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            StudentNode *current = root;
            StudentNode *parent = nullptr;

            while (current != nullptr)
            {
                parent = current;
                if (_rollNo < current->rollNo)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            if (_rollNo < parent->rollNo)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            }
        }
        return true;
    }

    bool search(int _rollNumber)
    {
        StudentNode *current = root;
        while (current != nullptr)
        {
            if (current->rollNo == _rollNumber)
            {
                cout << "Roll No: " << current->rollNo << endl;
                cout << "Name: " << current->name << endl;
                cout << "CGPA: " << current->cgpa << endl;
                return true;
            }
            else if (_rollNumber < current->rollNo)
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

    StudentNode *searchNode(int _rollNumber)
    {
        StudentNode *current = root;
        while (current != nullptr)
        {
            if (current->rollNo == _rollNumber)
            {
                cout << "Roll No: " << current->rollNo << endl;
                cout << "Name: " << current->name << endl;
                cout << "CGPA: " << current->cgpa << endl;
                return current;
            }
            else if (_rollNumber < current->rollNo)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return nullptr;
    }

    void InOrder()
    {
        InOrder(root);
        std::cout << std::endl;
    }

    bool remove(int rn)
    {
        bool isPresent = search(rn);
        if (isPresent)
        {
            root = removeNode(root, rn);
            return true;
        }
        else
        {
            cout << "Student with roll no:" << rn << " not found:(" << endl;
            return false;
        }
    }

    void displayInRange(double cgpaStart, double cgpaEnd)
    {
        displayInRangeHelper(cgpaStart, cgpaEnd, root);
        std::cout << std::endl;
    }

    ~StudentBST()
    {
        root = nullptr;
        destroy(root);
    }
};