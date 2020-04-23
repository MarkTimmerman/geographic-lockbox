#include "MenuOption.h"
#include "../../testing/catch.hpp"

bool is_global_value_true = false;
void set_is_global_value_to_true() {
    is_global_value_true = true;
};

TEST_CASE("can build MenuOption from digit_values and on_select", "[MenuOption]") {
    uint8_t expected_digit_values[4] = {1, 2, 3, 4};
    MenuOption menu_option = MenuOption(expected_digit_values, set_is_global_value_to_true);

    REQUIRE(menu_option.digit_values[0] == expected_digit_values[0]);
    REQUIRE(menu_option.digit_values[1] == expected_digit_values[1]);
    REQUIRE(menu_option.digit_values[2] == expected_digit_values[2]);
    REQUIRE(menu_option.digit_values[3] == expected_digit_values[3]);
    REQUIRE(menu_option.on_select == &set_is_global_value_to_true);
}

TEST_CASE("can call MenuOption.on_select", "[MenuOption]") {
    uint8_t digit_values[4] = {1, 2, 3, 4};
    MenuOption menu_option = MenuOption(digit_values, set_is_global_value_to_true);

    REQUIRE(is_global_value_true == false);
    menu_option.on_select();

    REQUIRE(is_global_value_true == true);
}
