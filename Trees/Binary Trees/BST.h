#ifndef BST_H_
#define BST_H_ 

template<typename T> 
struct TreeNode{
    T value; 
    TreeNode<T>* leftchild; 
    TreeNode<T>* rightchild; 

    TreeNode(T val = {}, TreeNode<T>* initialleft = nullptr, TreeNode<T>* initialright = nullptr) : value(val), leftchild(initialleft), rightchild(initialright){};
};

template<typename T>  
class BST{
    private:
        TreeNode<T>* root_ = nullptr;

    public:
        T GetValue() const{
            return this->root_->value;
        };

        BST(TreeNode<T>* root = new TreeNode<T>){
            root_ = root;
        }
    
};


#endif 