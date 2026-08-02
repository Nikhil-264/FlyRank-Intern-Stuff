import numpy as np
import matplotlib.pyplot as plt

# Given data
alpha = 2.5  # Relative volatility (assumed for simplicity)
xD = 0.95    # Distillate composition
xB = 0.05    # Bottom composition
xF = 0.50    # Feed composition

# Minimum reflux ratio (R_min)
R_min = (alpha * xD / (alpha - 1)) - ((1 - xD) / (alpha - 1))

# Define reflux ratios
reflux_ratios = [1.2 * R_min, 2 * R_min, 3 * R_min]

# Generate x values for equilibrium and operating lines
x = np.linspace(0, 1, 1000)  # Higher resolution for x

# Equilibrium line
y_eq = (alpha * x) / (1 + (alpha - 1) * x)

# Plot equilibrium line and operating lines for different reflux ratios
plt.figure(figsize=(10, 6))

# Plot equilibrium line
plt.plot(x, y_eq, label="Equilibrium Line", color="blue", linewidth=2)

# Stages for different reflux ratios
for R in reflux_ratios:
    # Rectifying section operating line
    y_operating = (R / (R + 1)) * x + xD / (R + 1)
    plt.plot(x, y_operating, label=f"Operating Line (R={R:.2f})", linestyle="--")

    # Graphical method for stages (McCabe-Thiele)
    x_stage, y_stage = [xD], [xD]
    x_current, y_current = xD, xD
    iteration_count = 0  # Safeguard against infinite loops
    max_iterations = 100

    while x_current > xB and iteration_count < max_iterations:
        # Step to equilibrium line
        x_next = x[np.argmin(np.abs(y_eq - y_current))]
        if abs(x_current - x_next) < 1e-6:  # Break if there's no progress
            break
        x_stage.append(x_next)
        y_stage.append(y_current)

        # Step to operating line
        y_next = (R / (R + 1)) * x_next + xD / (R + 1)
        x_stage.append(x_next)
        y_stage.append(y_next)

        x_current, y_current = x_next, y_next
        iteration_count += 1

    plt.plot(x_stage, y_stage, marker="o", label=f"Stages (R={R:.2f})")

# Plot y = x line (45-degree line)
plt.plot(x, x, label="y = x (Diagonal)", color="gray", linestyle=":")

# Add labels and legend
plt.xlabel("x (Liquid mole fraction of n-pentane)")
plt.ylabel("y (Vapor mole fraction of n-pentane)")
plt.title("McCabe-Thiele Diagram with Operating Lines and Stages")
plt.legend()
plt.grid()
plt.show()
