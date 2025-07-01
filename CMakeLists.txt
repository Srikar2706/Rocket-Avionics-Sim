cmake_minimum_required(VERSION 3.10)
project(rocket_avionics_sim)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(rocket_sim
    src/main.cpp
    src/sensors.cpp
    src/flight_controller.cpp
    src/actuators.cpp
)
