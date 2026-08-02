#include <stdio.h>

// swapping funtion
void swap(int *x, int *y)
{
    int refer;
    refer = *x;
    *x = *y;
    *y = refer;
}

// selecting minimum number from aray function
void select_min(int array[], int n)
{
    int i, j, min_index;
    for (int i = 0; i < n; i++) // n-1 because loop will run one time less than number of elemenmts in array
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_index]) // if nth element is less than min_index element min_index changes to that number
            {
                min_index = j;
            }
        } 
        swap(&array[min_index], &array[i]);
    }
}

// printing final array
void print_array(int *array, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);
    printf("Enter the members of array\n");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("element %d = ", i);
        scanf("%d", &array[i]);
    }
    select_min(array, n);
    print_array(array, n);

    return 0;
}