// Write a C program to enter your name and print the unique characters. Modify
// your code for both case-sensitive and insensitive.
// Input: A P J Abdul Kalam
// Output: A P J K b d u l a m (case sensitive)
// A P J K b d u l m (case insensitive)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void case_sensitive(char *str)
{
    int counted[100];
    int count;
    for (int i = 0; i < strlen(str); i++)
    {
        counted[i] = 0;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (counted[i] == 1)
            continue;
        count = 1;
        for (int j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
                counted[j] = 1;
            }
        }
        printf("%c ", str[i]);
    }
}

void case_insensitive(char *str)
{
    
}

int main()
{
    printf("Enter string :");
    char *str = (char *)malloc(sizeof(char) * 100);
    gets(str);
    case_sensitive(str);
    case_insensitive(str);

    return 0;
}
