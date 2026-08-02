#include <stdio.h>
#include <stdlib.h>

int main()
{
    int chars, i = 0;
    char *ptr;
    while (i < 3)
    {
        printf("ENter number of characters in ID : ");
        scanf("%d",&chars);
        ptr = (char*)malloc((chars+1)*sizeof(char));
        printf("Enter your ID : ");
        scanf("%s",ptr);
        printf("ID is %s\n",ptr);
        free(ptr);
        i++;
    }
    return 0;
}