// Codeforces
// Infectious Letters
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string s, int index)
    {
        if (count(s.begin(), s.end(), 'a') + count(s.begin(), s.end(), 'b') == s.size())
            return count(s.begin(), s.end(), 'a');
        if (index == s.size())
            return count(s.begin(), s.end(), 'a');
        if (s[index] == 'a')
        {
            if (s[index - 1] != 'b')
                s[index - 1] = 'a';
            if (s[index + 1] != 'b')
            {
                s[index + 1] = 'a';
                solve(s, index + 1);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    Solution a;
    int ans = a.solve(s, 1);
    cout << ans << endl;

    return 0;
}