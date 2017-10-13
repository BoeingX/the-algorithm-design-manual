#pragma once
#include "linked-list.hpp"
namespace adm{
    namespace ch03{
        template<typename T>
            class Queue : private LinkedList<T>{
            public:
                using LinkedList<T>::empty;
                using LinkedList<T>::clear;
                using LinkedList<T>::push_back;
                using LinkedList<T>::pop_front;
                using LinkedList<T>::front;
            };
    }
}
