#include <iostream>
#include "LSLL.h"
using namespace std;

int main()
{
    int arr[] = {4, 2, 8, 1, 9, 5, 4, 6};
    LSLL<int> list;
    list.create(arr, 8);
    list.displayLinkedList();
    int val = 4;
    list.removeKthNode(1,val);
    cout << endl;
    list.displayLinkedList();
    return 0;
}