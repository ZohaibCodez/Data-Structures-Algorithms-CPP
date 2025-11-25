#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;
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

    // tree.levelOrder();
    // cout << tree.getParent(7);
    // tree.removeByValue(2);
    // cout << tree.findNodeSiblings(10);
    // tree.displayDescendents(2);
    tree.levelOrder();
    tree.mirror();
    cout << endl;

    tree.levelOrder();
}