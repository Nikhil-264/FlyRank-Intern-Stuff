#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function for which we are finding the root: f(x) = 5x - e^(-x^2) + sin(x)
double func(double x) {
    return 5 * x - exp(-x * x) + sin(x);
}

// Bisection method
void bisectionMethod(double a, double b, double tol, int maxIter) {
    if (func(a) * func(b) >= 0) {
        cout << "Bisection method fails. The function must have opposite signs at the endpoints." << endl;
        return;
    }

    double c = a; // Initialize middle point
    int iter = 0;

    while ((b - a) >= tol && iter < maxIter) {
        // Find the middle point
        c = (a + b) / 2;

        // Print current approximation
        cout << "Iteration " << iter + 1 << ": x = " << fixed << setprecision(5) << a << " " << c  << " " << b << endl;

        // Check if middle point is root
        if (func(c) == 0.0) {
            break;
        }
        // Decide the side to repeat the steps
        else if (func(c) * func(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }

        iter++;
    }

    cout << "The root is approximately: " << fixed << setprecision(5) << c << endl;
}

int main() {
    double a = 0.16244, b = 0.16245;  // Initial guesses for the interval [a, b]
    double tol = 1e-6;     // Tolerance
    int maxIter = 50;      // Maximum iterations

    bisectionMethod(a, b, tol, maxIter);

    return 0;
}
