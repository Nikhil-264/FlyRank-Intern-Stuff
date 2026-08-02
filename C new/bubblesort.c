#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void print_array(int array[], int n)
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
    bubblesort(array, n);
    print_array(array, n);

    return 0;
}