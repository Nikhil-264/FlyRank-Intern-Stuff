// Name : Nikhil Mahibdrakar
// Roll no : 22CH10036
// Section 6
// Assignment 2
// Desciption - Conditions and branching
// Date : 24 March 2023

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a1, b1, c1, a2, b2, c2; // variables in circle eqn x^2 + y^2 + ax + by + c = 0
    float r1, r2, d;
    float x1, y1, x2, y2;
    float A, B, C;
    printf("Eter a b c as they are coefficints of eqn x^2 + y^2 +ax + by +c =0\n");
    printf("ENter coefficints for circle 1 : ");
    scanf("%f%f%f", &a1, &b1, &c1);

    printf("ENter coefficints for circle 2 : ");

    scanf("%f%f%f", &a2, &b2, &c2);

    if (a1 * a1 + b1 * b1 <= 4 * c1 || a2 * a2 + b2 * b2 <= 4 * c2)
    {
        printf("Incorrect input \nEnter the circles once again\n");
        printf("ENter coefficints for circle 1 : ");
        scanf("%f%f%f", &a1, &b1, &c1);
        printf("ENter coefficints for circle 2 : ");
        scanf("%f%f%f", &a2, &b2, &c2);
    }
    r1 = sqrt(a1 * a1 / 4 + b1 * b1 / 4 - c1);
    printf("The center of circle is  1 (%f,%f) and radius is %f\n", -a1 / 2, -b1 / 2, r1);
    r2 = sqrt(a2 * a2 / 4 + b2 * b2 / 4 - c2);
    printf("The center of circle is 2 (%f,%f) and radius is %f\n", -a2 / 2, -b2 / 2, r2);
    d = (sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2))) / 2;

    if (r1 + r2 < d)
    {
        printf("Two circles are not touching and not inside of other\n");
    }
    else if (r1 + r2 == d)
    {
        printf("Two circles are touching each other from outside\n");
    }
    else if (r1 + r2 > d)
    {
        if (r1 - r2 == d || r2 - r1 == d)
        {
            printf("Two circles are touching each other inside\n");
        }
        else if (r1 - r2 > d || r2 - r1 > d)
        {
            printf("one circle is inside the other \n");
        }
        else if (r1 - r2 < d || r2 - r1 < d)
        {
            printf("Both circles intersect at two points \n");
            A = ((b1 - b2) * (b1 * b2) + (a2 - a1) * (a2 - a1)) / ((b1 - b2) * (b1 - b2));
            B = ((2 * (c2 - c1) * (a2 - a1)) / ((b1 - b2) * (b1 - b2)) + a1 + b1 * (a2 - a1) / (b1 - b2));
            C = (((c1 - c2) * (c1 - c2)) / ((b1 - b2) * (b1 - b2)) + c1 + b1 * (c1 - c2) / (b1 - b2));
            x1 = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
            x2 = (-B - sqrt(B * B - 4 * A * C)) / (2 * A);
            y1 = ((c2 - c1) + (a2 - a1) * x1) / (b1 - b2);
            y2 = ((c2 - c1) + (a2 - a1) * x2) / (b1 - b2);
            printf("Points or intersection are (%f,%f) and (%f,%f)\n", x1, y1, x2, y2);
            if (r1 * r1 + r2 * r2 == d * d)
            {
                printf("Both circles intersect orthogonally\n");
                printf("AND\n The equation of the circle that intersects the intersection points or original circles and centres of circles is : \n");
                printf("(x - %f)^2 + (y - %f)^2 = %f ", -(a1 + a2) / 4, -(b1 + b2) / 4, d * d / 4);
                printf("substituting the value of x1 , y1 in the main circle eqaution we get %f\n", (x1 + (a1 + a2) / 4) * (x1 + (a1 + a2) / 4) + (y1 + (b1 + b2) / 4) * (y1 + (b1 + b2) / 4) - d * d / 4);
            }
        }
        else if (r1 == r2 && d == 0)
        {
            printf("Both circles are same\n");
        }
    }

    return 0;
}
