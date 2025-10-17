#include <iostream>
#include "LSLL.h"
using namespace std;



int main()
{
    int arr1[] = {2,6,4};
    LSLL<int> list1;
    list1.create(arr1, 3);
    int arr2[] = {8,1,3};
    LSLL<int> list2;
    list2.create(arr2, 3);
    cout << "List 1 : ";
    list1.displayLinkedList();
    cout << endl;
    cout << "List 2 : ";
    list2.displayLinkedList();
    cout << endl;
    LSLL<int> list3;
    list3.shuffleMerge(list1,list2);
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