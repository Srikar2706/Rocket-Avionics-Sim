#include "sensors.hpp"
#include <cmath>

static constexpr double g = 9.81;

double IMUSensor::read(int t) {
    double velocity = -g * t + noise(gen);
    return velocity;
}

double IMUSensor::noiseSample() {
    return noise(gen);
}

double Altimeter::read(int t) {
    double altitude = 1000.0 - 0.5 * g * t * t + noise(gen);
    return altitude;
}

double Altimeter::noiseSample() {
    return noise(gen);
}

double GPS::read(int t) {
    double position = 1000.0 - 0.5 * g * t * t + noise(gen);
    return position;
}

double GPS::noiseSample() {
    return noise(gen);
}
