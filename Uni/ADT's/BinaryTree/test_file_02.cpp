#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<int> tree(4); // height = 4 (so 15 possible nodes)

    tree.setRoot(1);
    tree.setLeftChild(1, 2);
    tree.setRightChild(1, 3);
    tree.setLeftChild(2, 4);
    tree.setRightChild(2, 5);
    tree.setLeftChild(4, 8);
    tree.setRightChild(4, 9);
    tree.setLeftChild(5, 10);
    tree.setLeftChild(3, 6);
    tree.setRightChild(3, 7);

    // cout << "Search 10 -> index: " << tree.search(10) << endl;
    // cout << "Search 7  -> index: " << tree.search(7) << endl;
    // cout << "Search 20 -> index: " << tree.search(20) << endl;
    // cout << "Search 100 -> index: " << tree.search(100) << endl;

    // cout << "\nRemoving 5 and its subtree...\n";
    // tree.remove(5);

    // cout << "Search 5 -> " << tree.search(5) << endl;
    // cout << "Search 3 -> " << tree.search(3) << endl;
    // cout << "Search 7 -> " << tree.search(7) << endl;

    cout << "PreOrder: ";
    tree.preOrder();
    cout << endl;

    cout << "PostOrder: ";
    tree.postOrder();
    cout << endl;

    cout << "InOrder: ";
    tree.inOrder();
    cout << endl;
    return 0;
}
