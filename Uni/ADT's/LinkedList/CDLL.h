#ifndef CIRCULAR_DOUBLY_LINKEDLIST
#define CIRCULAR_DOUBLY_LINKEDLIST

#include <iostream>
using namespace std;

template <typename T>
class DNode
{
public:
    T data;
    DNode *next;
    DNode *prev;

    DNode(T val)
    {
        data = val;
        next = prev = nullptr;
    }
};

template <typename T>
class CDLinkedList
{
private:
    DNode<T> *head;

public:
    CDLinkedList()
    {
        head = nullptr;
    }

    ~CDLinkedList()
    {
        if (!head)
            return;
        DNode<T> *traverse = head->next;
        while (traverse != head)
        {
            DNode<T> *temp = traverse;
            traverse = traverse->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    void displayList()
    {
        if (!head)
            cout << "List is empty:(";
        return;
        DNode<T> *traverse = head;
        do
        {
            cout << traverse->data;
            if (traverse->next != head)
                cout << " <-> ";
            traverse = traverse->next;
        } while (traverse != head);
    }

    // Insertion functions
    void insertAtHead(T val)
    {
        DNode<T> *temp = new DNode<T>(val);
        if (!head)
        {
            temp->next = temp->prev = temp;
            head = temp;
            return;
        }
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
    }
    void insertAtTail(T val)
    {
        DNode<T> *temp = new DNode(val);
        if (!head)
        {
            temp->next = temp->prev = temp;
            head = temp;
            return;
        }
        temp->prev = head->prev;
        temp->next = head;
        head->prev->next = temp;
        head->prev = temp;
    }

    // Deletion Functions
    void removeAtHead()
    {
        if (head->next == head)
        {
            DNode<T> *temp = head;
            head = nullptr;
            delete temp;
            return;
        }
        DNode<T> *temp = head;
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        delete temp;
    }
    void removeAtTail()
    {
        if (head->next == head)
        {
            DNode<T> *temp = head;
            head = nullptr;
            delete temp;
            return;
        }
        DNode<T> *tail = head->prev;
        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;
        delete tail;
    }
    void remove(T val)
    {
        if (!head)
            return;
        if (head->next == head && head->data == val)
        {
            DNode<T> *temp = head;
            head = nullptr;
            delete temp;
            return;
        }
        if (head->data == val)
        {
            DNode<T> *temp = head;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            head = temp->next;
            delete temp;
            return;
        }
        DNode<T> *traverse = head;
        do
        {
            if (traverse->data == val)
            {
                DNode<T> *temp = traverse;
                traverse->prev->next = traverse->next;
                traverse->next->prev = traverse->prev;
                delete temp;
                return;
            }
            traverse = traverse->next;
        } while (traverse != head);
    }

    // Utility functions
    bool search(T key)
    {
        if (!head)
            return false;
        DNode<T> *traverse = head;
        do
        {
            if (traverse->data == key)
            {
                return true;
            }
            traverse = traverse->next;
        } while (traverse != head);
        return false;
    }
    void update(T key, T val)
    {
        if (!head)
            return;
        DNode<T> *traverse = head;
        do
        {
            if (traverse->data == key)
            {
                traverse->data = val;
                return;
            }
            traverse = traverse->next;
        } while (traverse != head);
    }
    int countNodes()
    {
        int count = 0;
        if (!head)
            return 0;
        DNode<T> *traverse = head;
        do
        {
            count++;
            traverse = traverse->next;
        } while (traverse != head);
        return count;
    }
};

#endif