// tests-factorial.cpp
#include <vector>
#include <string>
#include "catch.hpp"

#include "../src/selection-sort.hpp"

TEST_CASE( "selection sort of empty vector", "[vector]" ) {

    std::vector<int> v;
    
    adm::ch02::SelectionSort(v);

    REQUIRE(v.empty());

}

TEST_CASE( "selection sort of single element", "[vector]" ) {

    std::vector<int> v = {1};
    
    adm::ch02::SelectionSort(v);

    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == 1);

}

TEST_CASE( "selection sort of first digits of pi", "[vector]" ) {

    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> v_sorted = {1, 1, 2, 3, 4, 5, 6, 9};
    
    adm::ch02::SelectionSort(v);

    REQUIRE(v == v_sorted);

}

TEST_CASE( "selection sort of string", "[vector]" ) {

    std::string s = "SELECTIONSORT";
    std::string s_sorted = "CEEILNOORSSTT";

    adm::ch02::SelectionSort(s);

    REQUIRE(s == s_sorted);

}
