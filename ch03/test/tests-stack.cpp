// tests-factorial.cpp
#include <vector>
#include <algorithm>
#include "catch.hpp"

#include "../src/stack.hpp"

TEST_CASE( "constructor" ) {

    adm::ch03::Stack<int> stack;

    REQUIRE(stack.empty());

}


TEST_CASE( "push" ) {
    
    adm::ch03::Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    REQUIRE(stack.top() == 3);
    stack.pop();
    stack.pop();
    stack.push(4);
    REQUIRE(stack.top() == 4);
    stack.pop();
    stack.pop();
    REQUIRE(stack.empty());

}
