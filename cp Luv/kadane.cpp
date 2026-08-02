// Kadane's Algorithm
// maximum subsarray summation

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long sum = 0, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
        }
        if(sum <= 0){
            sum = 0;
        }
    }
    return maxi;
}

// int main()
// {
//     long long sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//     }
        
//     return 0;
// }