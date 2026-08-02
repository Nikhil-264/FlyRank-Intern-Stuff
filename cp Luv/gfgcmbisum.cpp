#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> final_ans;

    void generate(vector<int> &A, int B, int index, vector<int> &temp)
    {
        if (B == 0)
        {
            final_ans.push_back(temp);
            return;
        }

        if (B < 0 || index >= A.size())
        {
            return;
        }

        // Include the current element
        temp.push_back(A[index]);
        generate(A, B - A[index], index, temp);

        // Exclude the current element and skip duplicates
        while (index + 1 < A.size() && A[index] == A[index + 1])
        {
            index++;
        } // this part was given b vhat gpt that u didnt understand so
        temp.pop_back();
        generate(A, B, index + 1, temp);
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        sort(A.begin(), A.end());
        vector<int> temp;
        generate(A, B, 0, temp);
        return final_ans;
    }
};

int main()
{
    Solution ok;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int B;
    cin >> B;
    vector<vector<int>> a = ok.combinationSum(arr, B);
    for (auto it = a.begin(); it != a.end(); it++)
    {
        for (int i = 0; i < (*it).size(); ++i)
        {
            cout << (*it)[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
