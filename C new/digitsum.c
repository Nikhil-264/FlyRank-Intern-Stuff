#include <stdio.h>
#include <math.h>
int exponent(int a, int n)
{
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return (n * exponent(a - 1, n));
    }
}
int main()
{
    int num, count = 0, sum = 0, temp;
    printf("Enter the number : ");
    scanf("%d", &num);
    temp = num;
    while (temp >= 1)
    {
        temp = (float)temp / 10;
        count++;
    }
    printf("Number of digits in the number is %d\n%d\n", count, temp);
    for (int i = 0; i < count; i++)
    {
        temp = num;
        num = temp % exponent(count - i - 1, 10);
        sum = sum + temp / exponent(count - i - 1, 10);
    }
    printf("Sum of digits is %d\n", sum);
    return 0;
}