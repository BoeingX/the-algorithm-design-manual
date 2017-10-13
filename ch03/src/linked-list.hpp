#pragma once
#include<deque>
namespace adm{
    namespace ch03{
        template<typename T>
            struct ListNode{
                T val;
                ListNode *next;
                ListNode(const T &val): val(val){
                    next = nullptr;
                }
            };

        template<typename T>
            class LinkedList{
                ListNode<T> *head_, *tail_;
            public:
                LinkedList(): head_(nullptr), tail_(nullptr){}
                ~LinkedList(){
                    clear(); 
                }
                bool empty(){
                    return !head_;
                }
                T front(){
                    return head_->val;
                }
                T back(){
                    return tail_->val;
                }
                ListNode<T> *search(const T &val){
                    ListNode<T> *curr = head_;
                    while(curr){
                       if(curr->val == val)
                           return curr;
                    }
                    return nullptr;
                }
                void push_front(const T &val){
                    if(empty()){
                        head_ = new ListNode<T>(val);
                        tail_ = head_;
                        return;
                    }
                    ListNode<T> *new_head = new ListNode<T>(val);
                    new_head->next = head_;
                    head_ = new_head;
                }
                void push_back(const T &val){
                    if(empty()){
                        head_ = new ListNode<T>(val);
                        tail_ = head_;
                        return;
                    }
                    tail_->next = new ListNode<T>(val);
                    tail_ = tail_->next;
                }
                void pop_front(){
                    if(empty())
                        return;
                    ListNode<T> *head = head_;
                    head_ = head_->next;
                    delete head;
                }
                void erase(const T &val){
                    if(empty())
                        return;
                    ListNode<T> *dummy = new ListNode<T>(val);
                    dummy->next = head_;
                    ListNode<T> *prev = dummy, *curr = head_;
                    while(curr){
                        if(curr->val == val){
                            prev->next = curr->next;
                            if(curr == tail_)
                                tail_ = prev;
                            ListNode<T> *to_erase = curr;
                            curr = curr->next;
                            delete to_erase;
                        }
                        else{
                            prev = prev->next;
                            curr = curr->next;
                        }
                    }
                    head_ = dummy->next;
                }
                void clear(){
                    ListNode<T> *curr = head_, *next;
                    while(curr){
                        next = curr->next;
                        delete curr;
                        curr = next;
                    }
                    head_ = nullptr, tail_ = nullptr;
                }
                std::deque<T> to_deque(){
                    std::deque<T> v;
                    ListNode<T> *curr = head_;
                    while(curr){
                        v.push_back(curr->val);
                        curr = curr->next;
                    }
                    return v;
                }
            };
    }
}
