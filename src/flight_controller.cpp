#include "flight_controller.hpp"

ControlOutput FlightController::computeControl(const SensorData& data) {
    double error = desiredAltitude - data.altitude;
    double derivative = -data.verticalVelocity;
    double thrust = kp * error + kd * derivative;
    if (thrust < 0) thrust = 0;
    if (thrust > 100) thrust = 100;
    return { thrust };
}
