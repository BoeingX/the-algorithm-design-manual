// tests-factorial.cpp
#include <deque>
#include <algorithm>
#include "catch.hpp"

#include "../src/linked-list.hpp"

TEST_CASE( "constructor" ) {

    adm::ch03::LinkedList<int> lst;

    REQUIRE(lst.empty());

}

TEST_CASE( "push back" ) {

    std::deque<int> v = {1, 2, 3, 4, 5};

    adm::ch03::LinkedList<int> lst;
    
    for(auto n : v)
        lst.push_back(n);

    REQUIRE(v == lst.to_deque());

}


TEST_CASE( "push front" ) {

    std::deque<int> v = {1, 2, 3, 4, 5};

    adm::ch03::LinkedList<int> lst;
    
    for(auto n : v)
        lst.push_front(n);

    std::reverse(v.begin(), v.end());

    REQUIRE(v == lst.to_deque());

}


TEST_CASE( "pop front" ) {

    std::deque<int> v = {1, 2, 3, 4, 5};

    adm::ch03::LinkedList<int> lst;
    
    for(auto n : v)
        lst.push_back(n);

    for(auto i = 0; i < 3 && i < v.size(); i++){
        lst.pop_front();
        v.pop_front();
    }

    REQUIRE(v == lst.to_deque());

}


TEST_CASE( "erase" ) {

    std::deque<int> v, v_ref;

    adm::ch03::LinkedList<int> lst;

    v = {1, 2, 3, 4, 5};
    lst.clear();
    for(auto n : v)
        lst.push_back(n);
    lst.erase(1);
    v_ref = {2, 3, 4, 5};
    REQUIRE(v_ref == lst.to_deque());
    
    v = {1, 2, 3, 4, 5};
    lst.clear();
    for(auto n : v)
        lst.push_back(n);
    lst.erase(5);
    v_ref = {1, 2, 3, 4};
    REQUIRE(v_ref == lst.to_deque());

    v = {1, 1, 1, 1, 1};
    lst.clear();
    for(auto n : v)
        lst.push_back(n);
    lst.erase(1);
    REQUIRE(lst.empty());

    v = {1, 1, 1, 1, 1};
    lst.clear();
    for(auto n : v)
        lst.push_back(n);
    lst.erase(2);
    REQUIRE(lst.to_deque() == v);

    v = {1, 2, 3, 4, 5};
    lst.clear();
    for(auto n : v)
        lst.push_back(n);
    lst.erase(5);
    lst.push_back(6);
    v_ref = {1, 2, 3, 4, 6};
    REQUIRE(lst.to_deque() == v_ref);

    v = {1};
    lst.clear();
    for(auto n : v)
        lst.push_back(n);
    lst.erase(1);
    lst.push_back(2);
    v_ref = {2};
    REQUIRE(lst.to_deque() == v_ref);

}
