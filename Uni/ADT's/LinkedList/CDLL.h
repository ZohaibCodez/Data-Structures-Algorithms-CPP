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
        // if merged empty -> keep head null; otherwise make circular
    
    // void merge(CDLinkedList &list1, CDLinkedList &list2)
    // {
    //     // destination must be empty
    //     while (head)
    //         removeAtHead();

    //     // quick cases
    //     if (!list1.head && !list2.head) return;
    //     if (!list1.head) { head = list2.head; list2.head = nullptr; return; }
    //     if (!list2.head) { head = list1.head; list1.head = nullptr; return; }

    //     DNode<T> *mergedHead = nullptr;
    //     DNode<T> *mergedTail = nullptr;

    //     // repeatedly detach the smaller head from list1 or list2 and append to merged list
    //     while (list1.head && list2.head)
    //     {
    //         CDLinkedList<T> *src = (list1.head->data <= list2.head->data) ? &list1 : &list2;
    //         DNode<T> *node = src->head;

    //         // detach head node from src
    //         if (node->next == node) // only node
    //         {
    //             src->head = nullptr;
    //         }
    //         else
    //         {
    //             DNode<T> *next = node->next;
    //             DNode<T> *tail = node->prev;
    //             tail->next = next;
    //             next->prev = tail;
    //             src->head = next;
    //         }

    //         // append node to merged circular list
    //         if (!mergedHead)
    //         {
    //             node->next = node->prev = node;
    //             mergedHead = mergedTail = node;
    //         }
    //         else
    //         {
    //             node->next = mergedHead;
    //             node->prev = mergedTail;
    //             mergedTail->next = node;
    //             mergedHead->prev = node;
    //             mergedTail = node;
    //         }
    //     }

    //     // splice remaining nodes (if any) from list1 or list2
    //     CDLinkedList<T> *rem = list1.head ? &list1 : (list2.head ? &list2 : nullptr);
    //     if (!mergedHead)
    //     {
    //         // merged empty -> just take remaining list (already circular)
    //         if (rem) { head = rem->head; rem->head = nullptr; }
    //         else head = nullptr;
    //     }
    //     else if (rem)
    //     {
    //         DNode<T> *remHead = rem->head;
    //         DNode<T> *remTail = remHead->prev;

    //         // link mergedTail <-> remHead and remTail <-> mergedHead
    //         mergedTail->next = remHead;
    //         remHead->prev = mergedTail;
    //         remTail->next = mergedHead;
    //         mergedHead->prev = remTail;

    //         // new tail is remTail
    //         mergedTail = remTail;
    //         head = mergedHead;

    //         rem->head = nullptr;
    //     }
    //     else
    //     {
    //         // no remaining nodes
    //         head = mergedHead;
    //     }
    // }
};

#endif