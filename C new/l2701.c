// program to count duplicates
#include <stdio.h>
int main()
{
    int n, k = 0, count = 1;

    printf("enter the number of elements in array\n");
    scanf("%d", &n);
    printf("print elements in array\n");
    int array1[n];
    int array2[n];
    int array3[n];

    for (int i = 0; i < n; i++)
    {
        printf("element %d :", i);
        scanf("%d", &array1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        array2[i] = array1[i];
        array3[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array1[i] == array2[j])
            {
                array3[j] = count;
                count++;
            }
        }
        count = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (array3[i] == 2)
        {
            k++;
        }
    }
    printf(" number of Duplicated elements is : %d ", k);

    return 0;
}
