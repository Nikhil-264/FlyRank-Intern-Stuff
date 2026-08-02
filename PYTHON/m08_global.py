import math
from scipy.optimize import fsolve

# Antoine equation constants for n-Pentane and n-Hexane
antoine_constants = {
    "n_pentane": {"A": 6.85221, "B": 1064.63, "C": 232},
    "n_hexane": {"A": 6.87776, "B": 1171.53, "C": 224.366}
}

# Feed composition and drum pressure
z_pentane = 0.5  # Feed mole fraction of n-Pentane
z_hexane = 0.5   # Feed mole fraction of n-Hexane
P_drum = 762.49  # Optimized drum pressure (mmHg)

# Function to calculate vapor pressure using Antoine's equation
def calculate_vapor_pressure(A, B, C, T):
    """Calculate vapor pressure using Antoine equation (T in °C, P in mmHg)."""
    return 10 ** (A - (B / (T + C)))

# Modified flash equation with logging
def flash_equation_with_logging(T_array, V_over_F_guess=0.5):
    """Flash equation to solve for T and log each iteration."""
    # Extract scalar value from numpy array
    T = T_array[0]
    
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

    # Calculate distribution coefficients K_i
    K_pentane = P_sat_pentane / P_drum
    K_hexane = P_sat_hexane / P_drum

    # Flash equation for components
    result = (
        (z_pentane * (K_pentane - 1) / (1 + V_over_F_guess * (K_pentane - 1))) +
        (z_hexane * (K_hexane - 1) / (1 + V_over_F_guess * (K_hexane - 1)))
    )

    # Log iteration details
    print(f"Iteration: T = {T:.4f} °C, P_sat_pentane = {P_sat_pentane:.2f} mmHg, "
          f"P_sat_hexane = {P_sat_hexane:.2f} mmHg, K_pentane = {K_pentane:.4f}, "
          f"K_hexane = {K_hexane:.4f}, Result = {result:.6f}")

    return result

# Initial guess for the flash temperature
T_selected = 48.53  # °C (from bubble and dew point calculation midpoint)

# Solve for flash temperature using fsolve and log iterations
flash_temperature = fsolve(flash_equation_with_logging, [T_selected])[0]  # Pass T as a list

print(f"\nFinal Flash Temperature: {flash_temperature:.2f} °C")
