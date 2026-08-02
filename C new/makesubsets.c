// return  number of susets and elements of subsets
// not completed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    // printf("the number of subsets are %f\n", pow(2, 3));
    int n;
    printf("Enter the number of elements in array :");
    scanf("%d", &n);
    printf("Enter the members of array\n");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array[i]);
    }
    printf("the number of subsets are %.1f\n", pow(2, n));
    printf("The subsets are as follows : \n{ } ");

    printf(" {");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("}");

    return 0;
}