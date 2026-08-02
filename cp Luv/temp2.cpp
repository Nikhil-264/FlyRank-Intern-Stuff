#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
    }

    vector<long long> sufMin(n);
    sufMin[n - 1] = a[n - 1];
    sum -= sufMin[n - 1];
    for (int i = n - 2; i >= 0; i--){
        sufMin[i] = min(sufMin[i + 1], a[i]);
        sum -= sufMin[i];
    }

    long long mx = -1;
    long long cur = 1;

    for(int i = 1; i < n; i++){
        if(sufMin[i] == sufMin[i - 1]){
            cur++;
        }
        else{
            mx = max(mx, cur);
            cur = 1;
        }
    }
    mx = max(mx, cur);
    cout << sum + mx - 1 << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}