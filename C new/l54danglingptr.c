#include <stdio.h>
#include <stdlib.h>
int funcdangling()
{
    int a = 34;
    int b = 346;
    int sum = a + b;
    return &sum;
}
int main()
{
    // CASE 1: deallocation of memory block
    int *ptr = (int *)malloc(7 * sizeof(int));
    ptr[0] = 5;
    ptr[1] = 4;
    ptr[2] = 7;
    ptr[3] = 2;
    free(ptr); // Now ptr is dangling pointer
    // CASE 2: function returning local variable address
    int *dangptr = funcdangling(); // ptr is dangling now
    // CASE 3: If variable goes out of scope
    int *danglingptr;
    {
        int a = 12;
        danglingptr = &a;
    }
    //here variable a goes out of svope which means danglingptr is pointng to a location which is freed and hence danglingptr is  now a dangling pointer

    return 0;
}