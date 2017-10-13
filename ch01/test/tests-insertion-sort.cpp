// tests-factorial.cpp
#include <vector>
#include <string>
#include "catch.hpp"

#include "../src/insertion-sort.hpp"

TEST_CASE( "insertion sort of empty vector", "[vector]" ) {

    std::vector<int> v;
    
    adm::ch01::InsertionSort(v);

    REQUIRE(v.empty());

}

TEST_CASE( "insertion sort of single element", "[vector]" ) {

    std::vector<int> v = {1};
    
    adm::ch01::InsertionSort(v);

    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == 1);

}

TEST_CASE( "insertion sort of first digits of pi", "[vector]" ) {

    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> v_sorted = {1, 1, 2, 3, 4, 5, 6, 9};
    
    adm::ch01::InsertionSort(v);

    REQUIRE(v == v_sorted);

}

TEST_CASE( "insertion sort of string", "[vector]" ) {

    std::string s = "INSERTIONSORT";
    std::string s_sorted = "EIINNOORRSSTT";

    adm::ch01::InsertionSort(s);

    REQUIRE(s == s_sorted);

}
