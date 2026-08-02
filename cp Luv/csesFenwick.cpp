#include <bits/stdc++.h>
using namespace std;

class fenwick{
    vector<long long> bit;
    int n;
public:
    fenwick(int n) : n(n) , bit(n + 1, 0) {}

    void update(int i, long long delta){
        for(; i <= n; i += i & -i){
            bit[i] += delta;
        }
    }

    long long query(int i){
        long long sum = 0;
        for(; i > 0; i -= i & -i){
            sum += bit[i];
        }
        return sum;
    }
};

// Dynamic range sum queries
// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     fenwick fenw(n);
//     for(int i = 0; i < n; i++){
//         fenw.update(i + 1, a[i]);
//     }
//     for(int i = 0; i < q; i++){
//         int type;
//         cin >> type;
//         if(type == 2){
//             int a, b;
//             cin >> a >> b;
//             a--; b--;
//             long long ans = fenw.query(b + 1) - fenw.query(a);
//             cout << ans << "\n";
//         }else{
//             int k, val;
//             cin >> k >> val;
//             k--;
//             long long delta = val - a[k];
//             a[k] = val;
//             fenw.update(k + 1, delta);
//         }
//     }
// }

// Prefix sum queries
void solve(){
    
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}