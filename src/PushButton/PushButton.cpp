#include "PushButton.h"
#include "../PushButtonStrategy/PushButtonStrategy.h"

PushButton::PushButton(PushButtonStrategy* initial_strategy) {
    strategy = initial_strategy;
}

bool PushButton::is_pushed() {
    return strategy->is_pushed();
}

