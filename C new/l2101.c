// sum of n numbers using recursion
#include <stdio.h>
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (n + sum(n - 1));
    }
}
int main()
{
    int n;
    printf("enter the number\n");
    scanf("%d", &n);
    printf("the factorial of the given number %d is %d", n, sum(n));
    return 0;
}