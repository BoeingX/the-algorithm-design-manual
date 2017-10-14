#pragma once
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
namespace adm{
    namespace ch03{
        template<typename T>
            struct TreeNode {
                T val;
                TreeNode *left, *right;
                TreeNode(const T &val): val(val), left(nullptr), right(nullptr){}
                ~TreeNode(){
                    if(left)
                        delete left;
                    if(right)
                        delete right;
                }
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
                TreeNode<T> *deserialize(const std::string &data){
                    if(data.size() == 1){
                        return nullptr;
                    }
                    std::queue<std::string> children;
                    std::queue<TreeNode<T> *> nodes;
                    std::string s;
                    for(size_t l = 0, r = 0; r < data.size(); r++){
                        if(data[r] == ','){
                            auto s = data.substr(l, r - l);
                            children.push(s);
                            l = r + 1;
                        }
                    }
                    TreeNode<T> *root = new TreeNode<T>(std::stoi(children.front()));
                    nodes.push(root);
                    children.pop();
                    while(!nodes.empty()){
                        TreeNode<T> *t = nodes.front();
                        nodes.pop();
                        if(!children.empty()){
                            s = children.front();
                            children.pop();
                            if(s != "null"){
                                t->left = new TreeNode<T>(std::stoi(s));
                                nodes.push(t->left);
                            }
                        }
                        if(!children.empty()){
                            s = children.front();
                            children.pop();
                            if(s != "null"){
                                t->right = new TreeNode<T>(std::stoi(s));
                                nodes.push(t->right);
                            }
                        }
                    }
                    return root;
                }
            public:
                BinaryTree(): root_(nullptr){}
                BinaryTree(const std::string &data){
                    root_ = deserialize(data); 
                }
                BinaryTree(const BinaryTree<T> &tree){
                    std::string s = tree.serialize();
                    root_ = deserialize(s); 
                }
                BinaryTree& operator= (const BinaryTree &tree){
                    std::string s = tree.serialize();
                    root_ = deserialize(s); 
                    return *this;
                }
                ~BinaryTree(){
                    clear();
                }
                void clear(){
                    if(!root_)
                        return;
                    delete root_;
                    root_ = nullptr;
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
                std::string serialize() const {
                    if(!root_)
                        return ",";
                    std::string s;
                    std::queue<TreeNode<T> *> q, q2;
                    size_t n_nodes = 0, n_nodes2 = 0;
                    q.push(root_);
                    n_nodes = 1;
                    while(!q.empty()){
                        TreeNode<T> *t = q.front();
                        q.pop();
                        if(t){
                            n_nodes--;
                            s += std::to_string(t->val) + ",";
                            if(t->left)
                                n_nodes2++;
                            q2.push(t->left);
                            if(t->right)
                                n_nodes2++;
                            q2.push(t->right);
                        }
                        else{
                            if(n_nodes || n_nodes2)
                                s += "null,";
                        }
                        if(q.empty()){
                            std::swap(q, q2);
                            std::swap(n_nodes, n_nodes2);
                        }
                    }
                    return s;
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
