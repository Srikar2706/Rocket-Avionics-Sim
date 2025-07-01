import matplotlib.pyplot as plt
import csv

TIME = []
ALTITUDE = []
VELOCITY = []
THRUST = []

# Read from CSV output of simulation
with open("../build/simulation_output.csv", newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        TIME.append(int(row['Time']))
        ALTITUDE.append(float(row['Altitude']))
        VELOCITY.append(float(row['Velocity']))
        THRUST.append(float(row['Thrust']))

plt.figure(figsize=(12, 6))

plt.subplot(2, 1, 1)
plt.plot(TIME, ALTITUDE, label="Altitude")
plt.title("Rocket Altitude Over Time")
plt.xlabel("Time (s)")
plt.ylabel("Altitude (m)")
plt.grid(True)
plt.legend()

plt.subplot(2, 1, 2)
plt.plot(TIME, THRUST, label="Thrust", color='orange')
plt.title("Thrust Command Over Time")
plt.xlabel("Time (s)")
plt.ylabel("Thrust")
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()
