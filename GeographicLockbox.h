#ifndef GEOGRAPHIC_LOCKBOX_H
#define GEOGRAPHIC_LOCKBOX_H

#include "Zone.h"
#include <vector>

using namespace std;

class GeographicLockbox {
    public:
        GeographicLockbox(vector<Zone>);

        vector<Zone> zones;

        double is_working();
};

#endif
