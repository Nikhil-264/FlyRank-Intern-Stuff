#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b)
{
    return a + b;
}
int lol(int a, int b)
{
    return a * b;
}
int lo(int a)
{
    return 0;
}
void k()
{
    printf("Hello\n");
}

int main()
{
    int (*fptr)(int, int);      // declaring pointer
    fptr = &sum;                // creating function pointer
    printf("%d\n", fptr(2, 3)); // testing
    printf("%d\n", fptr(6, 3));
    fptr = &lol;
    printf("%d\n", fptr(6, 3));
    int (*ftr)(int);
    ftr = &lo;
    printf("%d\n", ftr(6));
    void (*me)();
    me = &k;
    me();
    return 0;
}