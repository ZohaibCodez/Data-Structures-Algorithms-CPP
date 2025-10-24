#include "CDLL.h"
#include <iostream>
using namespace std;

int main()
{
    CDLinkedList<int> list1, list2, list3;
    list1.insertAtHead(1);
    list1.insertAtTail(3);
    list1.insertAtTail(5);
    list1.insertAtTail(6);
    list1.insertAtTail(8);
    list1.insertAtTail(12);
    list1.insertAtTail(14);
    cout << "List1 : ";
    list1.displayList();
    cout << endl;
    list1.splitList(list2,list3);
    cout << "List2 : ";
    list2.displayList();
    cout << endl;
    cout << "List3 : ";
    list3.displayList();
    return 0;
}