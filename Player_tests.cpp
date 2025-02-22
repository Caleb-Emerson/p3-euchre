#include "Player.hpp"
#include "unit_test_framework.hpp"

#include <iostream>

using namespace std;

// Given test
TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

//////////////// MY TESTS ////////////////

TEST_MAIN()
