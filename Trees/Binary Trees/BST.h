#ifndef BST_H_
#define BST_H_ 

#include <iostream>

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
        size_t size_ = 0;

        void PrintTree(TreeNode<T>* root, std::string indent = "", bool isLeft = true)
        {
            if (!root)
                return;

            PrintTree(root->rightchild, indent + (isLeft ? "|   " : "    "), false);

            std::cout << indent
                    << (isLeft ? "\\-- " : "/-- ")
                    << root->value << '\n';

            PrintTree(root->leftchild, indent + (isLeft ? "    " : "|   "), true);
        }

    public:
        BST(){};

        /*Changed it to a reference to guarantee existance of the object*/
        /*Removed const since I couldn't assign a const object to a raw pointer*/
        BST(TreeNode<T>& root){
            root_ = &root;
        }

        T GetValue() const{
            return this->root_->value;
        };

        size_t GetSize() const{
            return this->size_;
        }

        TreeNode<T>* BinarySearch(const T data, TreeNode<T>* current){
  
            if(current->value == data || current == nullptr){
                return current; 
            }
            else if(current->value > data){
                // I needed to return for some reason..? When do I return and when do I not?
                return BinarySearch(data, current->leftchild);
            }
            else if (current->value < data){
                return BinarySearch(data, current->rightchild);
            }

            return {};
        }

        TreeNode<T>* Search(const T data){
           if (root_ == nullptr){
            return root_;
           }

           return BinarySearch(data, root_);

        }

        /*Create a new node based on the data the user wants to pass*/
        /*NEXT FUNCTION DO IT RECURSIVELY*/
        bool Insert(T data = {}){
            if (root_ == nullptr){
                root_ = new TreeNode<T>(data);
                size_++;
                return true;
            }

            /*Find the position (parent) it belongs in*/
            TreeNode<T>* current = root_;
            while (current){

                if (current->value > data){
                    if (current->leftchild == nullptr){
                        current->leftchild = new TreeNode<T>(data);
                        size_++;
                        return true;
                    }
                    else{
                        current = current->leftchild;
                    }
                }

                else if (current->value <= data){
                    if(current->rightchild == nullptr){
                        current->rightchild = new TreeNode<T>(data);
                        size_++;
                        return true;
                    }
                    else{
                        current = current->rightchild;
                    }
                }

            }

            /*Set the parents next pointer to a new object*/
            return false; 
        }

        TreeNode<T>* FindSuccessor(TreeNode<T>* root){
            while (root->leftchild){
                root = root->leftchild;
            }
            return root; 
        }

        TreeNode<T>* RemoveOne(TreeNode<T> root, const T data){
            if (root == nullptr){
                return nullptr;
            }

            // Find the node with that data 
            if (root->value > data){
                root->left = RemoveOne(root->left, data);
            }
            else if (root->value < data){
                root->right = RemoveOne(root->right, data);
            }
            else{ //The node to delete has been found

                // case of 0 or 1 kid

                if(root->left == nullptr){
                    TreeNode<T>* temp = root->right;
                    delete root; 
                    return temp; 
                }

                else if (root->right == nullptr){
                    TreeNode<T>* temp = root->left; 
                    delete root;
                    return temp; 
                }

                // Case where it has 2 kids
                else {

                    // find successor: the smallest in the right subtree 
                    

 
                }
                
                // find successor 

                // set success data to the current root

                // call delete on the successor starting from the current node
            }

            return root; // this part is the key, where the possible reassignment happens
        }

        bool RemoveAll(const T data);
        
        void PrintTree()
        {
            PrintTree(root_, "", true);
        }
    
};


#endif 