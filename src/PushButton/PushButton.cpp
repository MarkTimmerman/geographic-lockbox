#include "PushButton.h"

#ifdef ARDUINO_ARCH_AVR
    #include "PushButtonStrategy.h"
#else
    #include "../PushButtonStrategy/PushButtonStrategy.h"
#endif

PushButton::PushButton(PushButtonStrategy* initial_strategy) {
    strategy = initial_strategy;
    was_pressed = strategy->is_pushed();
    timestamp_that_press_started = 0;
    minimum_milliseconds_for_short_press = 150;
    minimum_milliseconds_for_long_press = 2000;
}

void PushButton::update_with_timestamp(int current_timestamp) {
    bool was_pressed_and_now_is_not = was_pressed && !strategy->is_pushed();
    bool was_not_pressed_and_now_is = !was_pressed && strategy->is_pushed();

    if (was_not_pressed_and_now_is) {
        handle_start_press(current_timestamp);
    }
    if (was_pressed_and_now_is_not) {
        handle_end_press(current_timestamp);
    }
}

void PushButton::handle_start_press(int current_timestamp) {
    was_pressed = true;
    timestamp_that_press_started = current_timestamp;
}

void PushButton::handle_end_press(int current_timestamp) {
    was_pressed = false;
    int press_duration = current_timestamp - timestamp_that_press_started;
    timestamp_that_press_started = 0;

    if (press_duration < minimum_milliseconds_for_short_press) {
        return;
    }
    if (press_duration < minimum_milliseconds_for_long_press) {
        on_short_press();
    } else {
        on_long_press();
    }
}

