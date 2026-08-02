#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{ // return the value that u want in sorting
    if (a.first != b.first)
        return (a.first < b.first); // here i want to ascending order sorting so i returned a. < b. i
    else
        return (a.second > b.second); // in case of the same first first in the pair imwant to return descending order so i returned a. > b.
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }

    return 0;
}