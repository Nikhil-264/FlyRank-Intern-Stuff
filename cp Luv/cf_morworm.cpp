// B. Worms
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pre_sum(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        pre_sum[i] = sum;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        int ans;
        cin >> x;
        for (int i = 0; i < n; i++)
        {
            if (x <= pre_sum[i + 1])
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}