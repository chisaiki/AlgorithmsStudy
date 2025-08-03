#include "binarytree.h"

int main(){
    // Create root node with pointers to child nodes
    BinaryTreeNode root(2, new BinaryTreeNode(1, nullptr, nullptr), new BinaryTreeNode(3, nullptr, nullptr));

    root.getVal();
}