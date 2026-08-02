// COunting string members
#include <stdio.h>
int main()
{
    int i = 0;
    printf("Enter your word : ");

    char str[100];
    gets(str);
    do
    {
        i++;
    } while (str[i] != '\0');

    printf("The word is : ");
    puts(str);

    printf("Number of characters in the %s are %d", str, i);
    return 0;
}