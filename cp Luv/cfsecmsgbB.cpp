#include <bits/stdc++.h>
using namespace std;

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<pair<char, int>> s_lower;
        stack<pair<char, int>> s_upper;
        vector<pair<char, int>> ans;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] >= 'a' and s[i] <= 'z'){
                if (s[i] == 'b' and !(s_lower.empty())){
                    s_lower.pop();
                }
                else if(s[i] != 'b'){
                    s_lower.push({s[i], i});
                }
            }
            if (s[i] >= 'A' and s[i] <= 'Z'){
                if (s[i] == 'B' and !(s_upper.empty())){
                    s_upper.pop();
                }
                else if(s[i] != 'B'){
                    s_upper.push({s[i], i});
                }
            }
        }
        while (!s_lower.empty() or !s_upper.empty())
        {
            if (!s_lower.empty()){
                ans.push_back(s_lower.top());
                s_lower.pop();
            }
            if (!s_upper.empty()){
                ans.push_back(s_upper.top());
                s_upper.pop();
            }
        }
        sort(ans.begin(), ans.end(), sortBySecond);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first;
        }
        cout << endl;
    }
    return 0;
}