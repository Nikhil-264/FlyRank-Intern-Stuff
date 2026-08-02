// Finding the Peak Element
// Leetcode
// Take U forward
// https://leetcode.com/problems/find-peak-element/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 1;
        if(nums[n - 1] > nums[n - 2]) return n - 1;
        int hi = n - 2, lo = 1, mid;
        while (lo <= hi){
            mid = (hi + lo) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid] > nums[mid - 1]) lo = mid + 1;
            else if(nums[mid] > nums[mid + 1]) hi = mid - 1;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}