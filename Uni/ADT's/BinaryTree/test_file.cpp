#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<int> tree(5); // height = 5 (so 31 possible nodes)

    tree.setRoot(10);
    tree.setLeftChild(10, 11);
    tree.setRightChild(10, 12);
    tree.setRightChild(12, 15);
    tree.setLeftChild(11, 13);
    tree.setRightChild(11, 14);
    tree.setLeftChild(14, 16);
    tree.setRightChild(16, 7);

    cout << "Search 10 -> index: " << tree.search(10) << endl;
    cout << "Search 7  -> index: " << tree.search(7) << endl;
    cout << "Search 20 -> index: " << tree.search(20) << endl;
    cout << "Search 100 -> index: " << tree.search(100) << endl;

    cout << "\nRemoving 5 and its subtree...\n";
    tree.remove(5);

    cout << "Search 5 -> " << tree.search(5) << endl;
    cout << "Search 3 -> " << tree.search(3) << endl;
    cout << "Search 7 -> " << tree.search(7) << endl;

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
