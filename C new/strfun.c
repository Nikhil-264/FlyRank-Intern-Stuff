#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char exchange(char str[], int words, char before[], char after[])
{
    int wordstart=0, wordend;
    char word[100];
    for (int i = 0; i <= strlen(str); i++)
    {
        for (int j = wordstart; j < wordend; j++)
        {
            if (str[i]!=' '||str[i]!='\0')
            {
                word[j]=str[i];
            }
            if (str[i]==' '||str[i]=='\0')
            {
                wordstart=i+1;
                
            }
            
            
        }
    }
}
int main()
{
    char str[200];
    gets(str);
    int words = 0;
    for (int i = 0; i <= strlen(str); i++)
        if (str[i] == ' ' || str[i] == '\0')
            words++;
    printf("%d", words);

    return 0;
}