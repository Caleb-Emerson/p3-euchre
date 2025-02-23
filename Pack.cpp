#include <cassert>
#include <iostream>
#include <array>
#include "Pack.hpp"

// EFFECTS: Initializes the Pack to be in the following standard order:
//          the card of the lowest suit arranged from lowest rank to highest
//          rank, followed by the cards of the next lowest suit in order from
//          lowest to highest rank, and so on.
// NOTE: The standard order is the same as that in pack.in.
// NOTE: Do NOT use pack.in in your implementation of this function
// NOTE: The pack is initially full, with no cards dealt.
Pack::Pack() 
  : next(0) {
  for (int i = 0; i < PACK_SIZE; ++i) {
    cards.at(i) = Card(static_cast<Rank>((i % 6) + 7),
                  static_cast<Suit>(i / 6));
  }
}

// REQUIRES: pack_input contains a representation of a Pack in the format
//           required by the project specification
// MODIFIES: pack_input
// EFFECTS: Initializes Pack by reading from pack_input.
// NOTE: The pack is initially full, with no cards dealt.
Pack::Pack(std::istream& pack_input)
  : next(0) {
  for ( ; !empty(); ++next) {
    pack_input >> cards.at(next);
  }

  reset();
}

// REQUIRES: cards remain in the Pack
// EFFECTS: Returns the next card in the pack and increments the next index
Card Pack::deal_one() {
  return cards.at(next++);
}

// EFFECTS: Resets next index to first card in the Pack
void Pack::reset() {
  next = 0;
}

// EFFECTS: Shuffles the Pack and resets the next index. This performs an in
//          shuffle seven times. See https://en.wikipedia.org/wiki/In_shuffle.
void Pack::shuffle() {
  // In-Shuffle 7 times
  for (int shuffle_num = 0; shuffle_num < 7; ++shuffle_num) {
    int half = PACK_SIZE / 2;
    std::array<Card, PACK_SIZE> temp;

    int top_index = 0;
    int bot_index = half;
    for (int i = 0; i < PACK_SIZE; ++i) {
      if (i % 2 == 0) {
        temp.at(i) = cards.at(bot_index++);
      } else {
        temp.at(i) = cards.at(top_index++);
      }
    }

    cards = temp;
  }
}

// EFFECTS: returns true if there are no more cards left in the pack
bool Pack::empty() const {
  return next == PACK_SIZE;
}
