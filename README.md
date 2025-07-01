# 🚀 Rocket Avionics Software Simulation

This is a fully simulated avionics software stack for a vertical descent rocket, written in C++. It includes sensor emulation, PID-based flight control, and a simulated actuator system. Physics are modeled using realistic Newtonian equations (F=ma), mass depletion from fuel burn, and drag forces.

## 💡 Project Purpose
To demonstrate avionics and embedded systems principles through simulation, suitable for applications such as:
- Space vehicle descent control
- Avionics verification & validation
- Embedded flight software testing (SIL)

## 📦 Repository Structure
```
rocket-avionics-sim/
├── include/              # Header files for sensors, controller, actuators
├── src/                  # C++ implementations
├── tools/                # Python plotting script
├── build/                # CMake build directory (gitignored)
├── simulation_output.csv # CSV data from simulation
├── CMakeLists.txt        # Build script
├── README.md             # This file
└── .gitignore
```

## ⚙️ Build Instructions
```bash
git clone https://github.com/yourusername/rocket-avionics-sim.git
cd rocket-avionics-sim
mkdir build && cd build
cmake ..
make
./rocket_sim
```

This will generate `simulation_output.csv` containing time, altitude, velocity, and thrust data.

## 📈 Plot Simulation Data
Ensure `matplotlib` is installed:
```bash
pip install matplotlib
```
Run the Python script:
```bash
python3 tools/plot_sim_data.py
```
This will visualize:
- Altitude over time
- Thrust commands over time

## ✨ Features
- Realistic physics: mass loss, thrust-to-force, and drag
- Simulated IMU, GPS, and altimeter with Gaussian noise
- PID flight controller
- Actuator simulation
- CSV telemetry logging
- Python plotting tools

## 🧠 Concepts Demonstrated
- Newtonian dynamics modeling
- C++ modular design
- Sensor noise & failure modeling
- Closed-loop control systems
- Data analysis and visualization
