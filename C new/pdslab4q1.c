/****************************
Name:-Nikhil Mahindrakar
Roll NO :- 22CH10036
Section:-06
Assignment No:- 4
Description:-Forth C Program question 1 function and recurtion
Date :-28-April-2023
****************************/
#include <stdio.h>
int uptopic_line(int n, int l)
{
    if (n == 1 || n == 0)
        return n + 1;
    if (n > 1)
        return uptopic_line(n - 1, 0) + uptopic_line(n - 2, 0);
}
int utopic_circle(int n, int l)
{
    if (n == 1 || n == 2 || n == 3 || n == 0)
        return n + 1;
    if (n > 3)
        return utopic_circle(n - 1, 0) + utopic_circle(n - 2, 0);
}
int main()
{
    int n;
    printf("Enter the number of ducklings : ");
    scanf("%d", &n);
    printf("The number of UTOPIC collection in line : %d\n", uptopic_line(n, 0));
    printf("The number of UTOPIC collection in circle : %d\n", utopic_circle(n, 0));

    printf("L(n)f0r n=19: %d\n", uptopic_line(19, 0));
    printf("C(n) f0r n=19: %d\n", utopic_circle(19, 0));
    printf("L(n)for n=23: %d\n", uptopic_line(23, 0));
    printf("C(n) for n=23 : %d\n", utopic_circle(23, 0));
    printf("L(n) for n=29: %d\n", uptopic_line(29, 0));
    printf("C(n) for n=29: %d\n", utopic_circle(29, 0));
    printf("L(n) for n=37: %d\n", uptopic_line(37, 0));
    printf("C(n) for n=37: %d\n", utopic_circle(37, 0));

    return 0;
}
