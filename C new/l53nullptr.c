#include <stdio.h>
int main()
{
    int a = 34;
    int *ptr;
    if (ptr != NULL)
    {
        printf("The address of a is %d\n", *ptr);
    }
    else
    {
        printf("Pointer is null cont be printed");
    }

    return 0;
}