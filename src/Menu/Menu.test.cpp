#include "Menu.h"
#include "../MenuOption/MenuOption.h"
#include "../../testing/catch.hpp"

int global_count = 0;
void set_global_count_to_0() {
    global_count = 0;
};
void set_global_count_to_1() {
    global_count = 1;
};
void set_global_count_to_2() {
    global_count = 2;
};

TEST_CASE("can build Menu from options and number of options", "[Menu]") {
    MenuOption options[1] = { MenuOption( (uint8_t[4]) { 1, 2, 3, 4}, set_global_count_to_0) };

    REQUIRE_NOTHROW(Menu(options, 1));
}

TEST_CASE("can get the current menu option", "[Menu]") {
    MenuOption options[1] = { MenuOption( (uint8_t[4]) { 1, 2, 3, 4}, set_global_count_to_0) };

    Menu menu = Menu(options, 1);
    MenuOption currentOption = menu.get_current_option();

    REQUIRE(currentOption.digit_values[0] == options[0].digit_values[0]);
}

TEST_CASE("can cycle through the menu options", "[Menu]") {
    MenuOption options[2] = {
        MenuOption( (uint8_t[4]) { 1, 1, 1, 1}, set_global_count_to_1),
        MenuOption( (uint8_t[4]) { 2, 2, 2, 2}, set_global_count_to_2)
    };

    Menu menu = Menu(options, 2);

    menu.next_option();
    REQUIRE(menu.get_current_option().digit_values[0] == 2);

    menu.next_option();
    REQUIRE(menu.get_current_option().digit_values[0] == 1);
}

TEST_CASE("can select the current option", "[Menu]") {
    MenuOption options[2] = {
        MenuOption( (uint8_t[4]) { 1, 1, 1, 1}, set_global_count_to_1),
        MenuOption( (uint8_t[4]) { 2, 2, 2, 2}, set_global_count_to_2)
    };

    Menu menu = Menu(options, 2);
    REQUIRE(global_count == 0);
    menu.select_current_option();

    REQUIRE(global_count == 1);
}

TEST_CASE("can perform a simulated menu experience", "[Menu]") {
    MenuOption options[3] = {
        MenuOption( (uint8_t[4]) { 0, 0, 0, 0}, set_global_count_to_0),
        MenuOption( (uint8_t[4]) { 1, 1, 1, 1}, set_global_count_to_1),
        MenuOption( (uint8_t[4]) { 2, 2, 2, 2}, set_global_count_to_2)
    };
    Menu menu = Menu(options, 3);
    
    menu.select_current_option();
    REQUIRE(global_count == 0);
    REQUIRE(menu.get_current_option().digit_values[0] == 0);
    menu.next_option();
    menu.next_option();
    menu.select_current_option();
    REQUIRE(menu.get_current_option().digit_values[2] == 2);
    REQUIRE(global_count == 2);
    menu.next_option();
    menu.next_option();
    menu.select_current_option();
    REQUIRE(menu.get_current_option().digit_values[1] == 1);
    REQUIRE(global_count == 1);
}

