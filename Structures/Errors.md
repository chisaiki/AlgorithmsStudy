# Errors

## Header File
- Header File inclusion error
```cpp
#include 'binarytree.h' //Wrong

#include "binarytree.h" //Correct

//Need to use double quotes for inclusion

```

## BinaryTree.cpp
- Error: request for member ‘val_’ in ‘((BinaryTreeNode*)this)->BinaryTreeNode::right_ptr_’, which is of pointer type ‘BinaryTreeNode*’ (maybe you meant to use ‘->’ ?)
    - Solution: left_ptr_->val_ instead of left_ptr_.val_

The -> operator is actually syntactic sugar for pointer dereferencing:
```cpp
// These are equivalent:
left_ptr_->val_
(*left_ptr_).val_  // Dereference the pointer first, then use .
```

```
. (dot) = Use with objects
-> (arrow) = Use with pointers

*The memory trick "Object = One dot" and "Pointer = Pointer arrow" should help you remember!*
```





## Main.cpp

- You can create objects inline, inside parameter of other objects
```cpp
BinaryTreeNode root(2, BinaryTreeNode(1, nullptr, nullptr), BinaryTreeNode(3, nullptr, nullptr)); //Wrong
BinaryTreeNode root(2, new BinaryTreeNode(1, nullptr, nullptr), new BinaryTreeNode(3, nullptr, nullptr)); //Correct

//I forgot to use the new keyword to create these objects DYNAMICALLY

/*You need new because your constructor expects pointers, and new is one way to get pointers to dynamically created objects. However, for learning purposes, I'd recommend the stack allocation approach (predefining the objects then passing their address) as it's safer and doesn't require manual memory management.*/
```

## Future Recommendation
- In modern C++ (C++11+), you'd use smart pointers instead of raw new/delete:
```cpp
#include <memory>

// Using smart pointers (modern C++)
auto leftChild = std::make_unique<BinaryTreeNode>(1, nullptr, nullptr);
auto rightChild = std::make_unique<BinaryTreeNode>(3, nullptr, nullptr);
BinaryTreeNode root(2, leftChild.get(), rightChild.get());
```

- Or even better, redesign the class to use smart pointers internally:
```cpp
class BinaryTreeNode {
private:
    int val_;
    std::unique_ptr<BinaryTreeNode> left_;
    std::unique_ptr<BinaryTreeNode> right_;
public:
    BinaryTreeNode(int val, 
                   std::unique_ptr<BinaryTreeNode> left = nullptr,
                   std::unique_ptr<BinaryTreeNode> right = nullptr);
};
```

