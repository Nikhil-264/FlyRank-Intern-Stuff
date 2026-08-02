#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    printf("%d\n", 1+ rand() % 5);
    // // for (int i = 0; i < 5; i++)
    // // {
    // //     printf("%d\n", i);
    // // }
    // for (int i = 0; i < 5; ++i)
    // {
    //     printf("%d\n", i);
    // }

    return 0;
}