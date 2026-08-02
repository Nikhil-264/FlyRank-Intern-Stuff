// 2. Read in the coordinates of two points and print the equation of the line joining them in y = mx +c form.
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int x1, y1, x2, y2; 
    float m ;
    printf("Enter first point co-ordinates :  ");
    scanf("%d%d", &x1, &y1);
    printf("Enter second point co-ordinates :  ");
    scanf("%d%d", &x2, &y2);
    m = (float)(y2-y1)/(x2-x1);
    printf("The equation of line joining the points is : y = %.1fx + %.1f",m,y1-m*x1);

    return 0;
}
