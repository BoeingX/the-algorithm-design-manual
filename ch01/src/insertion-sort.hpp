#pragma once
#include <algorithm>

namespace adm{
    namespace ch01{
        template<typename Container>
        void InsertionSort(Container &v){
            if(v.empty())
                return;
            for(auto i = 1; i < v.size(); i++){
                auto j = i;
                while(j > 0 && v[j] < v[j-1]){
                    std::swap(v[j], v[j-1]);
                    j--;
                }
            }
        }
    }
}
