import matplotlib.pyplot as plt

# Label fractions
x = [10, 20, 30, 40]

# Mean accuracy
acc_mean = [82.6, 86.1, 88.5, 91.8]

# Lower and upper bounds (your ranges)
acc_min = [80, 84, 87, 90]
acc_max = [84, 88, 90, 93]

# Convert to error bars
error = [[m - l for m, l in zip(acc_mean, acc_min)],
         [u - m for u, m in zip(acc_max, acc_mean)]]

plt.figure()
plt.errorbar(x, acc_mean, yerr=error, marker='o', capsize=5)

plt.xlabel("Labeled Fraction (%)")
plt.ylabel("Accuracy (%)")
plt.title("Accuracy vs Label Fraction (with variability)")
plt.grid(True)

plt.savefig("accuracy_error_plot.png", dpi=300)
plt.show()