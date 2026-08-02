#include <stdio.h>
int main()
{
    int a = 345;
    float b = 8.3;
    void *ptr; // void pointer can be assighned to any data type by typecasting it.
    ptr = &a;
    printf("The value of a is %d\n", *((int *)ptr));
    ptr = &b;
    printf("The value of b is %.2f\n", *((float *)ptr));
    return 0;
}