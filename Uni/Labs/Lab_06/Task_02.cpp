#include <iostream>
#include "LSLL.h"
using namespace std;



int main()
{
    int arr1[] = {7, 3, 4, 2};
    LSLL<int> list1;
    list1.create(arr1, 4);
    int arr2[] = {5, 9};
    LSLL<int> list2;
    list2.create(arr2, 2);
    cout << "List 1 : ";
    list1.displayLinkedList();
    cout << endl;
    cout << "List 2 : ";
    list2.displayLinkedList();
    cout << endl;
    LSLL<int> list3;
    list3.combine(list1,list2);
    cout << "List 3 : ";
    list3.displayLinkedList();
    cout << endl;
    cout << "List 1 : ";
    list1.displayLinkedList();
    cout << endl;
    cout << "List 2 : ";
    list2.displayLinkedList();
    return 0;
}