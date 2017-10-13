// tests-factorial.cpp
#include <vector>
#include <algorithm>
#include "catch.hpp"

#include "../src/queue.hpp"

TEST_CASE( "constructor" ) {

    adm::ch03::Queue<int> queue;

    REQUIRE(queue.empty());

}


TEST_CASE( "push" ) {
    
    adm::ch03::Queue<int> queue;
    
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
    REQUIRE(queue.front() == 1);
    queue.pop_front();
    queue.pop_front();
    queue.push_back(4);
    REQUIRE(queue.front() == 3);
    queue.pop_front();
    queue.pop_front();
    REQUIRE(queue.empty());

}
