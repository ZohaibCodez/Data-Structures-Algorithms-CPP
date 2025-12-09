#include "Task_01.cpp"
#include <iostream>
#include<vector>

using namespace std;

int main()
{
    BST bst;
    vector<int> in1 = {1, 2, 3, 4, 5, 6};
    vector<int> pre1 = {3, 1, 2, 5, 4, 6};

    bst.construct_from_traversals(in1, pre1);
    cout << "In-order traversal (Example 1): ";
    bst.inOrder();
    cout << "Post-order traversal (Example 1): ";
    bst.postOrder();
    BST bst2;
    vector<int> in2 = {5, 10, 15, 25, 27, 30, 35, 40, 45, 50, 52, 55, 60, 65, 70, 75, 80, 85, 90, 100};
    vector<int> pre2 = {50, 25, 10, 5, 15, 40, 30, 27, 35, 45, 75, 60, 55, 52, 65, 70, 90, 80, 85, 100};
    bst2.construct_from_traversals(in2, pre2);
    cout << "\nIn-order traversal (Example 2): ";
    bst2.inOrder();
    cout << "Post-order traversal (Example 2): ";
    bst2.postOrder();
    return 0;
}