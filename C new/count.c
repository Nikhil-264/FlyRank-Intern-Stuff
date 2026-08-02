// counts number of digits in number
#include <stdio.h>
int exponent(int a)
{
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return 10 * exponent(a - 1);
    }
}
int main()
{
    int num, a, i=0;
    printf("enter the num\n");
    scanf("%d", &num);
    do
    {
        a = num / exponent(i);
        i = i + 1;
       
    } while (a > 1);
    printf("Number of digits in number are %d",i-1);
    return 0;
}