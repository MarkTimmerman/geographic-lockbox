#include "MenuOption.h"
#include <stdint.h>

MenuOption::MenuOption(
    uint8_t* initial_digit_values,
    void (*initial_on_select)()
) {
    digit_values = initial_digit_values;
    on_select = initial_on_select;
}
