#include "Coordinates.h"
#include <cmath>
using namespace std;

Coordinates::Coordinates() {
    latitude = 0.0;
    longitude = 0.0;
}

Coordinates::Coordinates(double initialLatitude, double initialLongitude) {
    latitude = initialLatitude;
    longitude = initialLongitude;
}

double Coordinates::get_distance_in_miles_from(Coordinates fromCoordinates) {
    double const EARTH_RADIUS_IN_KILOMETERS = 6371;
    double const MILES_PER_KILOMETER = 0.6213711922373338;

    double latitudeDeltaInRadians = degrees_to_radians(fromCoordinates.latitude - latitude);
    double longitudeDeltaInRadians = degrees_to_radians(fromCoordinates.longitude - longitude);

    double toLatitudeInRadians = degrees_to_radians(latitude);
    double fromLatitudeInRadians = degrees_to_radians(fromCoordinates.latitude);

    double squareOfHalfChordLength = pow(sin(latitudeDeltaInRadians / 2), 2)
                                     + pow(sin(longitudeDeltaInRadians / 2), 2)
                                     * cos(toLatitudeInRadians) * cos(fromLatitudeInRadians);
    double angularDistanceInRadians = 2 * atan2(sqrt(squareOfHalfChordLength), sqrt(1 - squareOfHalfChordLength));
    
    double distanceInKilometers = EARTH_RADIUS_IN_KILOMETERS * angularDistanceInRadians;

    return distanceInKilometers * MILES_PER_KILOMETER;
}

double Coordinates::degrees_to_radians(double degrees) {
    return degrees * M_PI / 180;
}

