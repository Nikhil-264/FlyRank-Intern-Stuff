#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rows, columns;
    printf("Enter the number of rows and columns : ");
    scanf("%d%d", &rows, &columns);
    char **str = (char **)malloc(rows * sizeof(char *));
    // char **str = calloc(rows, sizeof(char *));
    for (int i = 0; i < rows; i++)
    {
        *(str + i) = (char *)malloc(columns * sizeof(char));
    }
    printf("Enter the strings : \n");
    getchar();
    for (int i = 0; i < rows; i++)
    {
        gets(*(str + i));
    }
    for (int i = 0; i < rows; i++)
    {
        puts(*(str + i));
    }
    free(str);

    return 0;
}