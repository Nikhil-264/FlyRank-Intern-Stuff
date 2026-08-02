#include <stdio.h>

int secondMinimum(int arr[], int n) {
    int min = arr[0], secMin = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            secMin = min;
            min = arr[i];
        }
        else if (arr[i] < secMin && arr[i] != min) {
            secMin = arr[i];
        }
    }
    return secMin;
}

int secondMaximum(int arr[], int n) {
    int max = arr[0], secMax = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            secMax = max;
            max = arr[i];
        }
        else if (arr[i] > secMax && arr[i] != max) {
            secMax = arr[i];
        }
    }
    return secMax;
}

int main() {
    int n, i;
    int arr[n];
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // read the elements
    }
    
    printf("The array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // print the elements
    }
    
    printf("\nSecond minimum element: %d", secondMinimum(arr, n));
    printf("\nSecond maximum element: %d", secondMaximum(arr, n));
    
    free(arr); // free the dynamically allocated memory
    
    return 0;
}
