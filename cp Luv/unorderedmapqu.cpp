// Given N strings and Q querries, in each query you are given a string print frequency of that string
// n <= 10^5
// |S| <= 100
// Q <= 10^6

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // we are only usiong here unreerd maps to save time complexity
    unordered_map<string, int> m;
    multimap<pair<int, int>, string> w;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        cout << m[s] << endl;
    }
    return 0;
}