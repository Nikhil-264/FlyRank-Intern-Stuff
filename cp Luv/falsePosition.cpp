//False Position or Regula Falsi
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function for which we are finding the root: f(x) = 5x - e^(-x^2) + sin(x)
double func(double x) {
    return 5 * x - exp(-x * x) + sin(x);
}

// False Position Method
void falsePositionMethod(double a, double b, double tol, int maxIter) {
    if (func(a) * func(b) >= 0) {
        cout << "False Position method fails. The function must have opposite signs at the endpoints." << endl;
        return;
    }

    double c = a;  // Initialize the root
    int iter = 0;

    while ((b - a) >= tol && iter < maxIter) {
        // Compute the point where the secant line crosses the x-axis
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        // Print current approximation
        cout << "Iteration " << iter + 1 << ": x = " << fixed << setprecision(5) << c << endl;

        // Check if the root is found
        if (fabs(func(c)) <= tol) {
            break;
        }
        // Decide the new interval
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
    double a = 0.0, b = 1.0;  // Initial guesses for the interval [a, b]
    double tol = 1e-6;        // Tolerance
    int maxIter = 50;         // Maximum iterations

    falsePositionMethod(a, b, tol, maxIter);

    return 0;
}
