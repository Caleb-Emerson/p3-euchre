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

// Test Card::Card() and Card::Card(rank, suit) for each possible input
TEST(test_card_default_ctor) {
    Card two_spades = Card();
    ASSERT_EQUAL(two_spades.get_rank(), TWO);
    ASSERT_EQUAL(two_spades.get_suit(), SPADES);

    // Iterate through ranks
    for (int i = 0; i < 13; ++i) {
        Rank rank;

        // Assign each rank
        switch(i) {
            case 0:
                rank = TWO;
                break;
            case 1:
                rank = THREE;
                break;
            case 2:
                rank = FOUR;
                break;
            case 3:
                rank = FIVE;
                break;
            case 4:
                rank = SIX;
                break;
            case 5:
                rank = SEVEN;
                break;
            case 6:
                rank = EIGHT;
                break;
            case 7:
                rank = NINE;
                break;
            case 8:
                rank = TEN;
                break;
            case 9:
                rank = JACK;
                break;
            case 10:
                rank = QUEEN;
                break;
            case 11:
                rank = KING;
                break;
            case 12:
                rank = ACE;
                break;
        }

        // Iterate through Suits
        for (int j = 0; j < 4; ++j) {
            Suit suit;

            // Assign each suit
            switch(j) {
                case 0:
                    suit = SPADES;
                    break;
                case 1:
                    suit = HEARTS;
                    break;
                case 2:
                    suit = CLUBS;
                    break;
                case 3:
                    suit = DIAMONDS;
                    break;
            }

            // Check that ctor works correctly for this card
            Card this_card = Card(rank, suit);
            ASSERT_EQUAL(this_card.get_rank(), rank);
            ASSERT_EQUAL(this_card.get_suit(), suit);
        }
    }
}

// Tests Card::get_rank for TWO, THREE, TEN, JACK, QUEEN, KING, and ACE
TEST(test_get_rank) {
    Card two_spades = Card(TWO, SPADES);
    ASSERT_EQUAL(two_spades.get_rank(), TWO);

    Card three_diamonds = Card(THREE, DIAMONDS);
    ASSERT_EQUAL(three_diamonds.get_rank(), THREE);

    Card ten_clubs = Card(TEN, CLUBS);
    ASSERT_EQUAL(ten_clubs.get_rank(), TEN);

    Card jack_hearts = Card(JACK, HEARTS);
    ASSERT_EQUAL(jack_hearts.get_rank(), JACK);

    Card queen_spades = Card(QUEEN, SPADES);
    ASSERT_EQUAL(queen_spades.get_rank(), QUEEN);

    Card king_diamonds = Card(KING, DIAMONDS);
    ASSERT_EQUAL(king_diamonds.get_rank(), KING);

    Card ace_clubs = Card(ACE, CLUBS);
    ASSERT_EQUAL(ace_clubs.get_rank(), ACE);
}

// Test Card::get_suit basic once for all ranks, and test extensively for tens,
// each face card, and aces
TEST(test_get_suit_basic) {
    Card two_spades = Card(TWO, SPADES);
    ASSERT_EQUAL(two_spades.get_suit(), SPADES);

    Card three_clubs = Card(THREE, CLUBS);
    ASSERT_EQUAL(three_clubs.get_suit(), CLUBS);

    Card four_hearts = Card(FOUR, HEARTS);
    ASSERT_EQUAL(four_hearts.get_suit(), HEARTS);

    Card five_diamonds = Card(FIVE, DIAMONDS);
    ASSERT_EQUAL(five_diamonds.get_suit(), DIAMONDS);

    Card six_spades = Card(SIX, SPADES);
    ASSERT_EQUAL(six_spades.get_suit(), SPADES);

    Card seven_clubs = Card(SEVEN, CLUBS);
    ASSERT_EQUAL(seven_clubs.get_suit(), CLUBS);

    Card eight_hearts = Card(EIGHT, HEARTS);
    ASSERT_EQUAL(eight_hearts.get_suit(), HEARTS);

    Card nine_diamonds = Card(NINE, DIAMONDS);
    ASSERT_EQUAL(nine_diamonds.get_suit(), DIAMONDS);

    // TEN
    Card ten_spades = Card(TEN, SPADES);
    ASSERT_EQUAL(ten_spades.get_suit(), SPADES);

    Card ten_clubs = Card(TEN, CLUBS);
    ASSERT_EQUAL(ten_clubs.get_suit(), CLUBS);

    Card ten_hearts = Card(TEN, HEARTS);
    ASSERT_EQUAL(ten_hearts.get_suit(), HEARTS);

    Card ten_diamonds = Card(TEN, DIAMONDS);
    ASSERT_EQUAL(ten_diamonds.get_suit(), DIAMONDS);

    // JACK
    Card jack_spades = Card(JACK, SPADES);
    ASSERT_EQUAL(jack_spades.get_suit(), SPADES);

    Card jack_clubs = Card(JACK, CLUBS);
    ASSERT_EQUAL(jack_clubs.get_suit(), CLUBS);

    Card jack_hearts = Card(JACK, HEARTS);
    ASSERT_EQUAL(jack_hearts.get_suit(), HEARTS);

    Card jack_diamonds = Card(JACK, DIAMONDS);
    ASSERT_EQUAL(jack_diamonds.get_suit(), DIAMONDS);

    // QUEEN
    Card queen_spades = Card(QUEEN, SPADES);
    ASSERT_EQUAL(queen_spades.get_suit(), SPADES);

    Card queen_clubs = Card(QUEEN, CLUBS);
    ASSERT_EQUAL(queen_clubs.get_suit(), CLUBS);

    Card queen_hearts = Card(QUEEN, HEARTS);
    ASSERT_EQUAL(queen_hearts.get_suit(), HEARTS);

    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    ASSERT_EQUAL(queen_diamonds.get_suit(), DIAMONDS);

    // KING
    Card king_spades = Card(KING, SPADES);
    ASSERT_EQUAL(king_spades.get_suit(), SPADES);

    Card king_clubs = Card(KING, CLUBS);
    ASSERT_EQUAL(king_clubs.get_suit(), CLUBS);

    Card king_hearts = Card(KING, HEARTS);
    ASSERT_EQUAL(king_hearts.get_suit(), HEARTS);

    Card king_diamonds = Card(KING, DIAMONDS);
    ASSERT_EQUAL(king_diamonds.get_suit(), DIAMONDS);

    // ACE
    Card ace_spades = Card(ACE, SPADES);
    ASSERT_EQUAL(ace_spades.get_suit(), SPADES);

    Card ace_clubs = Card(ACE, CLUBS);
    ASSERT_EQUAL(ace_clubs.get_suit(), CLUBS);

    Card ace_hearts = Card(ACE, HEARTS);
    ASSERT_EQUAL(ace_hearts.get_suit(), HEARTS);

    Card ace_diamonds = Card(ACE, DIAMONDS);
    ASSERT_EQUAL(ace_diamonds.get_suit(), DIAMONDS);
}

