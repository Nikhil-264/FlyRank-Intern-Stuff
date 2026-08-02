#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string str;
        cin >> str;
        if (s.find(str) == s.end())
        {
            cout << "no\n";
        }
        else
            cout << "Yes\n";
    }
    return 0;
}