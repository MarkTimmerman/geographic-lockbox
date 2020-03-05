#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "GeographicLockbox/GeographicLockbox.h"
#include "Zone/Zone.h"

int main(int argc, char* argv[]) {
    vector<Zone> zones {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030),
        Zone(42.369772, -71.112643, 0.010),
        Zone(42.352732, -71.110063, 0.004)
    };

    GeographicLockbox lockbox = GeographicLockbox();
    lockbox.set_zones(zones);
    lockbox.update_state();

    return 0;
}
