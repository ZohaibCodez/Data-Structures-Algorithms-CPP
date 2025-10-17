#include "LSLL.h"
#include <iostream>

using namespace std;

int main()
{
    // LSLL<int> l;
    // l.removeAtTail();
    // l.insertAtTail(1);
    // cout << "LSLL: ";
    // l.displayLinkedList();
    // cout << endl;
    // l.insertAtHead(2);
    // cout << "LSLL: ";
    // l.displayLinkedList();
    // cout << endl;
    // l.insertAtHead(3);
    // l.insertAfter(2,99);
    // l.insertAtHead(4);
    // l.insertAfter(3,5);
    // l.insertBefore(5,22);
    // l.removeAtHead();
    // l.removeAtHead();
    // l.removeAfter(5);
    // cout << "Using Recursive Display Function to print LSLL in Order from Head - Tail: ";
    // l.recursiveDisplayLinkedListInStraightOrder();
    // cout << endl;
    // cout << "Using Recursive Display Function to print LSLL in Order from Tail - Head: ";
    // l.recursiveDisplayLinkedListInReverseOrder();
    // cout << endl;
    // cout << "Using Simple Loop Display Function: ";
    // l.displayLinkedList();
    // cout << endl;
    // cout << "Searching 5 using simple search: " << l.rSearch(5) << endl;
    // cout << "Searching 100 using simple search: " << l.rSearch(100) << endl;
    // cout << "Searching 99 using simple search: " << l.rSearch(99) << endl;
    // cout << "Count of Nodes in LSLL using simple count() : " << l.countNodes();
    // cout << endl;
    // cout << "Count of Nodes in LSLL using simple Recursive Count Function rCount() : " << l.rCount();
    // cout << endl;
    // cout << "Sum Function sum() : " << l.sum();
    // cout << endl;
    // cout << "Recursive Sum Function rSum() : " << l.rSum();

    // LSLL<int> ll;
    // ll.insertAtHead(4);
    // ll.insertAtHead(3);
    // ll.insertAtHead(2);
    // ll.insertAtHead(1);
    // cout << "Display : ";
    // ll.displayLinkedList();
    // cout << endl;
    // ll.insert(0,-1);
    // cout << "Display : ";
    // ll.displayLinkedList();
    // cout << endl;
    // ll.insert(5,5);
    // cout << "Display : ";
    // ll.displayLinkedList();
    // cout << endl;
    // ll.insert(7,5);
    // cout << "Display : ";
    // ll.displayLinkedList();
    // cout << endl;

    LSLL<int> l2;
    l2.insert(0, 10);
    l2.insert(1, 11);
    l2.insert(2, 12);
    l2.insert(3, 13);
    // l2.insert(0,0);
    cout << "Display : ";
    l2.displayLinkedList();
    cout << endl;
    l2.update(12, 20);
    cout << "Display : ";
    l2.displayLinkedList();
    cout << endl;
    return 0;
}