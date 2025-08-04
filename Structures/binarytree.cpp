#include "binarytree.h"
#include <iostream>

BinaryTreeNode::BinaryTreeNode(){}

BinaryTreeNode::BinaryTreeNode(int val, BinaryTreeNode* left_ptr = nullptr, BinaryTreeNode* right_ptr = nullptr) : val_(val), left_ptr_(left_ptr), right_ptr_(right_ptr){
    //this->val_ = val;
}

void BinaryTreeNode::GetVal(){
    std::cout << "Value is: " << this->val_ << std::endl;
}

void BinaryTreeNode::GetObjVal(){
    std::cout << "Left Ptr Val: " << left_ptr_->val_ << std::endl;
    std::cout << "Right Ptr Val: " << right_ptr_->val_ << std::endl;
}

void BinaryTreeNode::PrintTree(BinaryTreeNode* root){
    if(root == nullptr){
        return;
    }

    std::cout << " " << root->val_;
    PrintTree(root->left_ptr_);    
    PrintTree(root->right_ptr_);

}

bool BinaryTreeNode::SearchVal(BinaryTreeNode* root, int value){

    if(root == nullptr)
        return false;

    if(root->val_ == value){
        return true;
    }

    if(root->val_ < value){
        return SearchVal(root->right_ptr_, value);
    }
    else if(root->val_ > value){
        return SearchVal(root->left_ptr_, value);
    }

    return false;
    
}

BinaryTreeNode* BinaryTreeNode::InsertVal(BinaryTreeNode* root, int value){

    //When pointed to the correct location, insert new node
    if(root == nullptr){
        std::cout << "Success" << std::endl;
        return new BinaryTreeNode(value, nullptr, nullptr);
    }

    //If node already exists, overwrite the value
    if(root->val_ == value){
        std::cout << "Already exists" << std::endl;
        root->val_ = value;
    }

    //need to figure out why this works
    if(root->val_ < value){
        // You want to update the RIGHT child, then return the current root
        root->right_ptr_ = InsertVal(root->right_ptr_, value);
        return root;
    }
    else if(root->val_ > value){
        // You want to update the LEFT child, then return the current root  
        root->left_ptr_ = InsertVal(root->left_ptr_, value);
        return root;
    }

    return root;
}
