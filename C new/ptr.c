#include <stdio.h>
#include <stdlib.h>
void add(int *n, int *m)
{
    int result = *n + *m;
    printf("%d\n", result);
}
int main()
{
    int n = 9, m = 4;
    // add(&n, &m);
    int a = 0 ;
    int b = 8 ;
    printf("%d\n",&a);
    printf("%d\n",&b);
    // printf("%d",&);

    return 0;
}