// Covid Rush
// HackerRank
// https://www.hackerearth.com/problem/algorithm/covid-rush/
// Will be continued

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<int> arrival(n), treatment(n);
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
        cin >> arrival[i];
    for (int i = 0; i < n; i++){
        cin >> treatment[i];
        vec.push_back(make_pair(arrival[i], treatment[i]));
    }
    sort(vec.begin(), vec.end());

    return 0;
}