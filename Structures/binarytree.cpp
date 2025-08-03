#include "binarytree.h"
#include <iostream>
#include <cstddef>

BinaryTreeNode::BinaryTreeNode(){}

BinaryTreeNode::BinaryTreeNode(int val, BinaryTreeNode* left_ptr = nullptr, BinaryTreeNode* right_ptr = nullptr) : val_(val), left_ptr_(left_ptr), right_ptr_(right_ptr){
    //this->val_ = val;
}

void BinaryTreeNode::getVal(){
    std::cout << "Value is: " << this->val_ << std::endl;
}