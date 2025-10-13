#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    LinkedList<int> l;
    l.removeAtTail();
    l.insertAtTail(1);
    cout << "LinkedList: ";
    l.displayLinkedList();
    cout << endl;
    l.insertAtHead(2);
    cout << "LinkedList: ";
    l.displayLinkedList();
    cout << endl;
    l.insertAtHead(3);
    l.insertAfter(2,99);
    l.insertAtHead(4);
    l.insertAfter(3,5);
    l.insertBefore(5,22);
    l.removeAtHead();
    l.removeAtHead();
    l.removeAfter(5);
    cout << "Using Recursive Display Function to print LinkedList in Order from Head - Tail: ";
    l.recursiveDisplayLinkedListInStraightOrder();
    cout << endl;
    cout << "Using Recursive Display Function to print LinkedList in Order from Tail - Head: ";
    l.recursiveDisplayLinkedListInReverseOrder();
    cout << endl;
    cout << "Using Simple Loop Display Function: ";
    l.displayLinkedList();
    cout << endl;
    cout << "Count of Nodes in LinkedList using simple count() : " << l.count();
    cout << endl;
    cout << "Count of Nodes in LinkedList using simple Recursive Count Function rCount() : " << l.rCount();
    cout << endl; 
    cout << "Sum Function sum() : " << l.sum();
    cout << endl; 
    cout << "Recursive Sum Function rSum() : " << l.rSum();
    return 0;
}