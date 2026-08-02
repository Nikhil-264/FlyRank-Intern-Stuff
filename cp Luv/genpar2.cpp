#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> valid;
    void generate(string &s, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            valid.push_back(s);
            return;
        }

        if (open > 0)
        {
            s.push_back('(');
            generate(s, open - 1, close);
            s.pop_back();
        }

        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                generate(s, open, close - 1);
                s.pop_back();
            }
        }
    }

    vector<string> generate_parenthesis(int n)
    {
        string s = "";
        generate(s, n, n);
        return valid;
    }
};

int main()
{
    Solution ans;
    int n;
    cin >> n;
    vector<string> sol = ans.generate_parenthesis(n);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << endl;
    }
    
    return 0;
}