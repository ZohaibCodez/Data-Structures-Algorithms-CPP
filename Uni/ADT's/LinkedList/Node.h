#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T info;
    Node<T> *next;

    Node(T d)
    {
        info = d;
        next = 0;
    }

    Node(T d, Node<T> *p)
    {
        this->info = d;
        this->next = p;
    }

    Node()
    {
        next = 0;
    }
};

#endif