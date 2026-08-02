#include <stdio.h>
#include <stdlib.h>
// for binary search array has to be sorted
int binarysearch(int arr[], int size, int element)
{
    //time comlexity if O(log n) more efficient
    //while time complexity of linear search is O(n)
    int low = 0, mid, high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int ar[] = {0,1,2,4,5,6,7};
    int size = sizeof(ar) / sizeof(int);
    int element = 0;
    int searchindex = binarysearch(ar, size, element);
    printf("element found at %d ", searchindex);
    return 0;
}