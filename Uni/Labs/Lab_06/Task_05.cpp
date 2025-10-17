#include <iostream>
#include "LSLL.h"
using namespace std;

int main()
{
    int arr1[] = {23, 5, 4, 23, 6, 78, 4, 5,23,5};
    LSLL<int> list1;
    list1.create(arr1, 10);
    cout << "List 1 : ";
    list1.displayLinkedList();
    cout << endl;
    list1.removeDuplicates();
    cout << "List 1 : ";
    list1.displayLinkedList();
    cout << endl;
    return 0;
}
