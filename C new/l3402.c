//Seperating elements in string 
#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100];
    int n;
    gets(str1);
    n = strlen(str1);
    for (int i = 0; i < n; i++)
    {
        printf("%c ",str1[i]);
    }
    

    return 0;
}
