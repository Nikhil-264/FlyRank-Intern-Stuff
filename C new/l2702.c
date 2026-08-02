#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 6;
    int *ptr = &n;
    printf("%p\n", &n);
    printf("%p\n", &ptr);
    printf("%p\n", *(&ptr));
    printf("%d\n", *(&n));
    printf("%d\n", *ptr);
    return 0;
}