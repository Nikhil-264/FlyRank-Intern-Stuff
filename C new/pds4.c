// Read in the coefficients a, b, c of the quadratic equation ax2 + bx + c = 0, and print its roots nicely (for
// imaginary roots, print in x + iy form)
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    float a, b, c;
    printf("write a b c as coefficient of quadratic eqn \n");
    scanf("%f%f%f", &a, &b, &c);
    printf("equation is %fx^2 + %fx + %f = 0\n", a, b, c);
    if ((b * b - 4 * a * c) > 0)
    {
        printf("The roots are %f and %f", (-b - sqrt(b * b - 4 * a * c)) / (2 * a), (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
    }
    else if ((b * b - 4 * a * c) < 0)
    {
        printf("The roots are %f+%fi and %f+%fi ", -b / (2 * a), (-sqrt(-(b * b - 4 * a * c))) / (2 * a), -b / (2 * a), (+sqrt(-(b * b - 4 * a * c))) / (2 * a));
    }

    return 0;
}
