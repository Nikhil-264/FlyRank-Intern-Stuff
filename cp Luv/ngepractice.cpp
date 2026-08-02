// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

// Constraints:

// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &n1, vector<int> &n2)
    {
        stack<int> st;
        unordered_multimap<int, int> um;
        for (int i = 0; i < n2.size(); i++)
        {
            while (!st.empty() && st.top() < n2[i])
            {
                um.insert({st.top(), n2[i]});
                st.pop();
            }
            st.push(n2[i]);
        }
        while (!st.empty())
        {
            um.insert({st.top(), -1});
            st.pop();
        }
        vector<int> v;
        for (int i = 0; i < n1.size(); i++)
        {
            v.push_back((um.find(n1[i]))->second);
        }
        return v;
    }
};

int main()
{
    vector<int> n1 = {2, 4};
    vector<int> n2 = {1, 2, 3, 4};
    Solution ans;
    vector<int> sol = ans.nextGreaterElement(n1, n2);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
    return 0;
}