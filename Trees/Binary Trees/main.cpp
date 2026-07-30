#include "BST.h"
#include <iostream>

int main(){


    BST<int> NewTree;

    NewTree.Insert(10);
    NewTree.Insert(3);
    NewTree.Insert(11);
    NewTree.Insert(8);
    NewTree.Insert(7);
    NewTree.Insert(2);
    NewTree.Insert(12);
    NewTree.Insert(10);
    NewTree.Insert(1);


    NewTree.PrintTree();

    std::cout << NewTree.Search(11)->value << std::endl;


    return 0;
}