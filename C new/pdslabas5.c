/************************************
// Name : Nikhil Mahindrakar
// Roll no : 22CH10036
// Section : 6
// Assignment : 5
// Description : Pointer and DMA
// Date  :   12 May 2023,friday
*************************************/
#include <stdio.h>
#include <stdlib.h>
int *init(int *list)
{
    list = NULL;
    return list;
}
int *prepend(int *arr, int a, int n)
{
    printf("Enter the element you want to add :");
    scanf("%d", &a);
    n++;
    arr = (int *)realloc(arr, (n) * sizeof(int));
    for (int i = n; i > 0; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    arr[0] = a;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return arr;
}
int *insertmid(int *arr, int a, int n)
{
    printf("Enter the element you want to add in the middle :");
    scanf("%d", &a);
    n++;
    arr = (int *)realloc(arr, (n) * sizeof(int));
    for (int i = n; i > n / 2; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    arr[n / 2] = a;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return arr;
}
int *deletemid(int *arr, int n)
{
    if (n % 2 == 0)
    {
        for (int i = n / 2 - 1; i < n - 2; i++)
        {
            *(arr + i) = *(arr + i + 2);
        }
        n = n - 2;
        arr = (int *)realloc(arr, (n) * sizeof(int));
    }
    else
    {
        for (int i = n / 2; i < n - 1; i++)
        {
            *(arr + i) = *(arr + i + 1);
        }
        n--;
        arr = (int *)realloc(arr, (n) * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return arr;
}
int *deletelast(int *arr, int n)
{
    n = n - 1;
    arr = (int *)realloc(arr, (n) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return arr;
}
void deleteall(int *arr, int n, int a)
{
    printf("Enter the element to be removed : ");
    scanf("%d", &a);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
            count++;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            for (int j = i; j < n; j++)
            {
                *(arr + i) = *(arr + i + 1);
            }
            i--;
            // arr = (int *)realloc(arr, (n - 1) * sizeof(int));
        }
    }
    n -= count;
    arr = (int *)realloc(arr, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
int *remove_duplicate(int *arr, int n)
{

    int j = 0;
    int *counted = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        counted[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (counted[i] == 1)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                counted[j] = 1;
            }
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if ((*(counted + i)) == 0)
            k++;
    }
    int *ar = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if ((*(counted + i)) == 0)
        {
            *(ar + i) = *(arr + i);
            printf("%d ", *(ar + i));
        }
    }

    return arr;
}
int main()
{
    int *arr;
    init(arr);
    int n;
    int a;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Executing prepend... \n");
    arr = prepend(arr, a, n);
    n++;
    printf("Executing insertmid... \n");
    arr = insertmid(arr, a, n);
    n++;
    printf("Executing deletemid... \n");
    arr = deletemid(arr, n);
    printf("Executing deletelast...\n");
    arr = deletelast(arr, n);
    printf("Executing deleteall...\n");
    deleteall(arr, n, a);
    arr = remove_duplicate(arr, n);

    return 0;
}
