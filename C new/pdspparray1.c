// Write a C program that reads an integer n and uses an array to efficiently find out
// the first n prime numbers.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, count = 2;
    scanf("%d", &n);
    int *primes = (int *)malloc(n * sizeof(int));
    int i = 0;
    while (i < n)
    {
        if (is_prime(count))
        {
            primes[i] = count;
            i++;
        }
        count++;
    }
    for (int k = 0; k < n; k++)
    {
        printf("%d ", primes[k]);
    }

    return 0;
}