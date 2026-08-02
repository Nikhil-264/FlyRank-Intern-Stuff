// HTML parser exercise
#include <stdio.h>
#include <string.h>
int parser(char *string)
{
    int index = 0, in = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (string[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)
        {
            string[index] = string[i];
            index++;
        }
    }
    string[index] = '\0';
    while (string[0] == ' ')
    {
        for (int i = 0; i < strlen(string); i++)
        {
            string[i] = string[i + 1]; // shifts to left
        }
    } // removes initial trailing spaces
    // removing trailing spaces from end
    while (string[strlen(string) - 1] == ' ')
    {
        string[strlen(string) - 1] = '\0';
    }
}
int main()
{

    printf("Enter your string line as html tag line : \n");
    char str[200];
    gets(str);
    parser(str);
    printf("The parsed string is \"%s\" ", str);
    return 0;
}