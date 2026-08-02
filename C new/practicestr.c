// Write a C program to convert vowels into uppercase characters in a string.
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0;
    printf("Give your string : \n");
    char str[100];
    gets(str);
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }

    printf("%s", str);

    return 0;
}