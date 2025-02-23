#include "Pack.hpp"
#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

// Given test
TEST(test_pack_default_ctor) {
    Pack pack;
    Card first = pack.deal_one();
    ASSERT_EQUAL(NINE, first.get_rank());
    ASSERT_EQUAL(SPADES, first.get_suit());
}

//////////////// MY TESTS ////////////////

// Pack::Pack default test entire default pack
TEST(test_pack_default_ctor_full) {
    Pack default_pack = Pack();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            // Initialize temporary card to use for comparison
            Card temp_card = default_pack.deal_one();

            // Check for correct suit
            switch (i) {
                case 0:
                    ASSERT_EQUAL(temp_card.get_suit(), SPADES);
                    break;
                case 1:
                    ASSERT_EQUAL(temp_card.get_suit(), HEARTS);
                    break;
                case 2:
                    ASSERT_EQUAL(temp_card.get_suit(), CLUBS);
                    break;
                case 3:
                    ASSERT_EQUAL(temp_card.get_suit(), DIAMONDS);
                    break;
            }

            // Check for correct rank
            switch(j) {
                case 0:
                    ASSERT_EQUAL(temp_card.get_rank(), NINE);
                    break;
                case 1:
                    ASSERT_EQUAL(temp_card.get_rank(), TEN);
                    break;
                case 2:
                    ASSERT_EQUAL(temp_card.get_rank(), JACK);
                    break;
                case 3:
                    ASSERT_EQUAL(temp_card.get_rank(), QUEEN);
                    break;
                case 4:
                    ASSERT_EQUAL(temp_card.get_rank(), KING);
                    break;
                case 5:
                    ASSERT_EQUAL(temp_card.get_rank(), ACE);
                    break;
            }
        }
    }
}

// Pack::Pack iostream tests that pack.in matches default
TEST(test_pack_iostream_ctor_full) {
    const string filename = "pack.in";
    ifstream ifs(filename);
    assert(ifs.is_open());
    Pack io_pack(ifs);
    Pack default_pack = Pack();
    for (int i = 0; i < 24; ++i) {
        ASSERT_EQUAL(io_pack.deal_one(), default_pack.deal_one());
    }
    ifs.close();
}

// Pack::reset tests for when nothing has been dealt and for when all are dealt
TEST(test_pack_reset) {
    Pack default_pack = Pack();
    default_pack.reset();
    ASSERT_EQUAL(default_pack.deal_one(), Card(NINE, SPADES));
    for (int i = 0; i < 22; ++i) {
        default_pack.deal_one();
    }
    default_pack.reset();
    ASSERT_EQUAL(default_pack.deal_one(), Card(NINE, SPADES));
}

// Pack::empty tests
TEST(test_pack_empty) {
    Pack default_pack = Pack();
    ASSERT_FALSE(default_pack.empty());
    default_pack.deal_one();
    ASSERT_FALSE(default_pack.empty());
    for (int i = 0; i < 22; ++i) {
        default_pack.deal_one();
    }
    ASSERT_FALSE(default_pack.empty());
    default_pack.deal_one();
    ASSERT_TRUE(default_pack.empty());
    default_pack.reset();
    ASSERT_FALSE(default_pack.empty());
}

TEST_MAIN()
