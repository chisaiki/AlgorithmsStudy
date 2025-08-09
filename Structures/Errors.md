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

- **Static Function Declaration vs Implementation Error**: `cannot declare member function 'static bool BinaryTreeNode::search(BinaryTreeNode*, int)' to have static linkage`
```cpp
// ❌ Wrong - Don't use 'static' in .cpp file
static bool BinaryTreeNode::search(BinaryTreeNode* root, int value) {
    // implementation
}

// ✅ Correct - Only use 'static' in .h file declaration
// Header file (.h):
static bool search(BinaryTreeNode* root, int value);

// Implementation file (.cpp):
bool BinaryTreeNode::search(BinaryTreeNode* root, int value) {
    // implementation
}

/* Rule: Function specifiers (static, virtual, etc.) go in the DECLARATION only, 
   not in the implementation. The compiler knows it's static from the header. */
```



## Main.cpp

- You can create objects inline, inside parameter of other objects
```cpp
BinaryTreeNode root(2, BinaryTreeNode(1, nullptr, nullptr), BinaryTreeNode(3, nullptr, nullptr)); //Wrong
BinaryTreeNode root(2, new BinaryTreeNode(1, nullptr, nullptr), new BinaryTreeNode(3, nullptr, nullptr)); //Correct

//I forgot to use the new keyword to create these objects DYNAMICALLY

/*You need new because your constructor expects pointers, and new is one way to get pointers to dynamically created objects. However, for learning purposes, I'd recommend the stack allocation approach (predefining the objects then passing their address) as it's safer and doesn't require manual memory management.*/
```

- **Null Pointer Dereference Error**: Always check for `nullptr` BEFORE accessing pointer members
```cpp
// Wrong order - will crash if root is nullptr
if(root->val_ == value) { ... }
if(root == nullptr) return false;

// Correct order - check nullptr first
if(root == nullptr) return false;
if(root->val_ == value) { ... }
```

- **Missing Return Statement Warning**: `control reaches end of non-void function`
```cpp
// Problem: Missing return path
if(root->val_ < value) {
    return search(root->right_ptr_, value);
}
else if(root->val_ > value) {  // What if neither condition is true?
    return search(root->left_ptr_, value);
}
// No return statement here!

// Solution: Use 'else' instead of 'else if' OR add default return
else {  // Covers remaining case
    return search(root->left_ptr_, value);
}
```

**Note: Your binarytree.cpp already includes <iostream>, but that doesn't automatically make it available in main.cpp. Each .cpp file needs its own includes for what it uses directly.**


- **When to Use Static Functions**: If a member function doesn't use any instance variables, consider making it static
```cpp
// Current code - redundant and confusing
root.search(&root, 3);  // Why call search ON root and PASS &root?

// Better design - make search static
class BinaryTreeNode {
public:
    static bool search(BinaryTreeNode* root, int value);  // Add 'static'
};

// Because the function is no longer attached to the object (turned static), I need to specify where this function is coming from
BinaryTreeNode::search(&root, 3);  // Much cleaner!

/* 
Why this is better:
1. The search function doesn't use any instance members (this->val_, this->left_ptr_, etc.)
2. It only works with the 'root' parameter passed to it
3. Static functions belong to the class, not to specific objects
4. Makes the code more logical - we're searching a tree structure, not asking a specific node to search
*/
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

