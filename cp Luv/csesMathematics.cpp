#include <bits/stdc++.h>
using namespace std;
// Mathematics section CSES

// // Josephus Queries
// long long solve1(long long n, long long k) {
//     if (n == 1) return 1;

//     long long half = n / 2;

//     // First phase: evens removed
//     if (k <= half) {
//         return 2 * k;
//     }

//     // Second phase
//     long long res = solve1(n - half, k - half);

//     if (n % 2 == 0) {
//         return 2 * res - 1;
//     } else {
//         // rotation fix
//         if (res == 1) return n;
//         return 2 * res - 3;
//     }
// }

// void solve(){
//     long long n, k;
//     cin >> n >> k;
//     long long ans = solve1(n, k);
//     cout << ans << endl;
// }

// // Exponentiation
// void solve(){
//     int a, b;
//     int mod = 1e9 + 7;
//     cin >> a >> b;
//     long long ans = 1;
//     long long base = a;
//     while(b > 0){
//         if(b & 1){
//             ans = (ans * base) % mod;
//         }
//         base = (base * base) % mod;
//         b >>= 1;
//     }
//     cout << ans << endl;
// }

// // Exponentiation II
// void solve(){
//     int a, b, c;
//     cin >> a >> b >> c;
//     int mod = 1e9 + 7;
//     long long ans = 1;
//     long long base = b;
//     while(c > 0){
//         if(c & 1){
//             ans = (ans * base) % (mod - 1);
//         }
//         base = (base * base) % (mod - 1);
//         c >>= 1;
//     }
//     long long finalAns = 1;
//     base = a;
//     while(ans > 0){
//         if(ans & 1){
//             finalAns = (finalAns * base) % mod;
//         }
//         base = (base * base) % mod;
//         ans >>= 1;
//     }
//     cout << finalAns << endl;
// }

// // Counting Divisors
// void solve(){
//     int n;
//     cin >> n;
//     long long ans = 1;
//     for(int i = 2; i * i <= n; i++){
//         int ct = 0;
//         while(n % i == 0){
//             n /= i;
//             ct++;
//         }
//         ans *= (ct + 1);
//     }
//     if(n > 1) ans *= 2;
//     cout << ans << endl;
// }

// Common Divisors
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maxi = 1e6;
    vector<int> freq(maxi + 1, 0);
    for(int i = 0; i < n; i++) freq[a[i]]++;

    for(int g = maxi; g >= 1; g--){
        int multiples = 0;
        for(int i = g; i <= maxi; i += g){
            multiples += freq[i];
        }
        if(multiples >= 2){
            cout << g << endl;
            return;
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}