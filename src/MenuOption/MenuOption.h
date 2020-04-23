#ifndef MENU_OPTION_H
#define MENU_OPTION_H

#include <stdint.h>

class MenuOption {
    public:
        MenuOption(uint8_t*, void (*)());
        uint8_t* digit_values;
        void (*on_select)();
};

#endif


