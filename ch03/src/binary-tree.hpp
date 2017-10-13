#pragma once
#include <cmath>
#include <vector>
#include <stack>
namespace adm{
    namespace ch03{
        template<typename T>
            struct TreeNode {
                T val;
                TreeNode *left, *right;
                TreeNode(const T &val): val(val), left(nullptr), right(nullptr){}
            };
        template<typename T>
            class BinaryTree{
                TreeNode<T> *root_;
                void in_order(TreeNode<T> *root, std::vector<T> &v){
                    if(!root)
                        return;
                    in_order(root->left, v);
                    v.push_back(root->val);
                    in_order(root->right, v);
                }
                void pre_order(TreeNode<T> *root, std::vector<T> &v){
                    if(!root)
                        return;
                    v.push_back(root->val);
                    in_order(root->left, v);
                    in_order(root->right, v);
                }
                void post_order(TreeNode<T> *root, std::vector<T> &v){
                    if(!root)
                        return;
                    in_order(root->left, v);
                    in_order(root->right, v);
                    v.push_back(root->val);
                }
                size_t depth(TreeNode<T> *root){
                    if(!root)
                        return 0;
                    return 1 + std::max(depth(root->left), depth(root->right));
                }
                int is_balanced(TreeNode<T> *root){
                    if(!root)
                        return 0;
                    int d1 = is_balanced(root->left);
                    int d2 = is_balanced(root->right);
                    if(d1 == -1 || d2 == -1 || std::abs(d1 - d2) > 1)
                        return -1;
                    return 1 + std::max(d1, d2);
                }
            public:
                BinaryTree(): root_(nullptr){}
                ~BinaryTree(){
                    clear();
                }
                void set_root(TreeNode<T> *root){
                    root_ = root;
                }
                TreeNode<T> *get_root(){
                    return root_;
                }
                std::vector<T> in_order(){
                    std::vector<T> v;
                    in_order(root_, v);
                    return v;
                }
                std::vector<T> pre_order(){
                    std::vector<T> v;
                    pre_order(root_, v);
                    return v;
                }
                std::vector<T> post_order(){
                    std::vector<T> v;
                    post_order(root_, v);
                    return v;
                }
                bool isBST(){
                    std::vector<T> v = in_order();
                    for(auto i = 0; i + 1 < v.size(); i++)
                        if(v[i] >= v[i+1])
                            return false;
                    return true;
                }
                size_t depth(){
                    return depth(root_);
                }
                bool empty(){
                    return !root_;
                }
                bool is_balanced(){
                    return is_balanced(root_) != -1;
                }
                void clear(){
                    if(!root_)
                        return;
                    std::stack<TreeNode<T> *> to_delete;
                    to_delete.push(root_);
                    while(!to_delete.empty()){
                        TreeNode<T> *node = to_delete.top();
                        to_delete.pop();
                        if(node->left)
                            to_delete.push(node->left);
                        if(node->right)
                            to_delete.push(node->right);
                        delete node;
                        node = nullptr;
                    }
                    // if not set to nullptr, root_ is `dangling pointer`.
                    root_ = nullptr;
                }
            };
        template<typename T>
            class BST : public BinaryTree<T> {
                TreeNode<T> *search(TreeNode<T> *root, const T &val){
                    if(!root)
                        return nullptr;
                    if(root->val == val)
                        return root;
                    if(root->val > val)
                        return search(root->left, val);
                    return search(root->right, val);
                }
                TreeNode<T> *insert(TreeNode<T> *root, const T &val){
                    if(!root)
                        return new TreeNode<T>(val);
                    if(root->val > val)
                        root->left = insert(root->left, val);
                    else if(root->val < val)
                        root->right = insert(root->right, val);
                    return root;
                }
            public:
                TreeNode<T> *search(const T &val){
                    return search(BinaryTree<T>::get_root(), val);
                }
                void insert(const T &val){
                    BinaryTree<T>::set_root(insert(BinaryTree<T>::get_root(), val));
                }
                TreeNode<T> *min_element(){
                    TreeNode<T> *curr = BinaryTree<T>::get_root();
                    while(curr && curr->left)
                        curr = curr->left;
                    return curr;
                }
                TreeNode<T> *max_element(){
                    TreeNode<T> *curr = BinaryTree<T>::get_root();
                    while(curr && curr->right)
                        curr = curr->right;
                    return curr;
                }
            };
    }
}
