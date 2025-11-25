#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class BinaryTree
{
private:
    int height;
    T *data;
    bool *status;
    int size;

    int searchHelper(int curr, T p)
    {
        if (!status[curr])
            return -1;
        if (data[curr] == p)
            return curr;
        int temp = searchHelper(2 * curr + 1, p);
        if (temp == -1)
        {
            temp = searchHelper(2 * curr + 2, p);
        }
        return temp;
    }

    void removeHelper(int index)
    {
        if (!status[index])
        {
            return;
        }
        int rightIndex = 2 * index + 2;
        int leftIndex = 2 * index + 1;
        if (status[leftIndex] && leftIndex < size)
        {
            removeHelper(leftIndex);
            status[leftIndex] = false;
        }
        if (status[rightIndex] && rightIndex < size)
        {
            removeHelper(rightIndex);
            status[rightIndex] = false;
        }
    }

    void preOrderHelper(int curr = 0)
    {
        if (curr > size || !status[curr])
        {
            return;
        }
        int rightIndex = 2 * index + 2;
        int leftIndex = 2 * index + 1;
        cout << data[curr];
        if (status[leftIndex] && leftIndex < size)
        {
            preOrderHelper(leftIndex);
        }
        if (status[rightIndex] && rightIndex < size)
        {
            preOrderHelper(rightIndex);
        }
    }

public:
    BinaryTree(int h)
    {
        height = h;
        size = int(pow(2, height)) - 1;
        status = new bool[size];
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
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
            if (status[i] && data[i] == p)
            {
                data[i * 2 + 1] = v;
                status[i * 2 + 1] = true;
                return;
            }
        }
    }

    void setRightChild(T p, T v)
    {
        for (int i = 0; i < size; i++)
        {
            if (status[i] && data[i] == p)
            {
                data[i * 2 + 2] = v;
                status[i * 2 + 2] = true;
                return;
            }
        }
    }

    void remove(T val)
    {
        int index = search(val);
        if (index == -1)
        {
            return;
        }
        removeHelper(index);
        status[index] = false;
    }

    int search(T p)
    {
        return searchHelper(0, p);
    }

    void preOrder()
    {
        preOrderHelper(0);
    }
};

#endif