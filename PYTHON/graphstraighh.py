import matplotlib.pyplot as plt
import numpy as np

# Define x and y values
x = np.array([3, 6, 9, 12, 15])
y1 = np.array([9.6, 13.8, 17.9, 21.4, 21.4])
y2 = np.array([9.8, 13.5, 17.3, 21.3, 21.4])  # Fixed syntax error

# Plot both graphs with lines connecting points
plt.plot(x, y1, marker='o', linestyle='-', label='Increasing', color='b')
plt.plot(x, y2, marker='s', linestyle='-', label='Decreasing', color='r')

# Add labels and title
plt.xlabel("Input Pressure(psig)")
plt.ylabel("Output Current(mA)")
plt.title("Figure 4 : Hysteresis of P/I Converter")
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
