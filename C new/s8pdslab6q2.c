#include <stdio.h>
#include <math.h>

float evalpoly(int poly[], int k, float x)
{
    float result = 0.0;
    for (int i = k; i >= 0; i--)
    {
        result = result * x + poly[i];
    }
    return result;
}

float myroot(int poly[], int k, float a, float b)
{
    float c;
    float f_a = evalpoly(poly, k, a);
    float f_b = evalpoly(poly, k, b);

    if (f_a * f_b > 0)
    {
        printf("Error: f(a) and f(b) have the same sign.\n");
        return -1;
    }

    while (fabs(b - a) >= 0.0001)
    {
        c = (a + b) / 2.0;
        float f_c = evalpoly(poly, k, c);

        if (f_c < 0.0001)
        {
            return c;
        }

        if (f_c * f_a < 0)
        {
            b = c;
        }
        else
        {
            a = c;
            f_a = f_c;
        }
    }

    return c;
}

int main()
{
    int k;
    float a, b;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &k);

    int poly[k + 1];

    printf("Enter the coefficients of the polynomial (starting from the highest degree):\n");
    for (int i = k; i >= 0; i--)
    {
        scanf("%d", &poly[i]);
    }

    printf("Enter the values of a and b: ");
    scanf("%f %f", &a, &b);

    float root = myroot(poly, k, a, b);

    if (root != -1)
    {
        printf("Root of the polynomial between %.2f and %.2f: %.4f\n", a, b, root);
    }

    return 0;
}
