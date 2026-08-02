// paliondrome string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n = 0;
    char str[100];
    char temp[100];
    gets(str);
    strcpy(temp, str);
    printf("%c\n", str[2]);
    // puts(strrev(str));
    // puts(temp);
    // puts(str);
    for (int i = 0; i < strlen(str); i++)
    {

        if (str[i] == temp[i])
        {
            n++;
            
        }
        if (n==strlen(str))
        {
            printf("YEs");
        }
        
    }
    return 0;
}