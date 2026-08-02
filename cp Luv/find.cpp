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
        auto range = m.equal_range(target);
        if(it == m.end()){
            v.push_back(-1);
            v.push_back(-1);
        }
        else{
            it = range.first;
            v.push_back(it->second);
            it = range.second;
            --it;
            v.push_back(it->second);
        }
        return v;
    }
};
int main()
{

    return 0;
}