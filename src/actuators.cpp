#include "actuators.hpp"

void ActuatorSystem::apply(const ControlOutput& output) {
    // For now, just log the thrust
    std::cout << "[Actuators] Applying thrust: " << output.thrust << std::endl;
}