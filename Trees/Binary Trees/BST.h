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


        /*Create a new node based on the data the user wants to pass*/
        bool Insert(T data = {}){
            if (root_ == nullptr){
                root_ = new TreeNode<T>(data);
                size_++;
                return true;
            }

            /*Find the position (parent) it belongs in*/
            TreeNode<T>* current = root_;
            while (true){

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

        // void Traverse(TreeNode<T>* current){
        //     if (current == nullptr){
        //         return;
        //     }

        //     std::cout << current->value << std::endl;
        //     Traverse(current->leftchild);
        //     Traverse(current->rightchild);
        // }

        // void PrintTree(){
        //     TreeNode<T>* current = root_;
        //     Traverse(current);
        // }


        void PrintTree()
        {
            PrintTree(root_, "", true);
        }
    
};


#endif 