#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    LSLL<int> list;
    // Sample testing (You can add more)
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAfter(20, 25);
    list.insertBefore(10, 5);
    list.displayLinkedList();
    list.remove(25);
    list.removeAtHead();
    list.removeAtTail();
    cout << "\nAfter deletions: ";
    list.displayLinkedList();
    list.update(20, 99);
    cout << "\nAfter update: ";
    list.displayLinkedList();
    if (list.search(99))
        cout << "\nElement 99 found!";
    else
        cout << "\nElement 99 not found!";
    cout << "\nTotal Nodes: " << list.countNodes();
    return 0;
}