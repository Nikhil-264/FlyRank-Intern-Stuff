#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define the ODE: dy/dt = t + y
double func(double t, double y) {
    return t + y;  // You can change this to any desired function
}

// RK4 Method
void rk4(double t0, double y0, double h, double t_end) {
    double t = t0;
    double y = y0;
    
    cout << "t = " << t << ", y = " << fixed << setprecision(6) << y << endl;
    
    while (t < t_end) {
        // Step 1: Calculate k1, k2, k3, k4
        double k1 = h * func(t, y);
        double k2 = h * func(t + h / 2, y + k1 / 2);
        double k3 = h * func(t + h / 2, y + k2 / 2);
        double k4 = h * func(t + h, y + k3);
        
        // Update y using k1, k2, k3, k4
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        
        // Update t
        t = t + h;
        
        // Print current values of t and y
        cout << "t = " << t << ", y = " << fixed << setprecision(6) << y << endl;
    }
}

int main() {
    double t0 = 0.0;   // Initial time
    double y0 = 1.0;   // Initial value of y
    double h = 0.1;    // Step size
    double t_end = 1.0;  // End time

    rk4(t0, y0, h, t_end);

    return 0;
}
