#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void generate(vector<int> &subset, int i, vector<int> &nums)
{
    if (i == nums.size())
    {
        ans.push_back(subset);
        return;
    }

    // i'th element not including in subset;
    generate(subset, i + 1, nums);

    // i'th element including in subset
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums);
    subset.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> subset;
    generate(subset, 0, A);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}