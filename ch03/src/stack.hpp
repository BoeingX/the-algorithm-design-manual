#pragma once
#include "linked-list.hpp"
namespace adm{
    namespace ch03{
        template<typename T>
            class Stack : private LinkedList<T>{
            public:
                using LinkedList<T>::empty;
                using LinkedList<T>::clear;
                void push(const T &val){
                    LinkedList<T>::push_front(val);
                }
                void pop(){
                    LinkedList<T>::pop_front();
                }
                T top(){
                    return LinkedList<T>::front();
                }
            };
    }
}
