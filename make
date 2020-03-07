g++ -std=c++11 -Wall -o app \
    src/app.cpp \
    src/Coordinates/Coordinates.cpp \
    src/Zone/Zone.cpp \
    src/CurrentLocationStrategy/CurrentLocationStrategy.cpp \
    src/CurrentLocationStrategy/MockCurrentLocationStrategy.cpp \
    src/GeographicLock/GeographicLock.cpp
