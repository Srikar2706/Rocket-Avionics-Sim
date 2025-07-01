import csv
import matplotlib.pyplot as plt

# Read CSV data
time = []
altitude = []
velocity_y = []
position_x = []
velocity_x = []
thrust = []

with open("../build/simulation_output.csv", newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        time.append(float(row["Time"]))
        altitude.append(float(row["Altitude"]))
        velocity_y.append(float(row["VelocityY"]))
        position_x.append(float(row["PositionX"]))
        velocity_x.append(float(row["VelocityX"]))
        thrust.append(float(row["Thrust"]))

# Plot Altitude vs Time
plt.figure(figsize=(10, 6))
plt.subplot(2, 1, 1)
plt.plot(time, altitude, label="Altitude (m)")
plt.xlabel("Time (s)")
plt.ylabel("Altitude (m)")
plt.grid(True)
plt.legend()

# Plot VelocityX and VelocityY vs Time
plt.subplot(2, 1, 2)
plt.plot(time, velocity_y, label="Vertical Velocity (m/s)")
plt.plot(time, velocity_x, label="Horizontal Velocity (m/s)")
plt.xlabel("Time (s)")
plt.ylabel("Velocity (m/s)")
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.suptitle("Rocket Avionics Simulation (2D)", y=1.02)
plt.show()
