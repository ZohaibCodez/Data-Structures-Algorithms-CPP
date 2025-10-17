#include <iostream>
#include "..\Uni\ADT's\LinkedList\LSLL.h"

using namespace std;

LSLL<int>* removeElements(LSLL<int> *l,int val){
    if(l == nullptr) return l;
    while (l != nullptr && l->val == val) {
            LSLL<int>* temp = l;
            l = l->next;
            delete temp;
        }
        LSLL<int>* traverse = l;
        LSLL<int>* previous = nullptr;
        while (traverse != nullptr) {
            if (traverse->val == val) {
                LSLL<int>* temp = traverse;
                traverse = traverse->next;
                previous->next = traverse;
                delete temp;
            } else {
                previous = traverse;
                traverse = traverse->next;
            }
        }
        return l;
}

int main()
{
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    LSLL<int> *l;
    l->create(arr, n);

    cout << "Original list: ";
    l->displayLinkedList();

    LSLL<int> s;
    // s = removeElements(l, 6);

    cout << "After removing 6s: ";
    // s.displayLinkedList();

    // freeList(l);
    return 0;
}