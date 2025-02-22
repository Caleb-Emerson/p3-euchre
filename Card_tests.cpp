#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <iostream>

using namespace std;

// Given test
TEST(test_card_ctor) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(ACE, c.get_rank());
    ASSERT_EQUAL(HEARTS, c.get_suit());
}

//////////////// MY TESTS ////////////////

// Card::Card default tests

// Card::Card specified rank and suit tests

// Card::get_rank tests

// Card::get_suit default tests

// Card::get_suit with trump tests

// Card::is_face_or_ace tests

// Card::is_right_bower tests

// Card::is_left_bower tests

// Card::is_trump tests

// Card operator<< tests

// Card operator>> tests

// Card operator< tests

// Card operator<= tests

// Card operator> tests

// Card operator>= tests

// Card operator== tests

// Card operator!= tests

// Suit suit_next tests

// Card_less no led card tests

// Card_less with led card tests


TEST_MAIN()
