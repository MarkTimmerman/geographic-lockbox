#include "PushButton.h"
#include "../PushButtonStrategy/MockPushButtonStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("is_pushed returns false when not pushed", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(false);
    PushButton button = PushButton(strategy);

    bool is_pushed = button.is_pushed();

    REQUIRE(is_pushed == false);
}

TEST_CASE("is_pushed returns true when is pushed", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(true);
    PushButton button = PushButton(strategy);

    bool is_pushed = button.is_pushed();

    REQUIRE(is_pushed == true);
}

