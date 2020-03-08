#include "Coordinates.h"

#ifdef ARDUINO_ARCH_AVR
    #include <math.h>
#else
    #include <cmath>
    using namespace std;
#endif

Coordinates::Coordinates() {
    latitude = 0.0;
    longitude = 0.0;
}

Coordinates::Coordinates(double initial_latitude, double initial_longitude) {
    latitude = initial_latitude;
    longitude = initial_longitude;
}

double Coordinates::get_distance_in_miles_from(Coordinates from_coordinates) {
    double const EARTH_RADIUS_IN_KILOMETERS = 6371;
    double const MILES_PER_KILOMETER = 0.6213711922373338;

    double latitude_delta_in_radians = degrees_to_radians(from_coordinates.latitude - latitude);
    double longitude_delta_in_radians = degrees_to_radians(from_coordinates.longitude - longitude);

    double to_latitude_in_radians = degrees_to_radians(latitude);
    double from_latitude_in_radians = degrees_to_radians(from_coordinates.latitude);

    double square_of_half_chord_length = pow(sin(latitude_delta_in_radians / 2), 2)
                                     + pow(sin(longitude_delta_in_radians / 2), 2)
                                     * cos(to_latitude_in_radians) * cos(from_latitude_in_radians);
    double angular_distance_in_radians = 2 * atan2(sqrt(square_of_half_chord_length), sqrt(1 - square_of_half_chord_length));
    
    double distance_in_kilometers = EARTH_RADIUS_IN_KILOMETERS * angular_distance_in_radians;

    return distance_in_kilometers * MILES_PER_KILOMETER;
}

double Coordinates::degrees_to_radians(double degrees) {
    return degrees * M_PI / 180;
}

