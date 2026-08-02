#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long pfs[N];
int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pfs[i] = pfs[i - 1] + a[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << pfs[r] - pfs[l-1] << endl;
    }
    return 0;
} 