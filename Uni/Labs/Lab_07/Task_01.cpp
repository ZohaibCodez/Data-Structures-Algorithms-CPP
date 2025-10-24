#include "CDLL.h"
#include <iostream>
using namespace std;

int main()
{
    CDLinkedList<int> list1, list2, list3;
    list1.insertAtHead(4);
    list1.insertAtTail(7);
    list1.insertAtTail(10);
    list1.insertAtTail(12);
    cout << "List1 : ";
    list1.displayList();
    cout << endl;
    list2.insertAtHead(1);
    list2.insertAtTail(3);
    list2.insertAtTail(6);
    list2.insertAtTail(8);
    list2.insertAtTail(9);
    list2.insertAtTail(0);
    cout << "List2 : ";
    list2.displayList();
    cout << endl;
    list3.merge(list1,list2);
    cout << "List3 : ";
    list3.displayList();
    return 0;
}