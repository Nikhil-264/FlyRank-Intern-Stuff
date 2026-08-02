#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function that defines the ODE: dy/dt = t + y
double func(double t, double y) {
    return t + y;
}

// Explicit Euler method
void explicitEuler(double t0, double y0, double h, double t_end) {
    double t = t0;
    double y = y0;
    
    cout << "Explicit Euler Method:" << endl;
    cout << "t = " << t << ", y = " << fixed << setprecision(6) << y << endl;
    
    while (t < t_end) {
        // Explicit Euler step
        y = y + h * func(t, y);
        t = t + h;
        
        cout << "t = " << t << ", y = " << fixed << setprecision(6) << y << endl;
    }
}

int main() {
    double t0 = 0.0;   // Initial time
    double y0 = 1.0;   // Initial value of y
    double h = 0.1;    // Step size
    double t_end = 1.0;  // End time

    explicitEuler(t0, y0, h, t_end);

    return 0;
}
