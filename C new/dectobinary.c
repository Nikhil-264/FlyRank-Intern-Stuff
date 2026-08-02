// Decimal to Binary.
#include <stdio.h>
#include <math.h>
int main()
{
    int n, p = 0, binary;
    printf("Enter the number : ");
    scanf("%d", &n);
    while (pow(2, p) <= n)
        p++;
    int array[p];
    for (int i = 0; i < p; i++)
    {
        binary = n % 2;
        n = n / 2;
        array[i] = binary;
    }
    printf("The given number in binary is : ");
    for (int i = p - 1; i >= 0; i--)
    {
        printf("%d", array[i]);
    }

    return 0;
}