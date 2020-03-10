#include <iostream>
#include <vector>
using namespace std;

#include "Coordinates/Coordinates.h"
#include "GeographicLock/GeographicLock.h"
#include "CurrentLocationStrategy/MockCurrentLocationStrategy.h"
#include "Zone/Zone.h"

#include "PushButton/PushButton.h"
#include "PushButtonStrategy/MockPushButtonStrategy.h"

GeographicLock* build_lock() {
    vector<Zone> zones {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030),
        Zone(42.369772, -71.112643, 0.010),
        Zone(42.352732, -71.110063, 0.004)
    };

    Coordinates currentLocation = Coordinates(42.359285, -71.068276);
    MockCurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(currentLocation);
    GeographicLock* lock = new GeographicLock(currentLocationStrategy);
    lock->set_zones(zones);

    return lock;
}

void get_and_print_state(GeographicLock* lock) {
    GeographicLockState state = lock->get_state();

    printf("Distance to Next Zone: %f\n", state.miles_to_next_zone);
    printf("%d of %d Zones Visited\n", state.number_of_zones_visited, state.total_number_of_zones);
}

int main(int argc, char* argv[]) {
    GeographicLock* lock = build_lock();

    MockPushButtonStrategy* push_button_strategy = new MockPushButtonStrategy(true);
    PushButton button = PushButton(push_button_strategy);

    if (button.is_pushed()) {
        get_and_print_state(lock);
    }

    return 0;
}
