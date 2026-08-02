// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// 167. Two Sum II - Input Array Is Sorted
// Leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        int n = numbers.size();
        for (int i = 0; i < n; i++)
        {
            int k = target - numbers[i];
            int lo = 0, mid, hi = n - 1;
            while (lo <= hi)
            {
                mid = (hi + lo) / 2;
                if (i == mid)
                {
                    mid += 1;
                }
                if (target - numbers[i] == numbers[mid])
                {
                    ans.push_back(i + 1);
                    ans.push_back(mid + 1);
                    return ans;
                }
                else if (numbers[mid] > target - numbers[i])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}