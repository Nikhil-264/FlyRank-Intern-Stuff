// Root of a polynomial. Let f be a polynomial with f(a) < 0 and f(b) > 0 for given a and b. This means
// that there is a root of the polynomial between a and b. Use the principle of binary search to find c between
// a and b by repeatedly halving the interval of search, until f(c) < 0.0001. Therefore:

// (a) Write a function, float evalpoly(int poly[], int k, int x), that returns the value of a k-
// degree polynomial poly[] at a point x. For example, for evaluating 9x3 + 3x + 5 at x = 2.0, we

// have the coefficients poly[] = {5, 3, 0, 9}, the degree k = 3, and the value returned for x=2.0
// is 72.0 + 6.0 + 5 = 83.0
// (b) Write a function, float myroot(int poly[], int k, float a, float b), that returns the
// root of the k-degree polynomial between a and b (namely the value of c for which f(c) < 0.0001). If
// f(a) and f(b) have the same sign, the function should return some error value that enables the calling
// program to understand that the function returns failure.
// Write a main() that reads the values of k, a, b, and the coefficients poly[], then calls myroot() to
// find and print the root of the polynomial between a and b. If f(a) and f(b) have the same sign then
// main() should print an error statement.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float evalpoly(int ar[], int n, float x)
{
    float sum = 0;
    for (int i = 0; i < n + 1; i++)
    {
        sum = sum + ar[i] * pow(x, i);
    }
    return sum;
}

float myroot(int ar[], int n, float a, float b)
{
    float c;
    if ((evalpoly(ar, n, a) * evalpoly(ar, n, b)) > 0)
    {
        printf("error : root doesnt exist in this interval");
        return -1;
    }
    else
    {
        c = (a + b) / 2;
        while (fabs(evalpoly(ar, n, c)) >= 0.0001)
        {
            if ((evalpoly(ar, n, a) * evalpoly(ar, n, c)) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
            c = (a + b) / 2;
        }
        // printf("root is : %f", c);
    }
    return c;
}
int main()
{
    int n;
    printf("Enter degree of polynomial : ");
    scanf("%d", &n);
    int *poly = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter coefficients of polynomial : ");
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%d", &poly[i]);
    }
    float a, b;
    printf("enter interval such that a<b enter a and b respectively :");
    scanf("%f %f", &a, &b);
    float root = myroot(poly, n, a, b);
    printf("root is : %.10f\n", root);
    free(poly);
    return 0;
}