#pragma once

#include <random>

struct SensorData {
    double altitude;
    double verticalVelocity;
    double position;
};

class IMUSensor {
public:
    double read(int t);
    double noiseSample();
private:
    std::default_random_engine gen;
    std::normal_distribution<double> noise{0.0, 0.05};
};

class Altimeter {
public:
    double read(int t);
    double noiseSample();
private:
    std::default_random_engine gen;
    std::normal_distribution<double> noise{0.0, 0.1};
};

class GPS {
public:
    double read(int t);
    double noiseSample();
private:
    std::default_random_engine gen;
    std::normal_distribution<double> noise{0.0, 0.2};
};