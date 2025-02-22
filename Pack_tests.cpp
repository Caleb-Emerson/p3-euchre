#include "Pack.hpp"
#include "unit_test_framework.hpp"

#include <iostream>

using namespace std;

// Given test
TEST(test_pack_default_ctor) {
    Pack pack;
    Card first = pack.deal_one();
    ASSERT_EQUAL(NINE, first.get_rank());
    ASSERT_EQUAL(SPADES, first.get_suit());
}

//////////////// MY TESTS ////////////////

// Pack::Pack default tests

// Pack::Pack iostream tests

// Pack::deal_one tests

// Pack::reset tests

// Pack::shuffle tests

// Pack::empty tests

TEST_MAIN()
