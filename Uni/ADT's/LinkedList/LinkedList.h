#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

    void recursiveDisplayLinkedListInStraightOrder(Node<T> *start)
    {
        if (start != nullptr)
        {
            cout << start->info << " ";
            recursiveDisplayLinkedListInStraightOrder(start->next);
        }
    }

    void recursiveDisplayLinkedListInReverseOrder(Node<T> *start)
    {
        if (start != nullptr)
        {
            recursiveDisplayLinkedListInReverseOrder(start->next);
            cout << start->info << " ";
        }
    }

    int rCount(Node<T> *start)
    {
        if (start == nullptr)
            return 0;
        return rCount(start->next) + 1;
    }

    int rSum(Node<T> *start)
    {
        if (start == nullptr)
            return 0;
        else
            return rSum(start->next) + start->info;
    }

public:
    LinkedList()
    {
        this->head = 0;
    }

    void insertAtHead(T v)
    {
        Node<T> *temp = new Node(v);
        temp->next = this->head;
        head = temp;
    }

    void insertAtTail(T v)
    {
        Node<T> *t = new Node(v);
        if (!this->head)
        {
            head = t;
            return;
        }
        Node<T> *traverse = head;
        while (traverse->next != nullptr)
        {
            traverse = traverse->next;
        }
        traverse->next = t;
    }

    void insertAfter(int k, int v)
    {
        Node<T> *traverse = head;
        while (traverse != 0)
        {
            if (traverse->info == k)
            {
                Node<T> *t = new Node(v);
                t->next = traverse->next;
                traverse->next = t;
                return;
            }
            traverse = traverse->next;
        }
    }

    void insertBefore(int k, int v)
    {
        Node<T> *traverse = head;
        Node<T> *previous = nullptr;
        while (traverse != 0)
        {
            if (traverse->info == k)
            {
                Node<T> *t = new Node(v);
                t->next = traverse;
                previous->next = t;
            }
            previous = traverse;
            traverse = traverse->next;
        }
    }

    void removeAtHead()
    {
        if (this->head != 0)
        {
            head = head->next;
        }
    }

    void removeAtTail()
    {
        Node<T> *traverse = head;
        while (traverse != nullptr)
        {
            if (traverse->next->next == nullptr)
            {
                traverse->next = nullptr;
            }
            traverse = traverse->next;
        }
    }

    void removeAfter(int key)
    {
        Node<T> *traverse = head;
        while (traverse != 0)
        {
            if (traverse->info == key)
            {
                traverse->next = traverse->next->next;
                return;
            }
            traverse = traverse->next;
        }
    }

    void removeBefore(int key)
    {
    }

    void displayLinkedList()
    {
        Node<T> *temp;
        temp = head;
        while (temp != 0)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
    }

    void recursiveDisplayLinkedListInStraightOrder()
    {
        this->recursiveDisplayLinkedListInStraightOrder(head);
    }

    void recursiveDisplayLinkedListInReverseOrder()
    {
        this->recursiveDisplayLinkedListInReverseOrder(head);
    }

    int count()
    {
        int c = 0;
        Node<T> *temp;
        temp = head;
        while (temp != 0)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }

    // Recursive Count Function
    int rCount()
    {
        return rCount(this->head);
    }

    int sum()
    {
        Node<T> *temp = head;
        int s = 0;
        while (temp != 0)
        {
            s += temp->info;
            temp = temp->next;
        }
        return s;
    }

    // Recursive Sum Function
    int rSum()
    {
        return rSum(head);
    }
};

#endif