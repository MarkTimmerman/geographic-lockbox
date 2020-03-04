#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "GeographicLockbox.h"
#include "Zone.h"

int main(int argc, char* argv[]) {
    vector<Zone> zones {
        Zone::build_from_latitude_longitude_and_radius(42.359285, -71.068276, 0.015),
        Zone::build_from_latitude_longitude_and_radius(42.354927, -71.091457, 0.030),
        Zone::build_from_latitude_longitude_and_radius(42.369772, -71.112643, 0.010),
        Zone::build_from_latitude_longitude_and_radius(42.352732, -71.110063, 0.004)
    };
    GeographicLockbox lockbox = GeographicLockbox(zones);

    cout << fixed;
    cout << setprecision(6);

    for (auto&& currentZone: lockbox.zones) {
        cout << "(";
        cout << currentZone.coordinates.latitude;
        cout << ", ";
        cout << currentZone.coordinates.longitude;
        cout << ", ";
        cout << currentZone.radius;
        cout << ")" << endl;
    }

    printf("%f\n", lockbox.is_working());

    return 0;
}
