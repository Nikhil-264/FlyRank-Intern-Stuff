#include <stdio.h>
#include <math.h>
int main()
{
    float a1, b1, c1, a2, b2, c2, r1, r2, d, count = 1;
    float x1, y1, x2, y2;
    float A, B, C;
    printf("Enter coefficients of circle\n");
    scanf("%f%f%f%f%f%f", &a1, &b1, &c1, &a2, &b2, &c2);

    while (a1 * a1 + b1 * b1 <= 4 * c1 || a2 * a2 + b2 * b2 <= 4 * c2)
    {
        printf("Wrong input enter again");
        printf("Enter coefficients of circle\n");
        scanf("%f%f%f%f%f%f", &a1, &b1, &c1, &a2, &b2, &c2);
        count++;
        while (count == 2)
        {
            return 0;
        }
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
            if (d == 0)
            {
                printf("Both circles are same\n");
            }
            else
            {
                printf("Two circles are touching each other inside\n");
            }
        }
        else if (r1 - r2 > d || r2 - r1 > d)
        {
            printf("one circle is inside the other \n");
        }
        else if (r1 - r2 < d || r2 - r1 < d)
        {
            printf("Both circles intersect at two points \n");

            A = 1 + pow(((a2 - a1) / (b1 - b2)), 2);
            B = 2 * (c2 - c1) * (a2 - a1) / ((b1 - b2) * (b1 - b2)) + a1 + b1 * (a2 - a1) / (b1 - b2);
            C = ((c2 - c1) * (c2 - c1)) / ((b2 - b1) * (b2 - b1)) + c1 + b1 * (c2 - c1) / (b1 - b2);
            x1 = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
            x2 = (-B - sqrt(B * B - 4 * A * C)) / (2 * A);
            y1 = ((c2 - c1) + (a2 - a1) * x1) / (b1 - b2);
            y2 = ((c2 - c1) + (a2 - a1) * x2) / (b1 - b2);
            printf("Points of intersection are ( %f, %f) and ( %f, %f)\n", x1, y1, x2, y2);
            if (r1 * r1 + r2 * r2 == d * d)
            {
                printf("Two circles intersect orthogonally\n");
                printf("Equation of circle that passes from both the centres and the point of intersection is :\n");
                printf("( x - %f ) ^ 2 + ( y - %f ) ^ 2 = %f \n", -(a1 + a2) / 4, -(b1 + b2) / 4, d * d / 4);
                printf("Substituting both the intersection points in the new circle we get %f and %f", pow((x1 + a1 / 4 + a2 / 4), 2) + pow((y1 + b1 / 4 + b2 / 4), 2) - d * d / 4, pow((x2 + a1 / 4 + a2 / 4), 2) + pow((y2 + b1 / 4 + b2 / 4), 2) - d * d / 4);
            }
        }
    }

    return 0;
}