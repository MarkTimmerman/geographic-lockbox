#include "PushButton.h"
#include "../PushButtonStrategy/MockPushButtonStrategy.h"
#include "../../testing/catch.hpp"

int push_button_strategy_global = 0;
void set_push_button_strategy_global_to_0() {
    push_button_strategy_global = 0;
}
void set_push_button_strategy_global_to_1() {
    push_button_strategy_global = 1;
}

TEST_CASE("it calls on_short_press on a short press", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(false);
    PushButton button = PushButton(strategy);
    set_push_button_strategy_global_to_0();
    button.on_short_press = set_push_button_strategy_global_to_1;
    button.minimum_milliseconds_for_long_press = 2000;

    button.update_with_timestamp(0);
    strategy->is_pushed_value = true;
    button.update_with_timestamp(100);
    strategy->is_pushed_value = false;
    button.update_with_timestamp(300);

    REQUIRE(push_button_strategy_global == 1);
}

TEST_CASE("it does not handle a press when the press is not long enough", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(false);
    PushButton button = PushButton(strategy);
    set_push_button_strategy_global_to_0();
    button.on_short_press = set_push_button_strategy_global_to_1;
    button.minimum_milliseconds_for_short_press = 150;
    button.minimum_milliseconds_for_long_press = 2000;

    strategy->is_pushed_value = true;
    button.update_with_timestamp(0);
    strategy->is_pushed_value = false;
    button.update_with_timestamp(100);

    REQUIRE(push_button_strategy_global == 0);
}

TEST_CASE("it does not handle a press when it is not pressed", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(false);
    PushButton button = PushButton(strategy);
    set_push_button_strategy_global_to_0();
    button.on_short_press = set_push_button_strategy_global_to_1;
    button.on_long_press = set_push_button_strategy_global_to_1;
    button.minimum_milliseconds_for_long_press = 2000;

    REQUIRE(push_button_strategy_global == 0);
}

TEST_CASE("it does not handle a press when it is still depressed", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(false);
    PushButton button = PushButton(strategy);
    set_push_button_strategy_global_to_0();
    button.on_short_press = set_push_button_strategy_global_to_1;
    button.on_long_press = set_push_button_strategy_global_to_1;
    button.minimum_milliseconds_for_long_press = 2000;

    button.update_with_timestamp(0);
    strategy->is_pushed_value = true;
    button.update_with_timestamp(100);
    button.update_with_timestamp(200);

    REQUIRE(push_button_strategy_global == 0);
}

TEST_CASE("it calls on_long_press on a long press", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(false);
    PushButton button = PushButton(strategy);
    set_push_button_strategy_global_to_0();
    button.on_long_press = set_push_button_strategy_global_to_1;
    button.minimum_milliseconds_for_long_press = 2000;

    button.update_with_timestamp(0);
    strategy->is_pushed_value = true;
    button.update_with_timestamp(3000);
    strategy->is_pushed_value = false;
    button.update_with_timestamp(5000);

    REQUIRE(push_button_strategy_global == 1);
}

TEST_CASE("it can call on_short_press and on_long_press back to back", "[PushButton]") {
    MockPushButtonStrategy* strategy = new MockPushButtonStrategy(false);
    PushButton button = PushButton(strategy);
    set_push_button_strategy_global_to_0();
    button.on_short_press = set_push_button_strategy_global_to_0;
    button.on_long_press = set_push_button_strategy_global_to_1;
    button.minimum_milliseconds_for_long_press = 2000;

    REQUIRE(push_button_strategy_global == 0);
    strategy->is_pushed_value = true;
    button.update_with_timestamp(0);
    strategy->is_pushed_value = false;
    button.update_with_timestamp(3000);
    REQUIRE(push_button_strategy_global == 1);
    strategy->is_pushed_value = true;
    button.update_with_timestamp(6000);
    strategy->is_pushed_value = false;
    button.update_with_timestamp(9000);
    REQUIRE(push_button_strategy_global == 1);
    strategy->is_pushed_value = true;
    button.update_with_timestamp(9100);
    strategy->is_pushed_value = false;
    button.update_with_timestamp(9500);
    REQUIRE(push_button_strategy_global == 0);
}

