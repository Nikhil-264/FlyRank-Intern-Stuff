// functions in C
#include <stdio.h>
int product(int a, int b)
{
    return a * b;
}
int main()
{
    int a, b;
    printf("enter a and b\n");
    scanf("%d%d", &a, &b);
    printf("%d", product(a, b));
    return 0;
}
