// Luffy Needs Food
// HackerRank
// 3rd Competitive Programming Contest(STL) Question 3
// https://www.hackerearth.com/problem/algorithm/luffy-needs-food/
// Incomplete

#include <bits/stdc++.h>
using namespace std;

bool Descending(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k, f;
        cin >> k >> f;
        // set<pair<int, int>> il;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
            // il.insert(v[i]);
        }
        sort(v.begin(), v.end(), Descending);
        // for (const auto& pr : v) {
        // cout << "(" << pr.first << ", " << pr.second << ")" << endl;
        // }
        int more_food = INT_MIN;
        int flag = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            more_food = max(more_food, v[i].second);
            if((k - v[i].second) > f) {
                if(more_food != INT_MIN){
                    f += more_food;
                    ans++;
                }
                else {
                    flag = 1;// cout  -1
                    break;
                }
            }
            f -= (k - v[i].first);
            k = v[i].second;
        }
        if(flag == 1)   
            cout << -1 << endl;
        else{
            cout << ans << endl;
        }
    }
    return 0;
}