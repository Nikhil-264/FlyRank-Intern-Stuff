#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first != b.first)
    {
        return (a.second > b.second);
    }
    else
        return (a.second < b.second);
}

int main()
{
    string s;
    cin >> s;
    vector<pair<int, char>> a(52);
    for (char i = 'A'; i <= 'Z'; i++)
    {
        int ct = count(s.begin(), s.end(), i);
        a[i - 'A'] = (make_pair(ct, i));
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        int ct = count(s.begin(), s.end(), i);
        a[i - 'a' + 26] = (make_pair(ct, i));
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < 52; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    
    return 0;
}