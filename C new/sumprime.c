#include <stdio.h>
#include <stdlib.h>
int isprime(int n)
{
    int i;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
} 
int main()
{
    int sum = 0;
    int total = 0;
    for (int i = 2; i <= 1000; i++)
    {
        if (isprime(i))
        {
            sum += i;
            total++;
        }
    }
    printf("%d %d", sum,total);

    return 0;
}