#include "Coordinates.h"

void Coordinates::set_latitude(double newLatitude) {
    latitude = newLatitude;
}

void Coordinates::set_longitude(double newLongitude) {
    longitude = newLongitude;
}

double Coordinates::get_latitude() {
    return latitude;
}

double Coordinates::get_longitude() {
    return longitude;
}
