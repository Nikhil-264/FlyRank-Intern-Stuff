import math

# Antoine equation constants for n-Pentane and n-Hexane
antoine_constants = {
    "n_pentane": {"A": 6.85221, "B": 1064.63, "C": 232},
    "n_hexane": {"A": 6.87776, "B": 1171.53, "C": 224.366}
}

# Total pressure (mmHg)
P_total = 740

# Mole fractions in liquid phase (for bubble point calculation)
x_pentane = 0.5
x_hexane = 0.5

# Mole fractions in vapor phase (for dew point calculation)
y_pentane = 0.7
y_hexane = 0.3

def calculate_vapor_pressure(A, B, C, T):
    """Calculate vapor pressure using Antoine equation (T in °C, P in mmHg)."""
    return 10 ** (A - (B / (T + C)))

from scipy.optimize import fsolve

# Define functions for bubble and dew point calculations

def bubble_point_function(T):
    """Function to find bubble point temperature."""
    # Calculate vapor pressures at temperature T
    P_sat_pentane = calculate_vapor_pressure(
        antoine_constants["n_pentane"]["A"],
        antoine_constants["n_pentane"]["B"],
        antoine_constants["n_pentane"]["C"],
        T
    )
    P_sat_hexane = calculate_vapor_pressure(
        antoine_constants["n_hexane"]["A"],
        antoine_constants["n_hexane"]["B"],
        antoine_constants["n_hexane"]["C"],
        T
    )
    # Bubble point equation: P_total = x1 * Psat1 + x2 * Psat2
    return x_pentane * P_sat_pentane + x_hexane * P_sat_hexane - P_total

def dew_point_function(T):
    """Function to find dew point temperature."""
    # Calculate vapor pressures at temperature T
    P_sat_pentane = calculate_vapor_pressure(
        antoine_constants["n_pentane"]["A"],
        antoine_constants["n_pentane"]["B"],
        antoine_constants["n_pentane"]["C"],
        T
    )
    P_sat_hexane = calculate_vapor_pressure(
        antoine_constants["n_hexane"]["A"],
        antoine_constants["n_hexane"]["B"],
        antoine_constants["n_hexane"]["C"],
        T
    )
    # Dew point equation: 1 / P_total = y1 / Psat1 + y2 / Psat2
    return 1 / (y_pentane / P_sat_pentane + y_hexane / P_sat_hexane) - P_total

# Solve for bubble and dew point temperatures
bubble_point = fsolve(bubble_point_function, 30)[0]  # Initial guess of 30°C
dew_point = fsolve(dew_point_function, 30)[0]       # Initial guess of 30°C

bubble_point, dew_point
print(bubble_point)
print(dew_point)

# Define the selected operating temperature (midpoint of bubble and dew point)
T_selected = (bubble_point + dew_point) / 2  # °C

# Calculate vapor pressures at the selected temperature
P_sat_pentane_selected = calculate_vapor_pressure(
    antoine_constants["n_pentane"]["A"],
    antoine_constants["n_pentane"]["B"],
    antoine_constants["n_pentane"]["C"],
    T_selected
)

P_sat_hexane_selected = calculate_vapor_pressure(
    antoine_constants["n_hexane"]["A"],
    antoine_constants["n_hexane"]["B"],
    antoine_constants["n_hexane"]["C"],
    T_selected
)

# Calculate optimized drum pressure using Raoult's law
P_drum_optimized = x_pentane * P_sat_pentane_selected + x_hexane * P_sat_hexane_selected

# Outputs: selected temperature, vapor pressures, and optimized drum pressure
T_selected, P_sat_pentane_selected, P_sat_hexane_selected, P_drum_optimized

print(T_selected)
print(P_sat_pentane_selected)
print(P_sat_hexane_selected)
print(P_drum_optimized)