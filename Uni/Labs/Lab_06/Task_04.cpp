#include <iostream>
#include "LSLL.h"
using namespace std;



int main()
{
    int arr1[] = {2,6,4,8,9};
    LSLL<int> list1;
    list1.create(arr1, 5);
    cout << "List 1 : ";
    list1.displayLinkedList();
    cout << endl;
    list1.reverseList();
    cout << "List 1 : ";
    list1.displayLinkedList();
    cout << endl;
    return 0;
}