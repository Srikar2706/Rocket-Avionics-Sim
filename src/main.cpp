#include <iostream>
#include <fstream>
#include <random>
#include "sensors.hpp"
#include "flight_controller.hpp"
#include "actuators.hpp"

int main() {
    IMUSensor imu;
    Altimeter altimeter;
    GPS gps;
    FlightController controller;
    ActuatorSystem actuators;

    std::ofstream logFile("simulation_output.csv");
    logFile << "Time,Altitude,Velocity,Thrust\n";

    std::cout << "Starting Rocket Avionics Simulation...\n";

    double altitude = 1000.0;        // meters
    double velocity = 0.0;           // m/s
    double mass = 1000.0;            // kg
    double fuel_burn_rate = 0.5;     // kg/s per 1 unit thrust
    double dt = 1.0;                 // time step in seconds
    const double g = 9.81;           // m/s^2

    for (int t = 0; t <= 100; ++t) {
        SensorData data = {
            altitude + altimeter.noiseSample(),
            velocity + imu.noiseSample(),
            altitude + gps.noiseSample()
        };

        ControlOutput output = controller.computeControl(data);

        double thrust = output.thrust;                // [0, 100] normalized thrust
        double thrust_force = thrust * 10.0;          // Convert to Newtons
        double fuel_used = fuel_burn_rate * thrust * dt;
        mass = std::max(mass - fuel_used, 100.0);     // Prevent mass < dry mass

        double drag = 0.0025 * velocity * velocity;   // Simple quadratic drag
        double net_force = thrust_force - mass * g - drag;
        double acceleration = net_force / mass;

        velocity += acceleration * dt;
        altitude += velocity * dt;
        altitude = std::max(altitude, 0.0);

        actuators.apply(output);

        logFile << t << "," << altitude << "," << velocity << "," << output.thrust << "\n";

        std::cout << "Time: " << t << "s | Altitude: " << altitude
                  << " | Velocity: " << velocity
                  << " | Thrust: " << output.thrust << std::endl;
    }

    logFile.close();
    std::cout << "Simulation complete. Data saved to simulation_output.csv" << std::endl;
    return 0;
}
