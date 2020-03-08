#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include "../PushButtonStrategy/PushButtonStrategy.h"

class PushButton {
    public:
        PushButton(PushButtonStrategy*);
        bool is_pushed();
    private:
        PushButtonStrategy* strategy;
};

#endif
