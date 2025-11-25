#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T info;
    Node<T> *left;
    Node<T> *right;

    Node(T v)
    {
        info = v;
        left = 0;
        right = 0;
    }

    Node()
    {
        left = 0;
        right = 0;
    }
};

#endif