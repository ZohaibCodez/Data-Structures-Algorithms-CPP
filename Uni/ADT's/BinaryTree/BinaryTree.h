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

public:
    BinaryTree(int h)
    {
        height = h;
        size = static_cast<int>(pow(2, height)) - 1;
        status = new bool[size];
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
            status[i] = false;
        }
    }
    void setRoot(T v)
    {
        data[0] = v;
        status[0] = true;
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
};

#endif