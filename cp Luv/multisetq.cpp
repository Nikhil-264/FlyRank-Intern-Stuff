#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        long long ans = 0;
        cin >> n >> k;
        multiset<long long> s;
        for (int i = 0; i <= n; ++i)
        {
            long long x;
            cin >> x;
            s.insert(x);
        }
        for(int i = 0; i < k; i++)
        {
            auto it = (--s.end());
            ans += (*it);
            s.erase(it);
            s.insert((*it) / 2);
        }
        cout << ans << endl;
    }
    return 0;
}