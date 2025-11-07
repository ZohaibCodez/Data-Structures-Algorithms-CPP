#include<iostream>
#include "BinaryTree.h"

using namespace std;

int main(){
    BinaryTree<char> tree(5);

    tree.setRoot('A');
    tree.setLeftChild('A','B');
    tree.setRightChild('A','C');
    tree.setRightChild('C','F');
    tree.setLeftChild('B','D');
    tree.setRightChild('D','H');
    tree.setRightChild('B','E');
    tree.setLeftChild('E','I');
    tree.setRightChild('E','J');
    tree.setLeftChild('I','K');

    tree.displayAncestors('I');

    tree.displayParenthesizedView();
    tree.heightOfTree();

}