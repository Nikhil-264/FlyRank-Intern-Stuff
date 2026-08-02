#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v;
        multimap<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m.insert(make_pair(nums[i], i));
        }
        auto it = m.find(target);
        if (it == m.end())
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        else
        {
            v.push_back(it->second + 1);
            v.push_back(nums.size() + 1 -(it->second + 1));
        }
        return v;
    }
};

int main()
{

    return 0;
}