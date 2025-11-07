#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
private:
    int height;
    T *data;
    bool *status;
    int size;

    int search(int curr, T p)
    {
        if (curr >= size)
            return -1;
        if (!status[curr])
            return -1;
        if (data[curr] == p)
            return curr;
        T t = search(2 * curr + 1, p);
        if (t == -1)
        {
            t = search(2 * curr + 2, p);
        }
        return t;
    }

    int getIndex(T v)
    {
        for (int i = 0; i < size; i++)
        {
            if (status[i] == true && data[i] == v)
            {
                return i;
            }
        }
        return -1;
    }

    void removeHelper(int i)
    {
        if (i >= size)
            return;
        if (!status[i])
            return;

        status[i] = false;
        data[i] = 0;
        removeHelper(2 * i + 1);
        removeHelper(2 * i + 2);
    }

    void displayDescendentsHelper(int i)
    {
        if (i >= size || status[i] == false)
            return;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && status[left] == true)
        {
            cout << data[left] << " ";
            displayDescendentsHelper(left);
        }

        if (right < size && status[right] == true)
        {
            cout << data[right] << " ";
            displayDescendentsHelper(right);
        }
    }

    void preOrderHelper(int i)
    {
        if (data[i] == 0)
            return;
        if (i >= size || !status[i])
            return;
        cout << data[i] << " ";
        preOrderHelper(2 * i + 1);
        preOrderHelper(2 * i + 2);
    }
    void postOrderHelper(int i)
    {
        if (data[i] == 0)
            return;
        if (i >= size || !status[i])
            return;
        postOrderHelper(2 * i + 1);
        postOrderHelper(2 * i + 2);
        cout << data[i] << " ";
    }
    void inOrderHelper(int i)
    {
        if (data[i] == 0)
            return;
        if (i >= size || !status[i])
            return;
        inOrderHelper(2 * i + 1);
        cout << data[i] << " ";
        inOrderHelper(2 * i + 2);
    }

    void displayParenthesizedHelper(int i)
    {
        if (i >= size || !status[i])
            return;
        cout << data[i];
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        bool hasLeft = (leftChild < size && status[leftChild]);
        bool hasRight = (rightChild < size && status[rightChild]);

        if (hasLeft || hasRight)
        {
            cout << "(";
            if (hasLeft)
            {
                displayParenthesizedHelper(leftChild);
            }
            cout << ",";
            if (hasRight)
            {
                displayParenthesizedHelper(rightChild);
            }
            cout << ")";
        }
    }

public:
    BinaryTree(int h)
    {
        height = h;
        size = static_cast<int>(pow(2, height)) - 1;
        status = new bool[size];
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            status[i] = false;
        }
    }

    ~BinaryTree()
    {
        delete[] status;
        delete[] data;
    }
    void setRoot(T v)
    {
        data[0] = v;
        status[0] = true;
    }

    T getRoot()
    {
        if (status[0] == true)
        {
            return data[0];
        }
        cout << "No root present";
    }

    void setLeftChild(T p, T v)
    {
        for (int i = 0; i < size; i++)
        {
            if (status[i] == true && data[i] == p)
            {
                if ((2 * i + 1) < size)
                {
                    data[2 * i + 1] = v;
                    status[2 * i + 1] = true;
                    return;
                }
            }
        }
    }
    void setRightChild(T p, T v)
    {
        for (int i = 0; i < size; i++)
        {
            if (status[i] == true && data[i] == p)
            {
                if ((2 * i + 2) < size)
                {
                    data[2 * i + 2] = v;
                    status[2 * i + 2] = true;
                    return;
                }
            }
        }
    }

    T getParent(T node)
    {
        int i = getIndex(node);
        if (i == -1)
        {
            cout << "Node not Found";
        }
        if (i == 0)
        {
            cout << "Root Node has no parent Node";
        }

        int parentIndex = (i - 1) / 2;
        return data[parentIndex];
    }

    T search(T p)
    {
        return search(0, p);
    }

    void remove(T val)
    {
        int i = search(0, val);
        if (i != -1 && status[i])
        {
            removeHelper(i);
        }
    }

    void displayAncestors(T node)
    {
        int i = getIndex(node);
        if (i == -1)
        {
            cout << "node not found";
        }
        if (i == 0)
        {
            cout << "Root Node has no ancestors" << endl;
        }
        while (i > 0)
        {
            i = (i - 1) / 2;
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void displayDescendents(T node)
    {
        int i = getIndex(node);
        if (i == -1)
        {
            cout << "node not found:(";
        }
        if (i == size)
        {
            cout << "last node, Has no descendants";
        }
        displayDescendentsHelper(i);
        cout << endl;
    }

    void heightOfTree()
    {
        int maxHeight = -1;

        for (int i = 0; i < size; i++)
        {
            if (status[i] == true)
            {
                int level = floor(log2(i + 1));
                if (level > maxHeight)
                {
                    maxHeight = level;
                }
            }
        }

        cout << (maxHeight == -1 ? 0 : maxHeight + 1);
    }

    void levelOrder()
    {
        cout << "Level-order: ";
        for (int i = 0; i < size; i++)
        {
            if (status[i] == true)
            {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }

    void displayLevel(int levelNo)
    {
        if (levelNo < 0)
        {
            cout << "Invalid level!" << endl;
            return;
        }

        int startIndex = pow(2, levelNo) - 1;
        int endIndex = pow(2, levelNo + 1) - 2;

        cout << "Level " << levelNo << ": ";
        bool found = false;
        for (int i = startIndex; i <= endIndex && i < size; i++)
        {
            if (status[i] == 1)
            {
                cout << data[i] << " ";
                found = true;
            }
        }

        if (!found)
        {
            cout << "No nodes at this level";
        }
        cout << endl;
    }

    int findLevelOfNode(T node)
    {
        int index = getIndex(node);
        if (index == -1)
        {
            return -1;
        }

        int level = floor(log2(index + 1));
        return level;
    }

    void preOrder()
    {
        preOrderHelper(0);
    }
    void postOrder()
    {
        postOrderHelper(0);
    }
    void inOrder()
    {
        inOrderHelper(0);
    }
    void displayParenthesizedView()
    {
        if (status[0] == false)
        {
            cout << "Tree is empty";
        }
        else
        {
            displayParenthesizedHelper(0);
        }
        cout << endl;
    }
};

#endif