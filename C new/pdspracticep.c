// Allocate and reallocate a list of floating point numbers and characters.
// Ask user to input an integer n. Allocate n lists of characters. Ask the user to input the characters one by one for each list, and store the lists in n separate arrays (dynamically allocated). Concatenate them and store it in a dynamically allocated new array.
// Make sure, you always use dynamic memory allocation. Write functions that passes the pointers to the lists. Do not keep anything global.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    char **list, **list2;
    printf("Enter A Number : ");
    scanf("%d", &n);
    list = (char **)malloc(n * sizeof(char *));
    list2 = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        list[i] = (char *)malloc(100 * sizeof(char));
        list2[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", &list[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; list[i][j] != '\0'; j++)
        {
            printf("%c", list[i][j]);
        }
        printf("\n");
    }

    return 0;
}