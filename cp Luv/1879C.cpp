#include <bits/stdc++.h>
using namespace std;

long long fact(int n)
{
    if (n == 0 or n == 1)
        return 1;
    return ((n % 998244353) * (fact(n - 1) % 998244353)) % 998244353;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int rep = 0;
        long long sec = 1;
        int fir = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            rep++;
            if (s[i] != s[i + 1])
            {
                sec = ((sec % 998244353) * (fact(rep) % 998244353)) % 998244353;
                fir += (rep - 1);
                rep = 0;
            }
        }
        if (s[s.size() - 1] == s[s.size() - 2])
        {
            rep++;
            sec = ((sec % 998244353) * (fact(rep) % 998244353)) % 998244353;
            fir += (rep - 1);
            rep = 0;
        }
        cout << fir << " " << sec << endl;
    }
    return 0;
}