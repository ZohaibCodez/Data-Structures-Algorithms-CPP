#include<iostream>
#include "BinaryTree.h"

using namespace std;

int main(){
    BinaryTree<int> tree(4);

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

    // tree.remove(5);

    // cout << tree.search(10) << endl;

    // cout << tree.getParent(7) << endl;
    // tree.displayDescendents(1);
    // tree.heightOfTree();
    // tree.displayLevel(2);
    tree.heightOfTree();
    cout << endl;
    cout << tree.findLevelOfNode(10) << endl;
}