// Test Card::get_suit with trump once for all ranks, and test extensively for
// tens, jacks, queens, and kings, with additional emphasis on the jacks
TEST(test_get_suit_trump) {
    Card two_spades = Card(TWO, SPADES);
    ASSERT_EQUAL(two_spades.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(two_spades.get_suit(CLUBS), SPADES);
    ASSERT_EQUAL(two_spades.get_suit(HEARTS), SPADES);
    ASSERT_EQUAL(two_spades.get_suit(DIAMONDS), SPADES);

    Card three_clubs = Card(THREE, CLUBS);
    ASSERT_EQUAL(three_clubs.get_suit(SPADES), CLUBS);
    ASSERT_EQUAL(three_clubs.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(three_clubs.get_suit(HEARTS), CLUBS);
    ASSERT_EQUAL(three_clubs.get_suit(DIAMONDS), CLUBS);

    Card four_hearts = Card(FOUR, HEARTS);
    ASSERT_EQUAL(four_hearts.get_suit(SPADES), HEARTS);
    ASSERT_EQUAL(four_hearts.get_suit(CLUBS), HEARTS);
    ASSERT_EQUAL(four_hearts.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(four_hearts.get_suit(DIAMONDS), HEARTS);

    Card five_diamonds = Card(FIVE, DIAMONDS);
    ASSERT_EQUAL(five_diamonds.get_suit(SPADES), DIAMONDS);
    ASSERT_EQUAL(five_diamonds.get_suit(CLUBS), DIAMONDS);
    ASSERT_EQUAL(five_diamonds.get_suit(HEARTS), DIAMONDS);
    ASSERT_EQUAL(five_diamonds.get_suit(DIAMONDS), DIAMONDS);

    Card six_spades = Card(SIX, SPADES);
    ASSERT_EQUAL(six_spades.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(six_spades.get_suit(CLUBS), SPADES);
    ASSERT_EQUAL(six_spades.get_suit(HEARTS), SPADES);
    ASSERT_EQUAL(six_spades.get_suit(DIAMONDS), SPADES);

    Card seven_clubs = Card(SEVEN, CLUBS);
    ASSERT_EQUAL(seven_clubs.get_suit(SPADES), CLUBS);
    ASSERT_EQUAL(seven_clubs.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(seven_clubs.get_suit(HEARTS), CLUBS);
    ASSERT_EQUAL(seven_clubs.get_suit(DIAMONDS), CLUBS);

    Card eight_hearts = Card(EIGHT, HEARTS);
    ASSERT_EQUAL(eight_hearts.get_suit(SPADES), HEARTS);
    ASSERT_EQUAL(eight_hearts.get_suit(CLUBS), HEARTS);
    ASSERT_EQUAL(eight_hearts.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(eight_hearts.get_suit(DIAMONDS), HEARTS);

    Card nine_diamonds = Card(NINE, DIAMONDS);
    ASSERT_EQUAL(nine_diamonds.get_suit(SPADES), DIAMONDS);
    ASSERT_EQUAL(nine_diamonds.get_suit(CLUBS), DIAMONDS);
    ASSERT_EQUAL(nine_diamonds.get_suit(HEARTS), DIAMONDS);
    ASSERT_EQUAL(nine_diamonds.get_suit(DIAMONDS), DIAMONDS);

    // TEN
    Card ten_spades = Card(TEN, SPADES);
    ASSERT_EQUAL(ten_spades.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(ten_spades.get_suit(CLUBS), SPADES);
    ASSERT_EQUAL(ten_spades.get_suit(HEARTS), SPADES);
    ASSERT_EQUAL(ten_spades.get_suit(DIAMONDS), SPADES);

    Card ten_clubs = Card(TEN, CLUBS);
    ASSERT_EQUAL(ten_clubs.get_suit(SPADES), CLUBS);
    ASSERT_EQUAL(ten_clubs.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(ten_clubs.get_suit(HEARTS), CLUBS);
    ASSERT_EQUAL(ten_clubs.get_suit(DIAMONDS), CLUBS);

    Card ten_hearts = Card(TEN, HEARTS);
    ASSERT_EQUAL(ten_hearts.get_suit(SPADES), HEARTS);
    ASSERT_EQUAL(ten_hearts.get_suit(CLUBS), HEARTS);
    ASSERT_EQUAL(ten_hearts.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(ten_hearts.get_suit(DIAMONDS), HEARTS);

    Card ten_diamonds = Card(TEN, DIAMONDS);
    ASSERT_EQUAL(ten_diamonds.get_suit(SPADES), DIAMONDS);
    ASSERT_EQUAL(ten_diamonds.get_suit(CLUBS), DIAMONDS);
    ASSERT_EQUAL(ten_diamonds.get_suit(HEARTS), DIAMONDS);
    ASSERT_EQUAL(ten_diamonds.get_suit(DIAMONDS), DIAMONDS);

    // JACK
    Card jack_spades = Card(JACK, SPADES);
    ASSERT_EQUAL(jack_spades.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(jack_spades.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(jack_spades.get_suit(HEARTS), SPADES);
    ASSERT_EQUAL(jack_spades.get_suit(DIAMONDS), SPADES);

    Card jack_clubs = Card(JACK, CLUBS);
    ASSERT_EQUAL(jack_clubs.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(jack_clubs.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(jack_clubs.get_suit(HEARTS), CLUBS);
    ASSERT_EQUAL(jack_clubs.get_suit(DIAMONDS), CLUBS);

    Card jack_hearts = Card(JACK, HEARTS);
    ASSERT_EQUAL(jack_hearts.get_suit(SPADES), HEARTS);
    ASSERT_EQUAL(jack_hearts.get_suit(CLUBS), HEARTS);
    ASSERT_EQUAL(jack_hearts.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(jack_hearts.get_suit(DIAMONDS), DIAMONDS);

    Card jack_diamonds = Card(JACK, DIAMONDS);
    ASSERT_EQUAL(jack_diamonds.get_suit(SPADES), DIAMONDS);
    ASSERT_EQUAL(jack_diamonds.get_suit(CLUBS), DIAMONDS);
    ASSERT_EQUAL(jack_diamonds.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(jack_diamonds.get_suit(DIAMONDS), DIAMONDS);

    // QUEEN
    Card queen_spades = Card(QUEEN, SPADES);
    ASSERT_EQUAL(queen_spades.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(queen_spades.get_suit(CLUBS), SPADES);
    ASSERT_EQUAL(queen_spades.get_suit(HEARTS), SPADES);
    ASSERT_EQUAL(queen_spades.get_suit(DIAMONDS), SPADES);

    Card queen_clubs = Card(QUEEN, CLUBS);
    ASSERT_EQUAL(queen_clubs.get_suit(SPADES), CLUBS);
    ASSERT_EQUAL(queen_clubs.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(queen_clubs.get_suit(HEARTS), CLUBS);
    ASSERT_EQUAL(queen_clubs.get_suit(DIAMONDS), CLUBS);

    Card queen_hearts = Card(QUEEN, HEARTS);
    ASSERT_EQUAL(queen_hearts.get_suit(SPADES), HEARTS);
    ASSERT_EQUAL(queen_hearts.get_suit(CLUBS), HEARTS);
    ASSERT_EQUAL(queen_hearts.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(queen_hearts.get_suit(DIAMONDS), HEARTS);

    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    ASSERT_EQUAL(queen_diamonds.get_suit(SPADES), DIAMONDS);
    ASSERT_EQUAL(queen_diamonds.get_suit(CLUBS), DIAMONDS);
    ASSERT_EQUAL(queen_diamonds.get_suit(HEARTS), DIAMONDS);
    ASSERT_EQUAL(queen_diamonds.get_suit(DIAMONDS), DIAMONDS);

    // KING
    Card king_spades = Card(KING, SPADES);
    ASSERT_EQUAL(king_spades.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(king_spades.get_suit(CLUBS), SPADES);
    ASSERT_EQUAL(king_spades.get_suit(HEARTS), SPADES);
    ASSERT_EQUAL(king_spades.get_suit(DIAMONDS), SPADES);

    Card king_clubs = Card(KING, CLUBS);
    ASSERT_EQUAL(king_clubs.get_suit(SPADES), CLUBS);
    ASSERT_EQUAL(king_clubs.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(king_clubs.get_suit(HEARTS), CLUBS);
    ASSERT_EQUAL(king_clubs.get_suit(DIAMONDS), CLUBS);

    Card king_hearts = Card(KING, HEARTS);
    ASSERT_EQUAL(king_hearts.get_suit(SPADES), HEARTS);
    ASSERT_EQUAL(king_hearts.get_suit(CLUBS), HEARTS);
    ASSERT_EQUAL(king_hearts.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(king_hearts.get_suit(DIAMONDS), HEARTS);

    Card king_diamonds = Card(KING, DIAMONDS);
    ASSERT_EQUAL(king_diamonds.get_suit(SPADES), DIAMONDS);
    ASSERT_EQUAL(king_diamonds.get_suit(CLUBS), DIAMONDS);
    ASSERT_EQUAL(king_diamonds.get_suit(HEARTS), DIAMONDS);
    ASSERT_EQUAL(king_diamonds.get_suit(DIAMONDS), DIAMONDS);

    // ACE
    Card ace_spades = Card(ACE, SPADES);
    ASSERT_EQUAL(ace_spades.get_suit(SPADES), SPADES);
    ASSERT_EQUAL(ace_spades.get_suit(CLUBS), SPADES);
    ASSERT_EQUAL(ace_spades.get_suit(HEARTS), SPADES);
    ASSERT_EQUAL(ace_spades.get_suit(DIAMONDS), SPADES);

    Card ace_clubs = Card(ACE, CLUBS);
    ASSERT_EQUAL(ace_clubs.get_suit(SPADES), CLUBS);
    ASSERT_EQUAL(ace_clubs.get_suit(CLUBS), CLUBS);
    ASSERT_EQUAL(ace_clubs.get_suit(HEARTS), CLUBS);
    ASSERT_EQUAL(ace_clubs.get_suit(DIAMONDS), CLUBS);

    Card ace_hearts = Card(ACE, HEARTS);
    ASSERT_EQUAL(ace_hearts.get_suit(SPADES), HEARTS);
    ASSERT_EQUAL(ace_hearts.get_suit(CLUBS), HEARTS);
    ASSERT_EQUAL(ace_hearts.get_suit(HEARTS), HEARTS);
    ASSERT_EQUAL(ace_hearts.get_suit(DIAMONDS), HEARTS);

    Card ace_diamonds = Card(ACE, DIAMONDS);
    ASSERT_EQUAL(ace_diamonds.get_suit(SPADES), DIAMONDS);
    ASSERT_EQUAL(ace_diamonds.get_suit(CLUBS), DIAMONDS);
    ASSERT_EQUAL(ace_diamonds.get_suit(HEARTS), DIAMONDS);
    ASSERT_EQUAL(ace_diamonds.get_suit(DIAMONDS), DIAMONDS);
}

// Test Card::is_face_or_ace for all 2-9 Cards once and 10, Jack, Queen, King,
// and Ace for each suit
TEST(test_face_or_ace) {
    Card two_spades = Card(TWO, SPADES);
    ASSERT_FALSE(two_spades.is_face_or_ace());

    Card three_clubs = Card(THREE, CLUBS);
    ASSERT_FALSE(three_clubs.is_face_or_ace());

    Card four_hearts = Card(FOUR, HEARTS);
    ASSERT_FALSE(four_hearts.is_face_or_ace());

    Card five_diamonds = Card(FIVE, DIAMONDS);
    ASSERT_FALSE(five_diamonds.is_face_or_ace());

    Card six_spades = Card(SIX, SPADES);
    ASSERT_FALSE(six_spades.is_face_or_ace());

    Card seven_clubs = Card(SEVEN, CLUBS);
    ASSERT_FALSE(seven_clubs.is_face_or_ace());

    Card eight_hearts = Card(EIGHT, HEARTS);
    ASSERT_FALSE(eight_hearts.is_face_or_ace());

    Card nine_diamonds = Card(NINE, DIAMONDS);
    ASSERT_FALSE(nine_diamonds.is_face_or_ace());

    // TEN
    Card ten_spades = Card(TEN, SPADES);
    ASSERT_FALSE(ten_spades.is_face_or_ace());

    Card ten_clubs = Card(TEN, CLUBS);
    ASSERT_FALSE(ten_clubs.is_face_or_ace());
    
    Card ten_hearts = Card(TEN, HEARTS);
    ASSERT_FALSE(ten_hearts.is_face_or_ace());

    Card ten_diamonds = Card(TEN, DIAMONDS);
    ASSERT_FALSE(ten_diamonds.is_face_or_ace());

    // JACK
    Card jack_spades = Card(JACK, SPADES);
    ASSERT_TRUE(jack_spades.is_face_or_ace());

    Card jack_clubs = Card(JACK, CLUBS);
    ASSERT_TRUE(jack_clubs.is_face_or_ace());
    
    Card jack_hearts = Card(JACK, HEARTS);
    ASSERT_TRUE(jack_hearts.is_face_or_ace());

    Card jack_diamonds = Card(JACK, DIAMONDS);
    ASSERT_TRUE(jack_diamonds.is_face_or_ace());

    // QUEEN
    Card queen_spades = Card(QUEEN, SPADES);
    ASSERT_TRUE(queen_spades.is_face_or_ace());

    Card queen_clubs = Card(QUEEN, CLUBS);
    ASSERT_TRUE(queen_clubs.is_face_or_ace());
    
    Card queen_hearts = Card(QUEEN, HEARTS);
    ASSERT_TRUE(queen_hearts.is_face_or_ace());

    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    ASSERT_TRUE(queen_diamonds.is_face_or_ace());

    // KING
    Card king_spades = Card(KING, SPADES);
    ASSERT_TRUE(king_spades.is_face_or_ace());

    Card king_clubs = Card(KING, CLUBS);
    ASSERT_TRUE(king_clubs.is_face_or_ace());
    
    Card king_hearts = Card(KING, HEARTS);
    ASSERT_TRUE(king_hearts.is_face_or_ace());

    Card king_diamonds = Card(KING, DIAMONDS);
    ASSERT_TRUE(king_diamonds.is_face_or_ace());

    // ACE
    Card ace_spades = Card(ACE, SPADES);
    ASSERT_TRUE(ace_spades.is_face_or_ace());

    Card ace_clubs = Card(ACE, CLUBS);
    ASSERT_TRUE(ace_clubs.is_face_or_ace());
    
    Card ace_hearts = Card(ACE, HEARTS);
    ASSERT_TRUE(ace_hearts.is_face_or_ace());

    Card ace_diamonds = Card(ACE, DIAMONDS);
    ASSERT_TRUE(ace_diamonds.is_face_or_ace());
}

// Card::is_right_bower tests TWO, SIX, TEN, QUEEN, KING, ACE as a single suit
// for every trump suit and JACK for every suit and every trump suit
TEST(test_is_right_bower) {
    Card two_spades = Card(TWO, SPADES);
    ASSERT_FALSE(two_spades.is_right_bower(SPADES));
    ASSERT_FALSE(two_spades.is_right_bower(CLUBS));
    ASSERT_FALSE(two_spades.is_right_bower(HEARTS));
    ASSERT_FALSE(two_spades.is_right_bower(DIAMONDS));

    Card six_clubs = Card(SIX, CLUBS);
    ASSERT_FALSE(six_clubs.is_right_bower(SPADES));
    ASSERT_FALSE(six_clubs.is_right_bower(CLUBS));
    ASSERT_FALSE(six_clubs.is_right_bower(HEARTS));
    ASSERT_FALSE(six_clubs.is_right_bower(DIAMONDS));

    Card ten_hearts = Card(TEN, HEARTS);
    ASSERT_FALSE(ten_hearts.is_right_bower(SPADES));
    ASSERT_FALSE(ten_hearts.is_right_bower(CLUBS));
    ASSERT_FALSE(ten_hearts.is_right_bower(HEARTS));
    ASSERT_FALSE(ten_hearts.is_right_bower(DIAMONDS));

    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    ASSERT_FALSE(queen_diamonds.is_right_bower(SPADES));
    ASSERT_FALSE(queen_diamonds.is_right_bower(CLUBS));
    ASSERT_FALSE(queen_diamonds.is_right_bower(HEARTS));
    ASSERT_FALSE(queen_diamonds.is_right_bower(DIAMONDS));

    Card king_spades = Card(KING, SPADES);
    ASSERT_FALSE(king_spades.is_right_bower(SPADES));
    ASSERT_FALSE(king_spades.is_right_bower(CLUBS));
    ASSERT_FALSE(king_spades.is_right_bower(HEARTS));
    ASSERT_FALSE(king_spades.is_right_bower(DIAMONDS));

    Card ace_clubs = Card(ACE, CLUBS);
    ASSERT_FALSE(ace_clubs.is_right_bower(SPADES));
    ASSERT_FALSE(ace_clubs.is_right_bower(CLUBS));
    ASSERT_FALSE(ace_clubs.is_right_bower(HEARTS));
    ASSERT_FALSE(ace_clubs.is_right_bower(DIAMONDS));

    // JACK
    Card jack_spades = Card(JACK, SPADES);
    ASSERT_TRUE(jack_spades.is_right_bower(SPADES));
    ASSERT_FALSE(jack_spades.is_right_bower(CLUBS));
    ASSERT_FALSE(jack_spades.is_right_bower(HEARTS));
    ASSERT_FALSE(jack_spades.is_right_bower(DIAMONDS));

    Card jack_clubs = Card(JACK, CLUBS);
    ASSERT_FALSE(jack_clubs.is_right_bower(SPADES));
    ASSERT_TRUE(jack_clubs.is_right_bower(CLUBS));
    ASSERT_FALSE(jack_clubs.is_right_bower(HEARTS));
    ASSERT_FALSE(jack_clubs.is_right_bower(DIAMONDS));

    Card jack_hearts = Card(JACK, HEARTS);
    ASSERT_FALSE(jack_hearts.is_right_bower(SPADES));
    ASSERT_FALSE(jack_hearts.is_right_bower(CLUBS));
    ASSERT_TRUE(jack_hearts.is_right_bower(HEARTS));
    ASSERT_FALSE(jack_hearts.is_right_bower(DIAMONDS));

    Card jack_diamonds = Card(JACK, DIAMONDS);
    ASSERT_FALSE(jack_diamonds.is_right_bower(SPADES));
    ASSERT_FALSE(jack_diamonds.is_right_bower(CLUBS));
    ASSERT_FALSE(jack_diamonds.is_right_bower(HEARTS));
    ASSERT_TRUE(jack_diamonds.is_right_bower(DIAMONDS));
}

// Card::is_left_bower tests TWO, SIX, TEN, QUEEN, KING, ACE as a single suit
// for every trump suit and JACK for every suit and every trump suit
TEST(test_is_left_bower) {
    Card two_spades = Card(TWO, SPADES);
    ASSERT_FALSE(two_spades.is_left_bower(SPADES));
    ASSERT_FALSE(two_spades.is_left_bower(CLUBS));
    ASSERT_FALSE(two_spades.is_left_bower(HEARTS));
    ASSERT_FALSE(two_spades.is_left_bower(DIAMONDS));

    Card six_clubs = Card(SIX, CLUBS);
    ASSERT_FALSE(six_clubs.is_left_bower(SPADES));
    ASSERT_FALSE(six_clubs.is_left_bower(CLUBS));
    ASSERT_FALSE(six_clubs.is_left_bower(HEARTS));
    ASSERT_FALSE(six_clubs.is_left_bower(DIAMONDS));

    Card ten_hearts = Card(TEN, HEARTS);
    ASSERT_FALSE(ten_hearts.is_left_bower(SPADES));
    ASSERT_FALSE(ten_hearts.is_left_bower(CLUBS));
    ASSERT_FALSE(ten_hearts.is_left_bower(HEARTS));
    ASSERT_FALSE(ten_hearts.is_left_bower(DIAMONDS));

    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    ASSERT_FALSE(queen_diamonds.is_left_bower(SPADES));
    ASSERT_FALSE(queen_diamonds.is_left_bower(CLUBS));
    ASSERT_FALSE(queen_diamonds.is_left_bower(HEARTS));
    ASSERT_FALSE(queen_diamonds.is_left_bower(DIAMONDS));

    Card king_spades = Card(KING, SPADES);
    ASSERT_FALSE(king_spades.is_left_bower(SPADES));
    ASSERT_FALSE(king_spades.is_left_bower(CLUBS));
    ASSERT_FALSE(king_spades.is_left_bower(HEARTS));
    ASSERT_FALSE(king_spades.is_left_bower(DIAMONDS));

    Card ace_clubs = Card(ACE, CLUBS);
    ASSERT_FALSE(ace_clubs.is_left_bower(SPADES));
    ASSERT_FALSE(ace_clubs.is_left_bower(CLUBS));
    ASSERT_FALSE(ace_clubs.is_left_bower(HEARTS));
    ASSERT_FALSE(ace_clubs.is_left_bower(DIAMONDS));

    // JACK
    Card jack_spades = Card(JACK, SPADES);
    ASSERT_FALSE(jack_spades.is_left_bower(SPADES));
    ASSERT_TRUE(jack_spades.is_left_bower(CLUBS));
    ASSERT_FALSE(jack_spades.is_left_bower(HEARTS));
    ASSERT_FALSE(jack_spades.is_left_bower(DIAMONDS));

    Card jack_clubs = Card(JACK, CLUBS);
    ASSERT_TRUE(jack_clubs.is_left_bower(SPADES));
    ASSERT_FALSE(jack_clubs.is_left_bower(CLUBS));
    ASSERT_FALSE(jack_clubs.is_left_bower(HEARTS));
    ASSERT_FALSE(jack_clubs.is_left_bower(DIAMONDS));

    Card jack_hearts = Card(JACK, HEARTS);
    ASSERT_FALSE(jack_hearts.is_left_bower(SPADES));
    ASSERT_FALSE(jack_hearts.is_left_bower(CLUBS));
    ASSERT_FALSE(jack_hearts.is_left_bower(HEARTS));
    ASSERT_TRUE(jack_hearts.is_left_bower(DIAMONDS));

    Card jack_diamonds = Card(JACK, DIAMONDS);
    ASSERT_FALSE(jack_diamonds.is_left_bower(SPADES));
    ASSERT_FALSE(jack_diamonds.is_left_bower(CLUBS));
    ASSERT_TRUE(jack_diamonds.is_left_bower(HEARTS));
    ASSERT_FALSE(jack_diamonds.is_left_bower(DIAMONDS));
}

// Card::is_trump tests TWO, SIX, TEN, QUEEN, KING, ACE as a single suit for
// every trump suit and JACK for every suit and every trump suit
TEST(test_is_trump) {
    Card two_spades = Card(TWO, SPADES);
    ASSERT_TRUE(two_spades.is_trump(SPADES));
    ASSERT_FALSE(two_spades.is_trump(CLUBS));
    ASSERT_FALSE(two_spades.is_trump(HEARTS));
    ASSERT_FALSE(two_spades.is_trump(DIAMONDS));

    Card six_clubs = Card(SIX, CLUBS);
    ASSERT_FALSE(six_clubs.is_trump(SPADES));
    ASSERT_TRUE(six_clubs.is_trump(CLUBS));
    ASSERT_FALSE(six_clubs.is_trump(HEARTS));
    ASSERT_FALSE(six_clubs.is_trump(DIAMONDS));

    Card ten_hearts = Card(TEN, HEARTS);
    ASSERT_FALSE(ten_hearts.is_trump(SPADES));
    ASSERT_FALSE(ten_hearts.is_trump(CLUBS));
    ASSERT_TRUE(ten_hearts.is_trump(HEARTS));
    ASSERT_FALSE(ten_hearts.is_trump(DIAMONDS));

    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    ASSERT_FALSE(queen_diamonds.is_trump(SPADES));
    ASSERT_FALSE(queen_diamonds.is_trump(CLUBS));
    ASSERT_FALSE(queen_diamonds.is_trump(HEARTS));
    ASSERT_TRUE(queen_diamonds.is_trump(DIAMONDS));

    Card king_spades = Card(KING, SPADES);
    ASSERT_TRUE(king_spades.is_trump(SPADES));
    ASSERT_FALSE(king_spades.is_trump(CLUBS));
    ASSERT_FALSE(king_spades.is_trump(HEARTS));
    ASSERT_FALSE(king_spades.is_trump(DIAMONDS));

    Card ace_clubs = Card(ACE, CLUBS);
    ASSERT_FALSE(ace_clubs.is_trump(SPADES));
    ASSERT_TRUE(ace_clubs.is_trump(CLUBS));
    ASSERT_FALSE(ace_clubs.is_trump(HEARTS));
    ASSERT_FALSE(ace_clubs.is_trump(DIAMONDS));

    // JACK
    Card jack_spades = Card(JACK, SPADES);
    ASSERT_TRUE(jack_spades.is_trump(SPADES));
    ASSERT_TRUE(jack_spades.is_trump(CLUBS));
    ASSERT_FALSE(jack_spades.is_trump(HEARTS));
    ASSERT_FALSE(jack_spades.is_trump(DIAMONDS));

    Card jack_clubs = Card(JACK, CLUBS);
    ASSERT_TRUE(jack_clubs.is_trump(SPADES));
    ASSERT_TRUE(jack_clubs.is_trump(CLUBS));
    ASSERT_FALSE(jack_clubs.is_trump(HEARTS));
    ASSERT_FALSE(jack_clubs.is_trump(DIAMONDS));

    Card jack_hearts = Card(JACK, HEARTS);
    ASSERT_FALSE(jack_hearts.is_trump(SPADES));
    ASSERT_FALSE(jack_hearts.is_trump(CLUBS));
    ASSERT_TRUE(jack_hearts.is_trump(HEARTS));
    ASSERT_TRUE(jack_hearts.is_trump(DIAMONDS));

    Card jack_diamonds = Card(JACK, DIAMONDS);
    ASSERT_FALSE(jack_diamonds.is_trump(SPADES));
    ASSERT_FALSE(jack_diamonds.is_trump(CLUBS));
    ASSERT_TRUE(jack_diamonds.is_trump(HEARTS));
    ASSERT_TRUE(jack_diamonds.is_trump(DIAMONDS));
}

// Card operator<< tests TWO, THREE, SIX, TEN, JACK, QUEEN, KING, and ACE for
// each suit
TEST(test_card_insertion_operator) {
    // Define the ostringstream that will be used for string comparison
    ostringstream oss;

    // TWO
    Card two_spades = Card(TWO, SPADES);
    oss << two_spades;
    ASSERT_EQUAL(oss.str(), "Two of Spades");
    oss.str("");

    Card two_clubs = Card(TWO, CLUBS);
    oss << two_clubs;
    ASSERT_EQUAL(oss.str(), "Two of Clubs");
    oss.str("");

    Card two_hearts = Card(TWO, HEARTS);
    oss << two_hearts;
    ASSERT_EQUAL(oss.str(), "Two of Hearts");
    oss.str("");

    Card two_diamonds = Card(TWO, DIAMONDS);
    oss << two_diamonds;
    ASSERT_EQUAL(oss.str(), "Two of Diamonds");
    oss.str("");

    // THREE
    Card three_spades = Card(THREE, SPADES);
    oss << three_spades;
    ASSERT_EQUAL(oss.str(), "Three of Spades");
    oss.str("");

    Card three_clubs = Card(THREE, CLUBS);
    oss << three_clubs;
    ASSERT_EQUAL(oss.str(), "Three of Clubs");
    oss.str("");

    Card three_hearts = Card(THREE, HEARTS);
    oss << three_hearts;
    ASSERT_EQUAL(oss.str(), "Three of Hearts");
    oss.str("");

    Card three_diamonds = Card(THREE, DIAMONDS);
    oss << three_diamonds;
    ASSERT_EQUAL(oss.str(), "Three of Diamonds");
    oss.str("");

    // SIX
    Card six_spades = Card(SIX, SPADES);
    oss << six_spades;
    ASSERT_EQUAL(oss.str(), "Six of Spades");
    oss.str("");

    Card six_clubs = Card(SIX, CLUBS);
    oss << six_clubs;
    ASSERT_EQUAL(oss.str(), "Six of Clubs");
    oss.str("");

    Card six_hearts = Card(SIX, HEARTS);
    oss << six_hearts;
    ASSERT_EQUAL(oss.str(), "Six of Hearts");
    oss.str("");

    Card six_diamonds = Card(SIX, DIAMONDS);
    oss << six_diamonds;
    ASSERT_EQUAL(oss.str(), "Six of Diamonds");
    oss.str("");

    // TEN
    Card ten_spades = Card(TEN, SPADES);
    oss << ten_spades;
    ASSERT_EQUAL(oss.str(), "Ten of Spades");
    oss.str("");

    Card ten_clubs = Card(TEN, CLUBS);
    oss << ten_clubs;
    ASSERT_EQUAL(oss.str(), "Ten of Clubs");
    oss.str("");

    Card ten_hearts = Card(TEN, HEARTS);
    oss << ten_hearts;
    ASSERT_EQUAL(oss.str(), "Ten of Hearts");
    oss.str("");

    Card ten_diamonds = Card(TEN, DIAMONDS);
    oss << ten_diamonds;
    ASSERT_EQUAL(oss.str(), "Ten of Diamonds");
    oss.str("");

    // JACK
    Card jack_spades = Card(JACK, SPADES);
    oss << jack_spades;
    ASSERT_EQUAL(oss.str(), "Jack of Spades");
    oss.str("");

    Card jack_clubs = Card(JACK, CLUBS);
    oss << jack_clubs;
    ASSERT_EQUAL(oss.str(), "Jack of Clubs");
    oss.str("");

    Card jack_hearts = Card(JACK, HEARTS);
    oss << jack_hearts;
    ASSERT_EQUAL(oss.str(), "Jack of Hearts");
    oss.str("");

    Card jack_diamonds = Card(JACK, DIAMONDS);
    oss << jack_diamonds;
    ASSERT_EQUAL(oss.str(), "Jack of Diamonds");
    oss.str("");

    // QUEEN
    Card queen_spades = Card(QUEEN, SPADES);
    oss << queen_spades;
    ASSERT_EQUAL(oss.str(), "Queen of Spades");
    oss.str("");

    Card queen_clubs = Card(QUEEN, CLUBS);
    oss << queen_clubs;
    ASSERT_EQUAL(oss.str(), "Queen of Clubs");
    oss.str("");

    Card queen_hearts = Card(QUEEN, HEARTS);
    oss << queen_hearts;
    ASSERT_EQUAL(oss.str(), "Queen of Hearts");
    oss.str("");

    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    oss << queen_diamonds;
    ASSERT_EQUAL(oss.str(), "Queen of Diamonds");
    oss.str("");

    // KING
    Card king_spades = Card(KING, SPADES);
    oss << king_spades;
    ASSERT_EQUAL(oss.str(), "King of Spades");
    oss.str("");

    Card king_clubs = Card(KING, CLUBS);
    oss << king_clubs;
    ASSERT_EQUAL(oss.str(), "King of Clubs");
    oss.str("");

    Card king_hearts = Card(KING, HEARTS);
    oss << king_hearts;
    ASSERT_EQUAL(oss.str(), "King of Hearts");
    oss.str("");

    Card king_diamonds = Card(KING, DIAMONDS);
    oss << king_diamonds;
    ASSERT_EQUAL(oss.str(), "King of Diamonds");
    oss.str("");

    // ACE
    Card ace_spades = Card(ACE, SPADES);
    oss << ace_spades;
    ASSERT_EQUAL(oss.str(), "Ace of Spades");
    oss.str("");

    Card ace_clubs = Card(ACE, CLUBS);
    oss << ace_clubs;
    ASSERT_EQUAL(oss.str(), "Ace of Clubs");
    oss.str("");

    Card ace_hearts = Card(ACE, HEARTS);
    oss << ace_hearts;
    ASSERT_EQUAL(oss.str(), "Ace of Hearts");
    oss.str("");

    Card ace_diamonds = Card(ACE, DIAMONDS);
    oss << ace_diamonds;
    ASSERT_EQUAL(oss.str(), "Ace of Diamonds");
    oss.str("");
}

// Card operator>> tests TWO, THREE, SIX, TEN, JACK, QUEEN, KING, and ACE for
// alternating suits
TEST(test_card_extraction_operator) {
    istringstream iss_two("Two of Spades");
    Card two_spades;
    iss_two >> two_spades;
    ASSERT_EQUAL(two_spades, Card(TWO, SPADES));

    istringstream iss_three("Three of Clubs");
    Card three_clubs;
    iss_three >> three_clubs;
    ASSERT_EQUAL(three_clubs, Card(THREE, CLUBS));

    istringstream iss_six("Six of Hearts");
    Card six_hearts;
    iss_six >> six_hearts;
    ASSERT_EQUAL(six_hearts, Card(SIX, HEARTS));

    istringstream iss_ten("Ten of Diamonds");
    Card ten_diamonds;
    iss_ten >> ten_diamonds;
    ASSERT_EQUAL(ten_diamonds, Card(TEN, DIAMONDS));

    istringstream iss_jack("Jack of Spades");
    Card jack_spades;
    iss_jack >> jack_spades;
    ASSERT_EQUAL(jack_spades, Card(JACK, SPADES));

    istringstream iss_queen("Queen of Clubs");
    Card queen_clubs;
    iss_queen >> queen_clubs;
    ASSERT_EQUAL(queen_clubs, Card(QUEEN, CLUBS));

    istringstream iss_king("King of Hearts");
    Card king_hearts;
    iss_king >> king_hearts;
    ASSERT_EQUAL(king_hearts, Card(KING, HEARTS));

    istringstream iss_ace("Ace of Diamonds");
    Card ace_diamonds;
    iss_ace >> ace_diamonds;
    ASSERT_EQUAL(ace_diamonds, Card(ACE, DIAMONDS))
}

// Tests comparison between two unequal cards
TEST(test_card_comparison_basic) {
    Card five_spades = Card(FIVE, SPADES);
    Card nine_hearts = Card(NINE, HEARTS);

    ASSERT_TRUE(five_spades < nine_hearts);
    ASSERT_TRUE(five_spades <= nine_hearts);
    ASSERT_FALSE(five_spades > nine_hearts);
    ASSERT_FALSE(five_spades >= nine_hearts);
    ASSERT_FALSE(five_spades == nine_hearts);
    ASSERT_TRUE(five_spades != nine_hearts);
}

// Tests comparison between a face card and a number card
TEST(test_card_comparison_face_normal) {
    Card queen_spades = Card(QUEEN, SPADES);
    Card nine_hearts = Card(NINE, HEARTS);

    ASSERT_FALSE(queen_spades < nine_hearts);
    ASSERT_FALSE(queen_spades <= nine_hearts);
    ASSERT_TRUE(queen_spades > nine_hearts);
    ASSERT_TRUE(queen_spades >= nine_hearts);
    ASSERT_FALSE(queen_spades == nine_hearts);
    ASSERT_TRUE(queen_spades != nine_hearts);
}

// Tests comparison between an ace and a face card
TEST(test_card_comparison_ace_face) {
    Card ace_spades = Card(ACE, SPADES);
    Card queen_hearts = Card(QUEEN, HEARTS);

    ASSERT_FALSE(ace_spades < queen_hearts);
    ASSERT_FALSE(ace_spades <= queen_hearts);
    ASSERT_TRUE(ace_spades > queen_hearts);
    ASSERT_TRUE(ace_spades >= queen_hearts);
    ASSERT_FALSE(ace_spades == queen_hearts);
    ASSERT_TRUE(ace_spades != queen_hearts);
}

// Tests comparison between an ace and a number card
TEST(test_card_comparison_ace_number) {
    Card ace_spades = Card(ACE, SPADES);
    Card five_diamonds = Card(FIVE, DIAMONDS);

    ASSERT_FALSE(ace_spades < five_diamonds);
    ASSERT_FALSE(ace_spades <= five_diamonds);
    ASSERT_TRUE(ace_spades > five_diamonds);
    ASSERT_TRUE(ace_spades >= five_diamonds);
    ASSERT_FALSE(ace_spades == five_diamonds);
    ASSERT_TRUE(ace_spades != five_diamonds);
}

// Tests comparison between two cards of the same rank but different suits
TEST(test_card_comparison_same_rank_diff_suit) {
    Card five_hearts = Card(FIVE, HEARTS);
    Card five_clubs = Card(FIVE, CLUBS);

    ASSERT_FALSE(five_hearts < five_clubs);
    ASSERT_FALSE(five_hearts <= five_clubs);
    ASSERT_FALSE(five_hearts > five_clubs);
    ASSERT_FALSE(five_hearts >= five_clubs);
    ASSERT_FALSE(five_hearts == five_clubs);
    ASSERT_TRUE(five_hearts != five_clubs);
}

// Suit_next tests for all suits
TEST(test_suit_next_basic) {
    ASSERT_EQUAL(Suit_next(SPADES), CLUBS);
    ASSERT_EQUAL(Suit_next(CLUBS), SPADES);
    ASSERT_EQUAL(Suit_next(HEARTS), DIAMONDS);
    ASSERT_EQUAL(Suit_next(DIAMONDS), HEARTS);
}

// Card_less both cards are trump, standard order
TEST(test_card_less_both_trump) {
    Card ten_spades = Card(TEN, SPADES);
    Card king_spades = Card(KING, SPADES);
    Suit trump = SPADES;

    ASSERT_TRUE(Card_less(ten_spades, king_spades, trump));
}

// Card_less ensures right bower trumps ace within trump suit
TEST(test_card_less_bower_non_bower) {
    Card ace_hearts = Card(ACE, HEARTS);
    Card jack_hearts = Card(JACK, HEARTS);
    Suit trump = HEARTS;

    ASSERT_TRUE(Card_less(ace_hearts, jack_hearts, trump));
}

// Card_less ensures left bower less than right bower within trump suit
TEST(test_card_less_both_bowers) {
    Card jack_diamonds = Card(JACK, DIAMONDS);
    Card jack_hearts = Card(JACK, HEARTS);
    Suit trump = HEARTS;

    ASSERT_TRUE(Card_less(jack_diamonds, jack_hearts, trump));
}

// Card_less ensures trump supremacy over non-trump
TEST(test_card_less_trump_non_trump) {
    Card nine_clubs = Card(NINE, CLUBS);
    Card ace_spades = Card(ACE, SPADES);
    Suit trump = CLUBS;

    ASSERT_FALSE(Card_less(nine_clubs, ace_spades, trump));
}

// Card_less rank comparison when neither card is trump
TEST(test_card_less_neither_trump) {
    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    Card king_diamonds = Card(KING, DIAMONDS);
    Suit trump = SPADES;

    ASSERT_TRUE(Card_less(queen_diamonds, king_diamonds, trump));
}

// Card_less ensures same rank in different suits results in false
TEST(test_card_less_equal) {
    Card ace_hearts = Card(ACE, HEARTS);
    Card ace_diamonds = Card(ACE, DIAMONDS);
    Suit trump = CLUBS;

    ASSERT_FALSE(Card_less(ace_hearts, ace_diamonds, trump));
}

// Card_less ensures left bower trumps its normal suit
TEST(test_card_less_left_bower_normal_suit) {
    Card jack_clubs = Card(JACK, CLUBS);
    Card ace_clubs = Card(ACE, CLUBS);
    Suit trump = SPADES;

    ASSERT_FALSE(Card_less(jack_clubs, ace_clubs, trump));
}

// Card_less with led card both follow, no trump
TEST(test_card_less_led_both_follow) {
    Card ten_hearts = Card(TEN, HEARTS);
    Card queen_hearts = Card(QUEEN, HEARTS);
    Card king_hearts = Card(KING, HEARTS);
    Suit trump = SPADES;

    ASSERT_TRUE(Card_less(ten_hearts, queen_hearts, king_hearts, trump));
}

// Card_less with led card trump vs. led suit
TEST(test_card_less_led_trump_vs_led) {
    Card nine_clubs = Card(NINE, CLUBS);
    Card ace_hearts = Card(ACE, HEARTS);
    Card king_hearts = Card(KING, HEARTS);
    Suit trump = CLUBS;

    ASSERT_FALSE(Card_less(nine_clubs, ace_hearts, king_hearts, trump));
}

// Card_less with led card led suit vs. off-suit
TEST(test_card_less_led_suit_vs_off_suit) {
    Card queen_diamonds = Card(QUEEN, DIAMONDS);
    Card ace_spades = Card(ACE, SPADES);
    Card king_diamonds = Card(KING, DIAMONDS);
    Suit trump = CLUBS;

    ASSERT_FALSE(Card_less(queen_diamonds, ace_spades, king_diamonds, trump));
}

// Card_less with led card left bower vs. led suit
TEST(test_card_less_led_left_bower_vs_normal_led) {
    Card jack_diamonds = Card(JACK, DIAMONDS);
    Card ace_diamonds = Card(ACE, DIAMONDS);
    Card king_diamonds = Card(KING, DIAMONDS);
    Suit trump = HEARTS;

    ASSERT_FALSE(Card_less(jack_diamonds, ace_diamonds, king_diamonds, trump));
}

// Card_less with led card right vs. left bower
TEST(test_card_less_led_right_left_bower) {
    Card jack_clubs = Card(JACK, CLUBS);
    Card jack_spades = Card(JACK, SPADES);
    Card king_hearts = Card(KING, HEARTS);
    Suit trump = SPADES;

    ASSERT_TRUE(Card_less(jack_clubs, jack_spades, king_hearts, trump));
}

// Card_less with led card off-suit vs. off-suit
TEST(test_card_less_led_both_off_suit) {
    Card ten_diamonds = Card(TEN, DIAMONDS);
    Card queen_clubs = Card(QUEEN, CLUBS);
    Card king_hearts = Card(KING, HEARTS);
    Suit trump = SPADES;

    ASSERT_TRUE(Card_less(ten_diamonds, queen_clubs, king_hearts, trump));
}

// Card_less with led card matching trump
TEST(test_card_less_led_suit_matching_trump) {
    Card ten_spades = Card(TEN, SPADES);
    Card queen_spades = Card(QUEEN, SPADES);
    Card nine_spades = Card(NINE, SPADES);
    Suit trump = SPADES;

    ASSERT_TRUE(Card_less(ten_spades, queen_spades, nine_spades, trump));
}

// Card_less with leading trump vs. off-suit
TEST(test_card_less_led_leading_trump_vs_off_suit) {
    Card queen_spades = Card(QUEEN, SPADES);
    Card ace_hearts = Card(ACE, HEARTS);
    Card nine_spades = Card(NINE, SPADES);
    Suit trump = SPADES;

    ASSERT_FALSE(Card_less(queen_spades, ace_hearts, nine_spades, trump));
}

TEST_MAIN()
