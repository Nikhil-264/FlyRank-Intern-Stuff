#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string, int> m;
    while (q--)
    {
        int a;
        cin >> a;
        string s;
        cin >> s;
        if (a == 1)
        {
            int x;
            cin >> x;
            m[s] += x;
        }
        else if (a == 2)
        {
            m[s] = 0;
        }
        else if (a == 3)
        {
            cout << m[s] << endl;
        }
    }
    return 0;
}