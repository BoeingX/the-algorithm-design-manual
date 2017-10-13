#pragma once
#include <algorithm>
namespace adm{
    namespace ch02{
        template<typename Container>
        void SelectionSort(Container &v){
            for(auto it = v.begin(); it != v.end(); ++it){
                auto it2 = std::min_element(it, v.end());
                std::swap(*it, *it2);
            }
        }
    }
}
