// Pascals Triangle
#include <stdio.h>
int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int combi(int n, int i)
{
    return (factorial(n) / (factorial(i) * factorial(n - i)));
}
int main()
{
    int n;
    printf("Enter the number of lines you want : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            printf("    ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("%4d    ", combi(i, j));
        }
        printf("\n");
    }

    return 0;
}