// quick sort
// pick a pivet element and put it in its correct sopt in sorted array
// Code : 
#include <bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
        while(arr[i] <= pivot and i <= high){
            i++;
        }
        while(arr[j] > pivot and j >= low){
            j--;
        } 
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    cout << endl;
    
    
    return 0;
}