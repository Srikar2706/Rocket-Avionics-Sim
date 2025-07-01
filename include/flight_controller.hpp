#pragma once

#include "sensors.hpp"

struct ControlOutput {
    double thrust;
};

class FlightController {
public:
    ControlOutput computeControl(const SensorData& data);
private:
    double kp = 0.05;
    double kd = 0.1;
    double desiredAltitude = 500.0; // target altitude in meters
};
