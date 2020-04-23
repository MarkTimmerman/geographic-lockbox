#ifndef MENU_H
#define MENU_H

#ifdef ARDUINO_ARCH_AVR
    #include "MenuOption.h"
#else
    #include "../MenuOption/MenuOption.h"
#endif

class Menu {
    public:
        Menu(MenuOption*, int);
        MenuOption get_current_option();
        void next_option();
        void select_current_option();
    private:
        MenuOption* options;
        int number_of_options;
        int current_option_index;
};

#endif

