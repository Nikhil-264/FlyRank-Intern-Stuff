// Single Element In Sorted array
// Leetcode
// Take U forward
// Main logic : on the left side of the element the index of the element will be even odd respaectively and viceversa

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleElement(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        // We will identify the left half or right half by checking the odd and evn index part explained in the main desciption

        int lo = 1, hi = n - 2;// We treamed down the edges to avoid the edga conditions
        int mid;
        while (lo <= hi)
        {
            mid = (hi + lo) / 2;
            // Condition for the being n the left half
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid + 1] == nums[mid]))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution obj;
    cout << "The peak element is : " << obj.singleElement(a) << endl;

    return 0;
}