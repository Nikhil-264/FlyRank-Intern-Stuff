#include <stdio.h>
#include <math.h>

int main()
{
    int radius = 5;
    int center_x = 0;
    int center_y = 0;
    int x, y;
    float distance;

    for (y = -radius; y <= radius; y++)
    {   for (x = -radius; x <= radius; x++)
        {
            distance = sqrt(pow(x - center_x, 2) + pow(y - center_y, 2));
            if (distance <= radius)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}
