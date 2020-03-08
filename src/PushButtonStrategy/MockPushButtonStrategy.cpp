#include "MockPushButtonStrategy.h"

MockPushButtonStrategy::MockPushButtonStrategy(bool initial_is_pushed_value) {
    is_pushed_value = initial_is_pushed_value;
}

bool MockPushButtonStrategy::is_pushed() {
    return is_pushed_value;
}
