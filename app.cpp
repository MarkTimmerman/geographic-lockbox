#include <iostream>
using namespace std;
#include "GeographicLockbox.h"

int main(int argc, char* argv[]) {
    GeographicLockbox lockbox;
    cout << lockbox.is_working() << endl;

    return 0;
}
