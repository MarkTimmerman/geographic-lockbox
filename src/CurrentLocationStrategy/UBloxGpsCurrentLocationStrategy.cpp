#include "Coordinates.h"
#include "UBloxGpsCurrentLocationStrategy.h"
#include "SparkFun_Ublox_Arduino_Library.h"
#include <Wire.h>

UBloxGpsCurrentLocationStrategy::UBloxGpsCurrentLocationStrategy() {
    Wire.begin();
    gps = new SFE_UBLOX_GPS();
    gps->begin();
}

Coordinates UBloxGpsCurrentLocationStrategy::get() {
    const uint32_t U_BLOX_UNITS = 10000000;
    double latitude = gps->getLatitude() / (double)U_BLOX_UNITS;
    double longitude = gps->getLongitude() / (double)U_BLOX_UNITS;
    return Coordinates(latitude, longitude);
}

bool UBloxGpsCurrentLocationStrategy::can_get_location() {
    return gps->isConnected();
}
