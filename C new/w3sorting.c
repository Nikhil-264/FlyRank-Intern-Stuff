// 38. Write a program in C to merge one sorted array into another sorted array. Go to the editor
// Pivot element is the only element in input array which is smaller than it's previous element.
// A pivot element divided a sorted rotated array into two monotonically increasing array.
// Expected Output :
// The given Large Array is : 10 12 14 16 18 20 22
// The given Small Array is : 11 13 15 17 19 21
// After merged the new Array is :
// 10 11 12 13 14 15 16 17 18 19 20 21 22
#include <stdio.h>
#include <stdlib.h>
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
void merge(int array1[], int n, int array2[], int m)
{
    int array3[m + n];
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < m)
    {
        if (array1[i] < array2[j])
        {
            array3[k] = array1[i];
            i++;
            k++;
        }
        else
        {
            array3[k] = array2[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        array3[k] = array1[i];
        k++;
        i++;
    }
    while (j < m)
    {
        array3[k] = array2[j];
        k++;
        j++;
    }

    print_array(array3, m + n);
}
int main()
{
    int n, m;
    printf("Enter the number of elements in array1 :");
    scanf("%d", &n);
    printf("Enter the members of array1\n");
    int array1[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array1[i]);
    }
    printf("Enter the number of elements in array2 :");
    scanf("%d", &m);
    printf("Enter the members of array2\n");
    int array2[m];
    for (int i = 0; i < m; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array2[i]);
    }
    bubblesort(array1, n);
    bubblesort(array2, m);
    merge(array1, n, array2, m);

    return 0;
}