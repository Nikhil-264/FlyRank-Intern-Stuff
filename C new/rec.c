#include <stdio.h>
#include <stdlib.h>
int i = 0;
int main()
{
    if (i == 100)
        return 0;
    i++;
    printf("%4d ", i);
    main();
    return 0;
}