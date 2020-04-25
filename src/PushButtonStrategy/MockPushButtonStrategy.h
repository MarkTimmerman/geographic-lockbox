#ifndef MOCK_PUSH_BUTTON_STRATEGY_H
#define MOCK_PUSH_BUTTON_STRATEGY_H

#include "PushButtonStrategy.h"

class MockPushButtonStrategy : public PushButtonStrategy {
    public:
        MockPushButtonStrategy(bool);
        bool is_pushed();
        bool is_pushed_value;
};

#endif

