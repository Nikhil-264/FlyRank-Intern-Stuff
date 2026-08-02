/*Write a program in C to check if a number is a prime number or not using recursion. Go to the editor
Test Data :
Input any positive number : 7
Expected Output :

The number 7 is a prime number */
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    int i = 2, j = 0, k = 0;
    while (pow(i, 2) < n)
    {
        i++;
        j++;
    }
    int arr[j];
    for (int k = 0; k < j; k++)
    {
        arr[k] = n % (k + 2);
    }
    for (int l = 0; l < j; l++)
    {
        if (arr[l] == 0)
        {
            k = 1;
            break;
        }
    }
    if (k == 1)
    {
        printf("The number %d is not prime number\n", n);
    }
    else
    {
        printf("The number %d is a prime number\n", n);
    }

    return 0;
}
