// Krishnamurthy number
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
    int n, digit, sum = 0, temp;
    printf("Enter the number : ");
    scanf("%d", &n);
    temp = n;
    while (temp > 0)
    {
        digit = temp % 10;
        sum = sum + factorial(digit);
        temp = temp / 10;
    }
    if (n == sum)
    {
        printf("The number is Krishnamuethy number\n");
    }
    else
    {
        printf("The number is not the Krishnamurthy number\n");
    }

    return 0;
}