#include <bits/stdc++.h>
using namespace std;
const int M = 10000007;

int binExpItr(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b = (b >> 1);
    }
    return ans;
}

int main()
{
    long long n, k;
    while (1)
    {
        cin >> n >> k;
        if(n == 0 and k == 0) break;
        // long long s = 0, p = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     s = (s + binExpItr(i, k)) % M;
        //     p = (p + binExpItr(i, i)) % M;
        // }
        // int z1 = (s + p) % M;
        // int z2 = (z1 % M - (binExpItr(n, k) % M + binExpItr(n, n) % M) % M + M) % M;
        // int z3 = (z2 % M - (binExpItr(n - 1, k) % M + binExpItr(n - 1, n - 1) % M) % M + M) % M;
        // cout << ((z1 + z2) % M - (2 * z3) % M + M) % M << endl;
        long long ans = ((2 * ((binExpItr(n - 1, k) + binExpItr(n - 1, n - 1)) % M)) % M + (binExpItr(n, k) + binExpItr(n, n)) % M) % M;
        cout << ans << endl;
    }

    return 0;
}