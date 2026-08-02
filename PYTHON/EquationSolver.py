# EQUATION SOLVER
import numpy as np
from scipy.optimize import fsolve

# Given constant a
a = 0.421  # Example value, replace with your actual constant

# Define the equation function to solve
def equation(f, x, a):
    return a * (1 - x) - (a - f) * (1 - f)**2

# List of x values
x_values = [0.0250, 0.1219, 0.2373, 0.3352, 0.4284, 0.5341, 0.6340, 0.7003, 0.7675, 0.8367, 0.8914, 0.9452, 0.9616, 0.9885, 0.9981, 0.9981, 0.9998, 1.0000]  # Replace with your actual x values

# Find the corresponding f values
f_values = [fsolve(equation, 0.5, args=(x, a))[0] for x in x_values]

print("f values for corresponding x values:")
for x, f in zip(x_values, f_values):
    f_formatted = format(f, ".5f")
    R0D0f_formatted = format(f * 1.309524, ".5f")
    print(f"x = {x:.5f}, f = {f_formatted}, R0D0f = {R0D0f_formatted}")
