#ifndef U_BLOX_GPS_CURRENT_LOCATION_STRATEGY_H
#define U_BLOX_GPS_CURRENT_LOCATION_STRATEGY_H

#include "CurrentLocationStrategy.h"
#include "SparkFun_Ublox_Arduino_Library.h"

class UBloxGpsCurrentLocationStrategy : public CurrentLocationStrategy {
    public:
        UBloxGpsCurrentLocationStrategy();
        Coordinates get();
        bool can_get_location();
    private:
        SFE_UBLOX_GPS* gps;
};

#endif

