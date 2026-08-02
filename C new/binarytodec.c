#include <stdio.h>
#include <math.h>
int main()
{
    long signed int bin;
    printf("Enter the binary number only : ");
    scanf("%d", &bin);
    int n = 0, temp, sum = 0, r;
    temp = bin;
    // while (temp >= 1)
    // {
    //     temp = temp / 10;
    //     n++;
    // }

    temp = bin;

    for (int i = 0; temp >= 1; i++)
    {
        r = temp % 10;
        sum = sum + r * pow(2, i);
        temp = temp / 10;
    }
    printf("%d", sum);

    return 0;
}