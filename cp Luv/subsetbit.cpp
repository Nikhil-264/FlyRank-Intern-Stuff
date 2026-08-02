#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subset_ct = (1 << n);
    set<vector<int>> ans_temp;
    vector<vector<int>> ans;
    for (int i = 0; i < subset_ct; ++i)
    {
        vector<int> sub;
        for (int j = 0; j < n; j++)
            if ((i & (1 << j)) != 0)
                sub.push_back(nums[j]);
        ans_temp.insert(sub);
    }
    // return ans_temp;
    for (auto &vec : ans_temp)
    {
        ans.push_back(vec);
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
    auto subsets_all = subsets(nums);
    for (auto& innerVector : subsets_all) {
        for (int element : innerVector) {
            cout << element << " ";
        }
        cout << endl; 
    }
    return 0;
}
