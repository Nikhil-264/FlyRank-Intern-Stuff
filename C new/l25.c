// fibonacci series using recursions
#include <stdio.h>
int fibo(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return (fibo(n - 2) + fibo(n - 1));
    }
}
int main()
{
    int a , n ;
    printf ("Enter number of elements you want in series : ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", fibo(i));
    }
     
    return 0;
}