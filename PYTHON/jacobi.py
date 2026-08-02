import numpy as np

def jacobi_iteration(A, b, x0, w, tol, max_iter):
    n = len(b)
    x = x0.copy()
    x_new = x0.copy()

    for iteration in range(max_iter):
        for i in range(n):
            sigma = sum(A[i][j] * x[j] for j in range(n) if j != i)
            x_new[i] = (1 - w) * x[i] + w * (b[i] - sigma) / A[i][i]
        
        # Check for convergence
        if np.linalg.norm(x_new - x, ord=np.inf) < tol:
            return x_new, iteration + 1

        x = x_new.copy()

    return x_new, max_iter  # Return after max iterations if not converged

# Example system of equations: A * x = b
A = np.array([[3, -2, 1],
              [1, 3, -1],
              [1, -2, 3]])

b = np.array([2, 3, 2])
x0 = np.zeros_like(b)  # initial guess: (0, 0, 0)
tol = 1e-6
max_iter = 25

# Run the Jacobi method for w = 0.9, 1, and 1.1
for w in [0.9, 1.0, 1.1]:
    x, num_iter = jacobi_iteration(A, b, x0, w, tol, max_iter)
    # Print the result rounded to 4 decimal places
    x_rounded = np.round(x, 4)
    print(f"Solution for w = {w}: {x_rounded} in {num_iter} iterations")
