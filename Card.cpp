#include <cassert>
#include <iostream>
#include <array>
#include "Card.hpp"

using namespace std;

/////////////// Rank operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const RANK_NAMES[] = {
  "Two",   // TWO
  "Three", // THREE
  "Four",  // FOUR
  "Five",  // FIVE
  "Six",   // SIX
  "Seven", // SEVEN
  "Eight", // EIGHT
  "Nine",  // NINE
  "Ten",   // TEN
  "Jack",  // JACK
  "Queen", // QUEEN
  "King",  // KING
  "Ace"    // ACE
};

//REQUIRES str represents a valid rank ("Two", "Three", ..., "Ace")
//EFFECTS returns the Rank corresponding to str, for example "Two" -> TWO
Rank string_to_rank(const std::string &str) {
  for(int r = TWO; r <= ACE; ++r) {
    if (str == RANK_NAMES[r]) {
      return static_cast<Rank>(r);
    }
  }
  assert(false); // Input string didn't match any rank
  return {};
}

//EFFECTS Prints Rank to stream, for example "Two"
std::ostream & operator<<(std::ostream &os, Rank rank) {
  os << RANK_NAMES[rank];
  return os;
}

//REQUIRES If any input is read, it must be a valid rank
//EFFECTS Reads a Rank from a stream, for example "Two" -> TWO
std::istream & operator>>(std::istream &is, Rank &rank) {
  string str;
  if(is >> str) {
    rank = string_to_rank(str);
  }
  return is;
}



/////////////// Suit operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const SUIT_NAMES[] = {
  "Spades",   // SPADES
  "Hearts",   // HEARTS
  "Clubs",    // CLUBS
  "Diamonds", // DIAMONDS
};

//REQUIRES str represents a valid suit ("Spades", "Hearts", "Clubs", or "Diamonds")
//EFFECTS returns the Suit corresponding to str, for example "Clubs" -> CLUBS
Suit string_to_suit(const std::string &str) {
  for(int s = SPADES; s <= DIAMONDS; ++s) {
    if (str == SUIT_NAMES[s]) {
      return static_cast<Suit>(s);
    }
  }
  assert(false); // Input string didn't match any suit
  return {};
}

//EFFECTS Prints Suit to stream, for example "Spades"
std::ostream & operator<<(std::ostream &os, Suit suit) {
  os << SUIT_NAMES[suit];
  return os;
}

//REQUIRES If any input is read, it must be a valid suit
//EFFECTS Reads a Suit from a stream, for example "Spades" -> SPADES
std::istream & operator>>(std::istream &is, Suit &suit) {
  string str;
  if (is >> str) {
    suit = string_to_suit(str);
  }
  return is;
}


/////////////// Write your implementation for Card below ///////////////

//EFFECTS Initializes Card to the Two of Spades
Card::Card() {
  assert(false);
}

//EFFECTS Initializes Card to specified rank and suit
Card::Card(Rank rank_in, Suit suit_in) {
  assert(false);
}

//EFFECTS Returns the rank
Rank Card::get_rank() const {
  assert(false);
}

//EFFECTS Returns the suit. Does not consider trump.
Suit Card::get_suit() const {
  assert(false);
}

//EFFECTS Returns the suit
//HINT: the left bower is the trump suit!
Suit Card::get_suit(Suit trump) const {
  assert(false);
}

//EFFECTS Returns true if card is a face card (Jack, Queen, King, or Ace)
bool Card::is_face_or_ace() const {
  assert(false);
}

//EFFECTS Returns true is card is the Jack of the trump suit
bool Card::is_right_bower(Suit trump) const {
  assert(false);
}

//EFFECTS Returns true if card is the Jack of the next suit
bool Card::is_left_bower(Suit trump) const {
  assert(false);
}

//EFFECTS Returns true if the card is a trump card. All cards of the trump suit
// are trump cards. The left bower is also a trump card.
bool Card::is_trump(Suit trump) const {
  assert(false);
}

//EFFECTS Prints Card to stream, for example "Two of Spades"
std::ostream & operator<<(std::ostream &os, const Card &card) {
  assert(false);
}

//EFFECTS Reads a Card from a stream in the format "Two of Spades"
//NOTE The card class declares this operator>> "friend" function, which means it
//     is allowed to access card.rank and card.suit.
std::istream & operator>>(std::istream &is, Card &card) {
  assert(false);
}

//EFFECTS Returns true if lhs is lower value than rhs or the same card as rhs.
//        Does not consider trump.
bool operator<(const Card &lhs, const Card &rhs) {
  assert(false);
}

//EFFECTS Returns true if lhs is lower value than rhs or the same card as rhs.
//        Does not consider trump.
bool operator<=(const Card &lhs, const Card &rhs) {
  assert(false);
}

//EFFECTS Returns true if lhs is higher value than rhs.
//        Does not consider trump.
bool operator>(const Card &lhs, const Card &rhs) {
  assert(false);
}

//EFFECTS Returns true if lhs is higher value than rhs or the same card as rhs.
//        Does not consider trump.
bool operator>=(const Card &lhs, const Card &rhs) {
  assert(false);
}

//EFFECTS Returns true if lhs is same card as rhs.
//        Does not consider trump.
bool operator==(const Card &lhs, const Card &rhs) {
  assert(false);
}

//EFFECTS Returns true if lhs is not the same card as rhs.
//        Does not consider trump.
bool operator!=(const Card &lhs, const Card &rhs) {
  assert(false);
}

//EFFECTS Returns the next suit, which is the suit of the same color
Suit Suit_next(Suit suit) {
  assert(false);
}

//EFFECTS Returns true if a is lower than b. Uses trump to determine order, as
//        described in the spec.
bool Card_less(const Card &a, const Card &b, Suit trump) {
  assert(false);
}

//EFFECTS Returns true is a is lower value than b. Uses both the trump suit and
//        the suit led to determine order, as described in the spec.
bool Card_less (const Card &a, const Card &b,
                const Card &led_card, Suit trump) {
  assert(false);
}