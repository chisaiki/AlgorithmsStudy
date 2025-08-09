#include "binarytree.h"
#include <iostream>

int main(){
    // Create root node with pointers to child nodes
    BinaryTreeNode root(2, new BinaryTreeNode(1, nullptr, nullptr), new BinaryTreeNode(3, nullptr, nullptr));

    root.GetVal();
    root.GetObjVal();

    //Because the function is no longer attached to the object (turned static), I need to specify where this function is coming from
    std::cout << BinaryTreeNode::SearchVal(&root, 3) << std::endl;
    if((BinaryTreeNode::SearchVal(&root, 12)) == 0){
        BinaryTreeNode::InsertVal(&root, 12);

    }

    BinaryTreeNode::PrintTree(&root);
}