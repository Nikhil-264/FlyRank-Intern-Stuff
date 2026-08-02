// Too Lazy To Name Question II
// HackerRank
// 3rd Competitive Programming Contest(STL) Question 2
// https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question-ii/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> points_set;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        points_set.insert(p[i]);
    }
    int ar_min = INT_MAX, ar_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto p1 = p[i];
            auto p2 = p[j];
            // Checking only diagonal element
            if(p1.first == p2.first)continue;
            if(p1.second == p2.second)continue;
            // After confirming that the points selected are diagonal element we search for remaimning two points of the rectangle that they exist in set or not 
            int x1 = p1.first, y1 = p2.second;
            int x2 = p2.first, y2 = p1.second;
            // search x1, y1 ans x2, y2 in the set made
            if(points_set.count({x1, y1}) && points_set.count({x2, y2})){
                int ar = abs(x1 - x2) * abs(y1 - y2);
                ar_min = min(ar_min, ar);
                ar_max = max(ar_max, ar);
            }
        }
    }
    if(ar_max == INT_MIN) cout << -1 << endl;
    else cout << ar_max - ar_min << endl;
    

    return 0;
}
