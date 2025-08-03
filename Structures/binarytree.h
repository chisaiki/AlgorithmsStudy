//Header Guard file names, make your own, "BINARY_TREE_" based on Google style guide
#ifndef BINARY_TREE_ 
#define BINARY_TREE_


class BinaryTreeNode{
    private:
    int val_;
    
    //Pointer type has to be a class pointer, because left and right node will be pointing to an entire class object
    BinaryTreeNode* left_ptr_;
    BinaryTreeNode* right_ptr_;

    public: 
    //Constructors
    BinaryTreeNode();
    BinaryTreeNode(int val, BinaryTreeNode* left_ptr, BinaryTreeNode* right_ptr);

    void GetVal();
    void GetObjVal();

    //Need to make a print tree function
    static void PrintTree(BinaryTreeNode* root);

    //Takes root object and a value needed to be searched, and returns if it exists or not
    static bool SearchVal(BinaryTreeNode* root, int value);

    //not sure if return should be void or bool to collect success or fail
    static BinaryTreeNode* InsertVal(BinaryTreeNode* root, int value);

    static void DeleteVal(BinaryTreeNode* root, int value);



};

#endif