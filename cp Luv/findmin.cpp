// Finding minimum element from the rotated sorted array
// Leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMin(vector<int>& nums){
        int lo = 0, hi = nums.size() - 1, mid;
        int ans = INT_MAX;
        while(lo <= hi){
            mid = (hi + lo) / 2;
            if(nums[lo] <= nums[hi]){
                ans = min(ans, nums[lo]);
                break;
            }
            if(nums[lo] <= nums[mid]){
                ans = min(nums[lo], ans);
                lo = mid + 1;
            }
            else {
                ans = min(nums[mid], ans);
                hi = mid - 1;
            }
        }  
        return ans;
    }
};

int main()
{
    // pickup the minimum element from the sorted part of the array and eliminate the soeted part y storing the minimum and go on comparing the minimum of each sorted array to get the final minimum element of the wholw array

    return 0;
}