import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt('slit_data.txt', skiprows=1)
angles = data[:, 0]
single_intensity = data[:, 1]
double_intensity = data[:, 2]

# Calculate important angles
theta_min = 500e-9 / 0.1e-3  # λ/a in radians
theta_sep = 500e-9 / 0.5e-3  # λ/d in radians

# Create figure
plt.figure(figsize=(12, 8))

# Single-slit plot
plt.subplot(2, 1, 1)
plt.plot(angles, single_intensity, 'b-', linewidth=1.5)
plt.title('Single-Slit Diffraction Pattern', fontsize=14)
plt.xlabel('Angle θ (radians)', fontsize=12)
plt.ylabel('Relative Intensity', fontsize=12)
plt.grid(True, alpha=0.3)




# Double-slit plot
plt.subplot(2, 1, 2)
plt.plot(angles, double_intensity, 'r-', linewidth=1.5)
plt.title('Double-Slit Interference Pattern', fontsize=14)
plt.xlabel('Angle θ (radians)', fontsize=12)
plt.ylabel('Relative Intensity', fontsize=12)
plt.grid(True, alpha=0.3)




plt.tight_layout()
plt.savefig('slit_comparison.png', dpi=300)
plt.show()