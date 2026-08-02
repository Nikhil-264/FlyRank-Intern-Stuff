#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("argc is %d\n", argc - 1);

    printf("The argument supplied are : \n");
    for (int i = 1; i < argc; i++)
    {
        printf(" at %d = %s\n", i, argv[i]);
    }

    return 0;
}