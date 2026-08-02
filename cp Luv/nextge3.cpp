// Next greater element using stack O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
    vector<int> nge(nums.size());
    stack<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!st.empty() && nums[i] > nums[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    int i = 0;
    while (1)
    {
        if (nums[i] > nums[st.top()])
            break;
        if (i == st.top())
            break;
        i++;
    }
    if (i == st.top())
    {
        nge[st.top()] = -1;
        st.pop();
    }

    else
    {
        if (nums[i] > nums[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
    }

    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nge[i] == -1)
            ans[i] = -1;
        else
            ans[i] = nums[nge[i]];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> nge = nextGreaterElements(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    }
    return 0;
}