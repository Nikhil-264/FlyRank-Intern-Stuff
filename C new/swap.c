#include <stdio.h>
#include <stdlib.h>
void swap(int *n, int *m)
{
    int temp = *n;
    *n = *m;
    *m = temp;
}
int main()
{
    int n = 8;
    int m = 56;
    swap(&n, &m);
    printf("%d %d", n, m);

    return 0;
}