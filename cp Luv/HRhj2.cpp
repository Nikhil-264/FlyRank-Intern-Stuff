// Help Joe II
// HackerRank
// 3rd Competitive Programming Contest(STL) Question 1
// https://www.hackerearth.com/problem/algorithm/help-joe-ii/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] % m;
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    int ans;
    while (q--)
    {
        long long x;
        cin >> x;
        x %= m;
        vector<long long>::iterator ptr = upper_bound(a.begin(), a.end(), m - x - 1, less<long long>());
        if (ptr != a.begin())
            ptr--;
        cout << max((a[n - 1] + x) % m, (*ptr + x) % m) << endl;
    }
    return 0;
}
