#include <cassert>
#include <iostream>
#include <array>
#include "Player.hpp"

Player * Player_factory(const std::string &name, const std::string &strategy) {
  if (strategy == "Simple") {
    return new SimplePlayer(name);
  }

  if (strategy == "Human") {

  }

  assert(false);
  return nullptr;
}

std::ostream & operator<<(std::ostream &os, const Player &p) {
  assert(false);
}

class SimplePlayer : public Player {
public:
  // EFFECTS constructs a SimplePlayer
  SimplePlayer(std::string name_in)
    : name(name_in) {}

  // EFFECTS returns player's name
  const std::string & get_name() const{
    assert(false);
  }  

  // REQUIRES player has less than MAX_HAND_SIZE cards
  // EFFECTS adds Card c to Player's hand
  void add_card(const Card &c) {
    assert(false);
  }

  // REQUIRES round is 1 or 2
  // MODIFIES order_up_suit
  // EFFECTS If Player wishes to order up a trump suit then return true and
  // change order_up_suit to desired suit. If player wishes to pass, then do not
  // modify order_up_suit and return false.
  bool make_trump(const Card &upcard, bool is_dealer,
                  int round, Suit &order_up_suit) const {
    assert(false);
  }

  // REQUIRES Player has at least one card
  // EFFECTS Player adds one card to hand and removes one card from hand.
  void add_and_discard(const Card &upcard) {
    assert(false);
  }

  // REQUIRES Player has at least one card
  // EFFECTS Player adds one card to hand and removes one card from hand.
  void add_and_discard(const Card &upcard) {
    assert(false);
  }

  // REQUIRES Player has at least one card
  // EFFECTS Leads one card from Player's hand according to their strategy
  //     "Lead" means to play the first Card in a trick. The card is removed
  //     from the player's hand.
  Card lead_card(Suit trump) {
    assert(false);
  }

  // REQUIRES Player has at least one card
  // EFFECTS Plays one Card from Player's hand according to their strategy.
  //    The card is removed from the player's hand.
  Card play_card(const Card &led_card, Suit trump) {
    assert(false);
  }

  private:
  std::string name;
};

class HumanPlayer : public Player {
  public:
    // EFFECTS constructs a SimplePlayer
    HumanPlayer(std::string name_in)
      : name(name_in) {}
  
    // EFFECTS returns player's name
    const std::string & get_name() const{
      assert(false);
    }  
  
    // REQUIRES player has less than MAX_HAND_SIZE cards
    // EFFECTS adds Card c to Player's hand
    void add_card(const Card &c) {
      assert(false);
    }
  
    // REQUIRES round is 1 or 2
    // MODIFIES order_up_suit
    // EFFECTS If Player wishes to order up a trump suit then return true and
    // change order_up_suit to desired suit. If player wishes to pass, then do not
    // modify order_up_suit and return false.
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, Suit &order_up_suit) const {
      assert(false);
    }
  
    // REQUIRES Player has at least one card
    // EFFECTS Player adds one card to hand and removes one card from hand.
    void add_and_discard(const Card &upcard) {
      assert(false);
    }
  
    // REQUIRES Player has at least one card
    // EFFECTS Player adds one card to hand and removes one card from hand.
    void add_and_discard(const Card &upcard) {
      assert(false);
    }
  
    // REQUIRES Player has at least one card
    // EFFECTS Leads one card from Player's hand according to their strategy
    //     "Lead" means to play the first Card in a trick. The card is removed
    //     from the player's hand.
    Card lead_card(Suit trump) {
      assert(false);
    }
  
    // REQUIRES Player has at least one card
    // EFFECTS Plays one Card from Player's hand according to their strategy.
    //    The card is removed from the player's hand.
    Card play_card(const Card &led_card, Suit trump) {
      assert(false);
    }
  
    private:
    std::string name;
  };
