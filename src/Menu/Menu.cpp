#include "Menu.h"

#ifdef ARDUINO_ARCH_AVR
    #include "MenuOption.h"
#else
    #include "../MenuOption/MenuOption.h"
#endif


Menu::Menu(MenuOption* initial_options, int initial_number_of_options) {
    options = initial_options;
    number_of_options = initial_number_of_options;
    current_option_index = 0;
}

MenuOption Menu::get_current_option() {
    return options[current_option_index];
}

void Menu::next_option() {
    current_option_index = (current_option_index + 1) % number_of_options;
}

void Menu::select_current_option() {
    options[current_option_index].on_select();
}

