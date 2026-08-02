// deducing factorial of a number 
//using recursive function
#include <stdio.h>
int factorial(int n)
{
    if ((n == 0) || (n == 1))
    {
        return 1;
    }
    else
    {
        return (n * factorial(n - 1));
    }
}
int main()
{
    int n;
    printf("enter the number\n");
    scanf("%d", &n);
    printf("the factorial of the given number %d is %d", n, factorial(n));
    return 0;
}