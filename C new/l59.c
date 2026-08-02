#include <stdio.h>
#define PI 3.14
#define SQUARE(r) r *r

int main()
{
    float r = 4;
    printf("%.2f", PI);
    printf("Area is %f", PI * SQUARE(r));

    return 0;
}