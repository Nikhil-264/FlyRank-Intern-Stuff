// checking the number is palindrome or not for number
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, reverse = 0, original, remainder;
    printf("Enter the number : ");
    scanf("%d", &n);
    original = n;
    while (n != 0)
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n = n / 10;
    }
    if (reverse == original)
    {
        printf("The numebr is palindrome");
    }
    else
    {
        printf("The numebr is not palindrome");
    }

    return 0;
}