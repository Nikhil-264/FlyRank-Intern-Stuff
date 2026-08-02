import numpy as np
import matplotlib.pyplot as plt

# Data extracted from the image
temperature = [25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]
voltage_heating = [0, 0.1, 0.2, 0.25, 0.4, 0.6, 0.7, 0.8, 0.9, 1.05, 1.2, 1.45, 1.6, 1.75, 1.85, 2]
voltage_cooling = [0, 0.05, 0.2, 0.3, 0.45, 0.65, 0.75, 0.9, 0.95, 1.15, 1.3, 1.4, 1.6, 1.8, 1.85, 2]
from scipy.interpolate import make_interp_spline

# Generate smooth curves
temp_smooth = np.linspace(min(temperature), max(temperature), 200)

# Interpolation for smooth curve
heating_smooth = make_interp_spline(temperature, voltage_heating, k=3)(temp_smooth)
cooling_smooth = make_interp_spline(temperature, voltage_cooling, k=3)(temp_smooth)

# Plot smooth hysteresis curve
plt.figure(figsize=(8, 6))
plt.plot(temp_smooth, heating_smooth, 'r-', label="Heating")  # Smooth red curve for heating
plt.plot(temp_smooth, cooling_smooth, 'b-', label="Cooling")  # Smooth blue curve for cooling

# Labels and title
plt.xlabel("Temperature (°C)")
plt.ylabel("Voltage (V)")
plt.title("Figure 1 : Hysteresis Curve for Thermocouple")
plt.legend()
plt.grid(True)

# Show plot
plt.show()
