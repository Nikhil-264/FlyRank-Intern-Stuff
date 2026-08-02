import matplotlib.pyplot as plt

# Data
x = [10, 20, 30, 40]
acc_mean = [82.6, 86.1, 88.5, 91.8]
acc_min = [80, 84, 87, 90]
acc_max = [84, 88, 90, 93]

# Error bars
error = [[m - l for m, l in zip(acc_mean, acc_min)],
         [u - m for u, m in zip(acc_max, acc_mean)]]

# Style
plt.figure(figsize=(7,5))
plt.errorbar(
    x, acc_mean, yerr=error,
    fmt='o-', linewidth=2, markersize=6,
    capsize=6
)

# Labels
plt.xlabel("Labeled Fraction (%)", fontsize=12)
plt.ylabel("Accuracy (%)", fontsize=12)
plt.title("Accuracy vs Label Fraction with Variability", fontsize=13)

# Grid (light, subtle)
plt.grid(alpha=0.3)

# Limits (important for clean look)
plt.ylim(78, 95)

# Ticks
plt.xticks(x)

# Tight layout (important for PDF)
plt.tight_layout()

# Save high quality
plt.savefig("accuracy_error_plot.png", dpi=300)

plt.show()
f1_mean = [81.4, 85.5, 88.0, 91.5]
f1_min = [79, 83, 86, 90]
f1_max = [83, 87, 90, 93]

f1_error = [[m - l for m, l in zip(f1_mean, f1_min)],
            [u - m for u, m in zip(f1_max, f1_mean)]]

plt.figure(figsize=(7,5))

plt.errorbar(x, acc_mean, yerr=error, fmt='o-', linewidth=2, capsize=6, label="Accuracy")
plt.errorbar(x, f1_mean, yerr=f1_error, fmt='s--', linewidth=2, capsize=6, label="Macro F1")

plt.xlabel("Labeled Fraction (%)")
plt.ylabel("Score (%)")
plt.title("Performance vs Label Fraction with Variability")

plt.legend()
plt.grid(alpha=0.3)
plt.ylim(78, 95)
plt.xticks(x)

plt.tight_layout()
plt.savefig("performance_error_plot.png", dpi=300)
plt.show()