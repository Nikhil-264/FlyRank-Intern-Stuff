// while loop
#include <stdio.h>
int main()
{
    int n, i = 0; // if i=0 it will start from 0
    printf("enter  n\n");
    scanf("%d", &n);
    while (i < n)
    {
        printf("%d\n", i);
        i = i + 1;
    }

    return 0;
}
