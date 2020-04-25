#ifndef PHYSICAL_PUSH_BUTTON_STRATEGY_H
#define PHYSICAL_PUSH_BUTTON_STRATEGY_H

#include "PushButtonStrategy.h"

class PhysicalPushButtonStrategy : public PushButtonStrategy {
    public:
        PhysicalPushButtonStrategy(int, int);
        bool is_pushed();
    private:
        void set_pin_modes();
        int momentary_switch_pin;
        int led_pin;
};

#endif


