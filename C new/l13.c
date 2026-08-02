// do while loop
#include <stdio.h>

int main()
{
    int n, i = 0; // i initialised to as 0
    printf("enter the number\n");
    scanf("%d", &n);
    do
    {
        printf("%d\n", i + 1); // i+1 for starting from 1 coz i is zero
        i = i + 1;
    } while (i < n);

    return 0;
}
