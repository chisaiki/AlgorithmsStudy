# Notes

## Static vs Global Functions - TL;DR

**Question**: Should utility functions be static class members or global functions?

**Answer**: **Static is better** for class-related utilities.

### Quick Rule:
- **Static**: Function belongs to a specific class → `ClassName::functionName()`
- **Global**: Function works with multiple unrelated types → `functionName()`

### Example:
```cpp
// ✅ Good - Static (belongs to BinaryTreeNode)
class BinaryTreeNode {
public:
    static bool search(BinaryTreeNode* root, int value);
};
BinaryTreeNode::search(&root, 3);

// ❌ Avoid - Global (pollutes namespace)
bool search(BinaryTreeNode* root, int value);
search(&root, 3);  // Which search? From where?
```

### Why Static Wins:
1. **Organization**: Keeps related code together
2. **Namespace**: No naming conflicts  
3. **Professional**: Industry standard pattern
4. **Future-proof**: Can access private class members if needed

### When to Use Global:
- General utilities like `max()`, `min()`
- Functions working with multiple unrelated classes
- Operator overloading outside classes

## Utility Function vs Member Function

### **Key Difference**:
- **Member**: "Hey object, do something with YOUR data"
- **Utility**: "Hey class, do this operation with the data I'm giving you"

## Binary Tree Insert - Return-Based Approach - TL;DR

**Why does this pattern work?**

```cpp
BinaryTreeNode* InsertVal(BinaryTreeNode* root, int value) {
    if(root == nullptr) {
        return new BinaryTreeNode(value, nullptr, nullptr);  // Create new node
    }
    
    if(root->val_ < value) {
        root->right_ptr_ = InsertVal(root->right_ptr_, value);  // Key line!
        return root;
    }
    else if(root->val_ > value) {
        root->left_ptr_ = InsertVal(root->left_ptr_, value);   // Key line!
        return root;
    }
    
    return root;  // No change needed
}
```

**The Magic:**
1. **Recursive calls return either:**
   - The same pointer (no change)
   - A new pointer (new node was created)

2. **Assignment captures the result:**
   - `root->right_ptr_ = InsertVal(...)` updates the tree structure
   - The parent node now points to the correct subtree

3. **Return propagates changes upward:**
   - Each level returns its (possibly updated) root
   - Changes bubble up through the entire tree

**Example Trace:**
```
Insert 4 into tree: 2(1,3)
1. InsertVal(2) → go right → InsertVal(3) 
2. InsertVal(3) → go right → InsertVal(nullptr)
3. InsertVal(nullptr) → return new Node(4)
4. Back to 3: right_ptr_ = Node(4), return 3
5. Back to 2: right_ptr_ = 3 (unchanged), return 2
Result: 2(1, 3(null, 4))
```

**Key Insight**: Each node "catches" the result and updates its child pointer!

## Why Original Insert Failed - TL;DR

**Original broken code:**
```cpp
void InsertVal(BinaryTreeNode* root, int value) {
    if(root == nullptr) {
        new BinaryTreeNode(value, nullptr, nullptr);  // ❌ Memory leak!
        return;
    }
    // ... recursive calls
}
```

**Two Fatal Problems:**

### **1. Memory Leak - Created Node Goes Nowhere**
```cpp
new BinaryTreeNode(value, nullptr, nullptr);  // Creates node in memory
// But no variable stores the pointer!
// Node exists but is unreachable = memory leak
```

### **2. No Way to Update Parent's Pointer**
```cpp
void InsertVal(BinaryTreeNode* root, int value) {
    // 'root' is just a COPY of a pointer value
    // Even if you did: root = new BinaryTreeNode(...)
    // You're only changing the local copy, not the original tree!
}
```

**The Core Issue:**
```
Parent Node: left_ptr_ = 0x1234 (points to some child)
Call: InsertVal(left_ptr_, 5)
// Inside function: root = 0x1234 (copy of the value)
// How do you change left_ptr_ from inside the function?
// You CAN'T! You only have a copy of its value, not a reference to it!
```

**Why Return-Based Works:**
```cpp
// Return the new/updated pointer back to caller
left_ptr_ = InsertVal(left_ptr_, 5);  // Caller updates the actual pointer!
```

**Lesson**: When you need to modify a pointer variable, you need either:
- **Return the new value** (most common)
- **Pass by reference** (`BinaryTreeNode*& root`)
- **Pass pointer-to-pointer** (`BinaryTreeNode** root`)

---

### **Member Function**:
- **Uses** the object's data (`this->member_variable_`)
- **Called ON** a specific object instance
- **Accesses/modifies** the object's state

```cpp
class BinaryTreeNode {
private:
    int val_;
public:
    void getVal() {                    // Member function
        std::cout << this->val_;       // Uses object's data
    }
};

BinaryTreeNode node;
node.getVal();  // Called ON the 'node' object
```

### **Utility Function**:
- **Doesn't use** the object's data (no `this->`)
- **Works with** parameters passed to it
- **Performs operations** independent of any specific object instance

```cpp
class BinaryTreeNode {
public:
    static bool search(BinaryTreeNode* root, int value) {  // Utility function
        // Only uses 'root' parameter, not 'this'
        if (root == nullptr) return false;
        return root->val_ == value;  // Uses parameter, not object data
    }
};

BinaryTreeNode::search(&root, 3);  // Called on CLASS, not object
```