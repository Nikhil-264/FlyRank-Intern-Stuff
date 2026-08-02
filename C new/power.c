// power of a number
#include <stdio.h>
int exponent(int a,int n)
{
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return( n * exponent(a - 1,n));
    }
}
int main ()
{
    int a,n ;
    printf("Enter power and number :");
    scanf("%d%d",&a,&n);
    printf("%d",exponent(a,n));
    return 0;
}