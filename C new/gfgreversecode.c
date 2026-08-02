// You will be given an integer n, your task is to return the sum of all natural number less than or equal to n
#include <stdio.h>
#include <stdlib.h>
int sumofnatural(int n)
{
    return n * (n + 1) / 2;
}
int main()
{
    int n;
    scanf("%d", &n);
    sumofnatural(n);

    return 0;
}