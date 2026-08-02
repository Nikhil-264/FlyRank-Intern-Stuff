#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return ((fact((n - 1))) * n);
}

int combi(int n, int r)
{
    int co = fact(n) / (fact(r) * fact(n - r));
    return co;
}

bool compareDecreasing(int a, int b)
{
    return a > b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a(11);
        for (auto &i : a)
            cin >> i;
        int k;
        cin >> k;
        sort(a.begin(), a.end(), compareDecreasing);
        // for (int i = 0; i < 11; ++i)
        // {
        // 	cout << a[i] << " ";
        // }
        // cout << endl;
        int ans = 0;
        for (int i = 0; i < 11; i++)
        {
            int ct = count(a.begin(), a.end(), a[i]);
            if (ct <= k)
            {
                k -= ct;
                i += ct - 1;
            }
            else if (k == 0)
            {
                ans = 1;
                break;
            }
            else
            {
                ans = combi(ct, k);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}