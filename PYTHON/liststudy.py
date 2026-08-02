import math

# Given and assumed values for recalculation
feed_flow_rate = 15  # m³/hr (convert to kg/s)
density_liquid = 650  # kg/m³ (average of pentane and hexane densities)
density_vapor = 2.5  # kg/m³ (assumed vapor density)
vapor_fraction = 0.5  # Estimated V/F (flash ratio)
max_vapor_velocity = 0.15  # m/s (based on SF from PDF table)
operating_pressure = 762.49 * 133.322  # mmHg to Pa
safety_factor = 1.15  # 15% safety margin for pressure
design_pressure = operating_pressure * safety_factor  # Pa
allowable_stress = 120e6  # Pa (assume for typical industrial-grade steel)
joint_efficiency = 0.85  # for welded joints

# Step 1: Calculate vapor flow rate (kg/s)
feed_mass_flow_rate = feed_flow_rate * density_liquid / 3600  # kg/s
vapor_mass_flow_rate = vapor_fraction * feed_mass_flow_rate  # kg/s

# Step 2: Calculate minimum diameter of drum
d_min = math.sqrt(
    (4 * vapor_mass_flow_rate) / (math.pi * max_vapor_velocity * density_vapor)
)

# Step 3: Calculate thickness of the drum
radius = d_min / 2  # Inner radius of the drum (m)
thickness = (design_pressure * radius) / (
    allowable_stress * joint_efficiency - 0.6 * design_pressure
)

# Outputs: diameter and thickness
d_min, thickness

print(d_min)
print(thickness)