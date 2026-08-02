#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    int k;
    k = (1 / sqrt(5.0)) * (pow((1 + sqrt(5.0)) / 2, n) - pow((1 - sqrt(5.0)) / 2, n));
    return k;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fibo(n) << endl;
    }
    return 0;
}