#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k, input, pro = 1;
        cin >> k;//if 10 takin 15 times int constarint will overflow so use long long
        while (k--)
        {
            cin >> input;
            pro *= input;
        }
        if (pro % 10 == 2 || pro % 10 == 3 || pro % 10 == 5)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}