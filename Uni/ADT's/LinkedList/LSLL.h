#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LSLL
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

    T rSearch(Node<T> *traverse, T key)
    {
        if (traverse == 0)
        {
            return -1;
        }
        if (traverse->info == key)
            return traverse->info;
        return rSearch(traverse->next, key);
    }

public:
    // Constructor
    LSLL()
    {
        this->head = 0;
    }

    void create(T arr[], int n)
    {
        if (n <= 0)
            return;

        head = new Node<T>(arr[0]); // Creating first node
        head->next = nullptr;

        Node<T> *traverse = head;

        for (int i = 1; i < n; i++)
        {
            Node<T> *temp = new Node<T>(arr[i]);
            temp->next = nullptr;
            traverse->next = temp;
            traverse = temp;
        }
    }

    // Insertion functions
    void insert(int index, T key)
    {
        // checking index is in range
        if (index < 0 || index > this->countNodes())
        {
            return;
        }

        Node<T> *temp = new Node(key);
        // if inserting at first position
        if (index == 0)
        {
            temp->next = head;
            this->head = temp;
        }
        else
        {
            Node<T> *traverse = head;
            for (int i = 0; i < index - 1; i++)
            {
                traverse = traverse->next;
            }
            temp->next = traverse->next;
            traverse->next = temp;
        }
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
        // if there is no node
        if (this->head == nullptr)
            return;
        // if head node matches key
        if (this->head->info == k)
        {
            // Node<T> *previous = nullptr;
            Node<T> *t = new Node(v);
            t->next = head;
            head = t;
            return;
        }
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

    // Deletion functions
    void removeAtHead()
    {
        if (this->head != 0)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeAtTail()
    {
        // if there is no node;
        if (this->head == 0)
        {
            return;
        }
        // if there is only one node, one head node
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        // if there are more than one nodes, then we check from second node
        Node<T> *traverse = head;
        while (traverse->next->next != nullptr)
        {
            traverse = traverse->next;
        }
        Node<T> *temp = traverse->next;
        traverse->next = nullptr;
        delete temp;
    }

    void removeAfter(int key)
    {
        Node<T> *traverse = head;
        while (traverse != nullptr)
        {
            if (traverse->info == key)
            {
                Node<T> *temp = traverse->next;
                traverse->next = traverse->next->next;
                delete temp;
                return;
            }
            traverse = traverse->next;
        }
    }

    void removeBefore(int key)
    {
        // no nodes in list
        if (head == nullptr)
            return;
        // if there is only one node. So no node to remove before single node(head node)
        if (head->next == nullptr)
            return;
        // if first node's info matches the key, then we can't remove the node before head node. So simply return ==> no removal:(
        if (head->info == key)
            return;
        // second node maatches the key, removing first node(head node)
        if (head->next->info == key)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // general case: Finding the node matching the key and removing the node before it
        Node<T> *traverse = head;
        while (traverse->next->next != nullptr)
        {
            if (traverse->next->next->info == key)
            {
                Node<T> *temp = traverse->next;
                traverse->next = traverse->next->next;
                delete temp;
                return;
            }
            traverse = traverse->next;
        }
    }

    void remove(T val)
    {
        // no nodes ==> empty
        if (head == nullptr)
            return;
        // if first node's info matches
        if (head->info == val)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // general case: Finding a node that matches a key and then removing it
        Node<T> *traverse = head;
        while (traverse->next != nullptr)
        {
            if (traverse->next->info == val)
            {
                Node<T> *temp = traverse->next;
                traverse->next = traverse->next->next;
                delete temp;
                return;
            }
            traverse = traverse->next;
        }
    }

    // Utility functions
    int search(T key)
    {
        Node<T> *traverse = this->head;
        while (traverse != 0)
        {
            if (traverse->info == key)
                return traverse->info;
            traverse = traverse->next;
        }
        return -1;
    }

    void update(T key, T val)
    {
        Node<T> *traverse = head;
        while (traverse != nullptr)
        {
            if (traverse->info == key)
            {
                traverse->info = val;
                return;
            }
            traverse = traverse->next;
        }
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

    T rSearch(T key)
    {
        return this->rSearch(head, key);
    }

    int countNodes()
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

    // Destructor
    ~LSLL()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = 0;
    }
};

#endif