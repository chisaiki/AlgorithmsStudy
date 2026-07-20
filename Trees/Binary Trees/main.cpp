#include "BST.h"
#include <iostream>

int main(){
    TreeNode<int>* obj = new TreeNode<int>(2);

    BST<int> NewObject;

    std::cout << NewObject.GetValue() << std::endl;

    return 0;
}