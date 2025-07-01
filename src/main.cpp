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
     logFile << "Time,Altitude,VelocityY,PositionX,VelocityX,Thrust\n";

    std::cout << "Starting Rocket Avionics Simulation (2D)...\n";

    double altitude = 1000.0;        // Y-axis position in meters
    double velocityY = 0.0;          // Vertical velocity (m/s)
    double positionX = 0.0;          // Horizontal position in meters
    double velocityX = 0.0;          // Horizontal velocity (m/s)
    double angle = 90.0;             // Angle in degrees (90 = up)
    double mass = 1000.0;            // kg
    double fuel_burn_rate = 0.5;     // kg/s per 1 unit thrust
    double dt = 1.0;                 // time step in seconds
    const double g = 9.81;           // m/s^2

    for (int t = 0; t <= 100; ++t) {
        SensorData data = {
            altitude + altimeter.noiseSample(),
            velocityY + imu.noiseSample(),
            altitude + gps.noiseSample()
        };

        ControlOutput output = controller.computeControl(data);

        double thrust = output.thrust;                // [0, 100] normalized thrust
        double thrust_force = thrust * 10.0;          // Convert to Newtons
        double fuel_used = fuel_burn_rate * thrust * dt;
        mass = std::max(mass - fuel_used, 100.0);     // Prevent mass < dry mass

        
        double angle_rad = angle * M_PI / 180.0;
        double thrustX = thrust_force * std::cos(angle_rad);
        double thrustY = thrust_force * std::sin(angle_rad);

        double dragY = 0.0025 * velocityY * velocityY;
        double dragX = 0.0025 * velocityX * velocityX;

        double net_forceY = thrustY - (mass * g) - dragY;
        double net_forceX = thrustX - dragX;

        double accelY = net_forceY / mass;
        double accelX = net_forceX / mass;

        velocityY += accelY * dt;
        velocityX += accelX * dt;

        altitude += velocityY * dt;
        positionX += velocityX * dt;

        altitude = std::max(altitude, 0.0);

        actuators.apply(output);

        logFile << t << "," << altitude << "," << velocityY << "," << positionX << "," << velocityX << "," << thrust << "\n";

        std::cout << "Time: " << t << "s | Altitude: " << altitude
                  << " | VY: " << velocityY << " | PX: " << positionX
                  << " | VX: " << velocityX << " | Thrust: " << thrust << std::endl;
    }

    logFile.close();
    std::cout << "Simulation complete. Data saved to simulation_output.csv" << std::endl;
    return 0;
}
