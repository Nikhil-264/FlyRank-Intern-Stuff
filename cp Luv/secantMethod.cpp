#include <bits/stdc++.h>
// #include <cmath>
// #include <iomanip>
using namespace std;

// Function for which we are finding the root: f(x) = 5x - e^(-x^2) + sin(x)
double func(double x) {
    return 5 * x - exp(-x * x) + sin(x);
}

// Secant method
void secantMethod(double x0, double x1, double tol, int maxIter) {
    double x2;
    int iter = 0;

    cout << "Iteration " << iter + 1 << ": x0 = " << fixed << setprecision(5) << x0 
         << ", x1 = " << x1 << endl;

    // Loop until the error tolerance or max iterations are reached
    while (fabs(x1 - x0) >= tol && iter < maxIter) {
        // Compute next approximation using secant formula
        x2 = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));

        // Print current approximation
        iter++;
        cout << "Iteration " << iter + 1 << ": x = " << fixed << setprecision(5) << x2 << endl;

        // Update the previous two values
        x0 = x1;
        x1 = x2;
    }

    // Output the root approximation
    cout << "The root is approximately: " << fixed << setprecision(5) << x2 << endl;
}

int main() {
    double x0 = 0.16, x1 = 0.17;  // Initial guesses
    double tol = 1e-6;            // Tolerance
    int maxIter = 50;             // Maximum iterations

    secantMethod(x0, x1, tol, maxIter);

    return 0;
}

