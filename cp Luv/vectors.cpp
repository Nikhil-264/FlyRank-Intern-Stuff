#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int ct = 0;
        int sum = 0;
        int flag = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > k)
                flag = -1;
            do
            {
                sum += a[i];
                i++;
            } while (sum <= k);
            sum = 0;
            ct++;
        }
        if (flag != -1)
            cout << ct << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
