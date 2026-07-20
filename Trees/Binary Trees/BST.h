#ifndef BST_H_
#define BST_H_ 

template<T> 
struct TreeNode{
    T value; 
    TreeNode* leftchild; 
    TreeNode* rightchild; 

    TreeNode(T val = {}, TreeNode* initialleft = nullptr, TreeNode* initialright = nullptr) : value(val), leftchild(initialleft), rightchild(initialright);
};

class BST{
    private:
        TreeNode* root;

    public:
        
    
};


#endif 