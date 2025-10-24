#ifndef CIRCULAR_DOUBLY_LINKEDLIST
#define CIRCULAR_DOUBLY_LINKEDLIST

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class DNode
{
public:
    T data;
    DNode<T> *next;
    DNode<T> *prev;

    DNode(const T &val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class CDLinkedList
{
private:
    DNode<T> *head;

public:
    CDLinkedList() : head(nullptr) {}

    ~CDLinkedList()
    {
        while (head)
            removeAtHead();
    }

    void displayList()
    {
        if (!head)
        {
            cout << "(empty)";
            return;
        }
        DNode<T> *traverse = head;
        do
        {
            cout << traverse->data;
            if (traverse->next != head)
                cout << " ";
            traverse = traverse->next;
        } while (traverse != head);
    }

    // Insertion functions
    void insertAtHead(const T &val)
    {
        DNode<T> *temp = new DNode<T>(val);
        if (!head)
        {
            temp->next = temp->prev = temp;
            head = temp;
            return;
        }
        DNode<T> *tail = head->prev;
        temp->next = head;
        temp->prev = tail;
        tail->next = temp;
        head->prev = temp;
        head = temp;
    }
    void insertAtTail(const T &val)
    {
        if (!head)
        {
            insertAtHead(val);
            return;
        }
        DNode<T> *temp = new DNode<T>(val);
        DNode<T> *tail = head->prev;
        temp->prev = tail;
        temp->next = head;
        tail->next = temp;
        head->prev = temp;
    }

    // Deletion Functions
    void removeAtHead()
    {
        if (!head)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        DNode<T> *tail = head->prev;
        DNode<T> *toDelete = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete toDelete;
    }
    void removeAtTail()
    {
        if (!head)
            return;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        DNode<T> *tail = head->prev;
        DNode<T> *newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
    }
    void remove(const T &val)
    {
        if (!head)
            return;
        // single node
        if (head->next == head)
        {
            if (head->data == val)
            {
                delete head;
                head = nullptr;
            }
            return;
        }
        // find node
        DNode<T> *cur = head;
        do
        {
            if (cur->data == val)
            {
                DNode<T> *p = cur->prev;
                DNode<T> *n = cur->next;
                p->next = n;
                n->prev = p;
                if (cur == head)
                    head = n;
                delete cur;
                return;
            }
            cur = cur->next;
        } while (cur != head);
    }

    // Utility functions
    bool search(const T &key) const
    {
        if (!head)
            return false;
        DNode<T> *traverse = head;
        do
        {
            if (traverse->data == key)
                return true;
            traverse = traverse->next;
        } while (traverse != head);
        return false;
    }

    // void merge(CDLinkedList<T> list1, CDlinkedList<T> list2)
    // {
    //     if (list1->head)
    //     {
    //     }
    // }

    void update(const T &key, const T &val)
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
    int countNodes() const
    {
        if (!head)
            return 0;
        int count = 0;
        DNode<T> *traverse = head;
        do
        {
            ++count;
            traverse = traverse->next;
        } while (traverse != head);
        return count;
    }

    void merge(CDLinkedList &list1, CDLinkedList &list2)
    {
        if (!list1.head && !list2.head)
            return;
        if (!list1.head)
        {
            head = list2.head;
            list2.head = nullptr;
            return;
        }
        if (!list2.head)
        {
            head = list1.head;
            list1.head = nullptr;
            return;
        }

        // breaking circularity
        list1.head->prev->next = nullptr;
        list2.head->prev->next = nullptr;

        DNode<T> *p1 = list1.head;
        DNode<T> *p2 = list2.head;
        DNode<T> *mergedHead = nullptr, *mergedTail = nullptr;

        while (p1 && p2)
        {
            DNode<T> *smaller;
            if (p1->data < p2->data)
            {
                smaller = p1;
                p1 = p1->next;
            }
            else
            {
                smaller = p2;
                p2 = p2->next;
            }

            if(!mergedHead){
                mergedHead = mergedTail = smaller;
                mergedHead->prev = nullptr;
                mergedHead->next = nullptr;
            }else{
                mergedTail->next = smaller;
                smaller->prev = mergedTail;
                mergedTail = smaller;
            }
        }
    }

    void splitList(CDLinkedList<T> &leftHalf, CDLinkedList<T> &rightHalf)
    {
        if (!head)
            return;

        int n = countNodes();

        if (n == 1)
        {
            leftHalf.head = head;
            leftHalf.head->next = leftHalf.head->prev = leftHalf.head;
            head == nullptr;
            return;
        }

        int mid = (n + 1) / 2;
        DNode<T> *leftStart = head;
        DNode<T> *midNode = head;

        for (int i = 0; i < mid; i++)
        {
            midNode = midNode->next;
        }

        // making start and end of two nodes
        DNode<T> *rightStart = midNode->next;
        DNode<T> *leftEnd = midNode;
        DNode<T> *rightEnd = head->prev;

        // Closing left Half
        leftEnd->next = leftStart;
        leftStart->prev = leftEnd;

        // Closing right Half
        rightEnd->next = rightStart;
        rightStart->prev = rightEnd;

        // Assigning Heads
        leftHalf.head = leftStart;
        rightHalf.head = rightStart;

        head = nullptr;
    }
};

#endif