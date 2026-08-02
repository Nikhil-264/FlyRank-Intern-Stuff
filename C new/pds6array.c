#include <stdio.h>
#include <stdlib.h>
void f(int A[], int B)
{
    A[2] = 10;
    B = 10;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5}, B[] = {1, 2, 3, 4, 5};
    f(A, B[2]);
    //showing that individual element can not be passed in function as argument
    printf("A[2] = %d , B[2] = %d ", A[2], B[2]);
    return 0;
}