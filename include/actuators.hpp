#pragma once

#include "flight_controller.hpp"
#include <iostream>

class ActuatorSystem {
public:
    void apply(const ControlOutput& output);
};