#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#ifdef ARDUINO_ARCH_AVR
    #include "PushButtonStrategy.h"
#else
    #include "../PushButtonStrategy/PushButtonStrategy.h"
#endif

class PushButton {
    public:
        PushButton(PushButtonStrategy*);
        void update_with_timestamp(int);
        int minimum_milliseconds_for_short_press;
        int minimum_milliseconds_for_long_press;
        void (*on_short_press)();
        void (*on_long_press)();
    private:
        PushButtonStrategy* strategy;
        bool was_pressed;
        int timestamp_that_press_started;
        void handle_start_press(int);
        void handle_end_press(int);
};

#endif
