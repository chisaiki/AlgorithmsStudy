# Errors

## Header File
- Header File inclusion error
```cpp
#include 'binarytree.h' //Wrong

#include "binarytree.h" //Correct

//Need to use double quotes for inclusion

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

