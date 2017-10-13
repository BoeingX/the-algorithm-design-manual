// tests-factorial.cpp
#include <algorithm>
#include "catch.hpp"

#include "../src/binary-tree.hpp"

TEST_CASE( "constructor" ) {
    
    adm::ch03::BST<int> bst;
    REQUIRE(bst.empty());

}

TEST_CASE( "insert" ) {
    
    adm::ch03::BST<int> bst;

    std::vector<int> v, v_ref;

    bst.clear();
    v = {3, 2, 1, 4, 5};
    for(auto n : v)
        bst.insert(n);
    v_ref = {1, 2, 3, 4, 5};
    REQUIRE(bst.depth() == 3);
    REQUIRE(bst.in_order() == v_ref);
    REQUIRE(bst.search(1));
    REQUIRE(!bst.search(6));
    REQUIRE(bst.isBST());
    REQUIRE(bst.is_balanced());
    REQUIRE(bst.min_element()->val == 1);
    REQUIRE(bst.max_element()->val == 5);

    bst.clear();
    v = {1, 2, 3, 4, 5};
    for(auto n : v)
        bst.insert(n);
    v_ref = {1, 2, 3, 4, 5};
    REQUIRE(bst.depth() == 5);
    REQUIRE(bst.in_order() == v_ref);
    REQUIRE(bst.isBST());
    REQUIRE(!bst.is_balanced());

}
