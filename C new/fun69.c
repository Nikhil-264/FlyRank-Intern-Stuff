#include <stdio.h>
#include <stdbool.h>

bool checkDigits(int square, int cube)
{
    int digitCount[10] = {0}; // Array to store the count of each digit
    while (square > 0)
    {
        digitCount[square % 10]++;
        square /= 10;
    }
    while (cube > 0)
    {
        digitCount[cube % 10]++;
        cube /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (digitCount[i] == 0)
        {
            return false;
        }
    }
    return true;
}

void findNumbers()
{
    int numbers[51];
    int count = 0;
    for (int n = 48; n < 99; n++)
    {
        int square = n * n;
        int cube = n * n * n;
        if (checkDigits(square, cube))
        {
            numbers[count] = n;
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main()
{
    findNumbers();
    return 0;
}
