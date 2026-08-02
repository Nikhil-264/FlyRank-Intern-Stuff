#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int a = 1, b = 2, c = 3, d = 4;
    printf("%d\n", a && b || c && d > a || c <= b);
    float P, I, N;

    printf("give the values of amount , rate, no. of years in the same order : \n");
    scanf("%f%f%f", &P, &I, &N);
    printf("%f", P * (pow(1 + (I) / 100, N)));

    return 0;
}
