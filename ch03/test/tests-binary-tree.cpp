// tests-factorial.cpp
#include <algorithm>
#include "catch.hpp"

#include "../src/binary-tree.hpp"

TEST_CASE( "constructor" ) {
    
    adm::ch03::BST<int> bst;
    REQUIRE(bst.empty());

}

TEST_CASE( "insert" ) {
    

    std::vector<int> v, v_ref;

    adm::ch03::BST<int> bst;
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

    v = {1, 2, 3, 4, 5};
    bst.clear();
    for(auto n : v)
        bst.insert(n);
    v_ref = {1, 2, 3, 4, 5};
    REQUIRE(bst.depth() == 5);
    REQUIRE(bst.in_order() == v_ref);
    REQUIRE(bst.isBST());
    REQUIRE(!bst.is_balanced());

}

TEST_CASE( "deserialize" ) {
    std::vector<std::string> v = {",", "5,4,7,3,null,2,null,-1,null,9,", "1,null,2,3,"};
    adm::ch03::BinaryTree<int> tree;
    for(auto s : v){
        tree = adm::ch03::BinaryTree<int>(s);
        REQUIRE(tree.serialize() == s);
    }
}
