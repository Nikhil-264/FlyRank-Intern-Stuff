// find if the element is in the array or not if yes return index otherewise return -1 take input as number to be find number of elements in array and array
#include <stdio.h>
#include <stdlib.h>
int findary()
{
    int n, num;
    printf("Enter the number to be found :");
    scanf("%d", &num);
    printf("Enter the number of elements in array :");
    scanf("%d", &n);
    printf("Enter the members of array\n");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] != num)
        {
            if (i == n - 1)
            {
                return -1;
            }
            else
            {
                continue;
            }
        }
        if (array[i] == num)
        {
            return i;
        }
    }
}
int main()
{
    printf("%d", findary());
    return 0;
}
//you can do it by binary search