#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;

double multiply(double mid, int n){
    double ans = 1;
    for (int i = 0; i < n; i++){
        ans *= mid;
    }
    return ans;
}

pair<double, double> find_root(double &x, int nth)
{
    double lo = 1, hi = x, mid;
    while (hi - lo > eps)
    {
        mid = (lo + hi) / 2;
        if (multiply(mid, nth) < x)
            lo = mid;
        else
            hi = mid;
    }
    return make_pair(lo, hi);
    // cout << setprecision(10) << lo << endl << hi << endl;
}

int main()
{
    double x;
    cout << "Enter Number : ";
    cin >> x;
    int nth;
    cout << "Enter which root u want : "; 
    cin >> nth;
    // cout << find_root(x) << endl;
    pair<double, double> ans = find_root(x, nth);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}