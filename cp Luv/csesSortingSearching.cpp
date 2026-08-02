#include <bits/stdc++.h>
using namespace std;

// Nearest Smaller Values
// void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     stack<pair<int, int>> s;
//     for(int i = 0; i < n; i++){
//         while(!s.empty() and s.top().first >= a[i]){
//             s.pop();
//         }
//         if(s.empty()){
//             cout << 0 << " ";
//         } else {
//             cout << s.top().second << " ";
//         }
//         s.push({a[i], i + 1});
//     }
// }

// Subarray Sums I
// void solve() {
//     int n, x;
//     cin >> n >> x;

//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     long long sum = 0;
//     int l = 0;
//     int ct = 0;

//     for(int r = 0; r < n; r++) {
//         sum += a[r];

//         while(sum > x) {
//             sum -= a[l];
//             l++;
//         }

//         if(sum == x) ct++;
//     }

//     cout << ct << "\n";
// }

// Subarray Sums II
// void solve(){
//     int n, x;
//     cin >> n >> x;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     long long count = 0;
//     long long sum = 0;
//     map<long long, long long> prefixSumCount;
//     prefixSumCount[0] = 1;

//     for(int i = 0; i < n; i++){
//         sum += a[i];
//         if(prefixSumCount.find(sum - x) != prefixSumCount.end()){
//             count += prefixSumCount[sum - x];
//         }
//         prefixSumCount[sum]++;
//     }
//     cout << count << "\n";
// }

//  Subarray Divisibility
// void solve(){
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     long long count = 0;
//     long long sum = 0;
//     map<long long, long long> ctMap;
//     ctMap[0] = 1;
//     for(int i = 0; i < n; i++){
//         // cout << "i: " << i << " " << "n" << n << " ";
//         sum += a[i];
//         // cout << "sum: " << sum << " ";
//         long long mod = sum % n;
//         if(mod < 0) mod += n;
//         // cout << "mod: " << mod << " ";
//         if(ctMap.find(mod) != ctMap.end()){
//             // cout << ctMap[mod] << " " << mod << " ";
//             count += ctMap[mod];
//         }
//         // cout << "\n";
//         ctMap[mod]++;
//     }
//     cout << count << "\n";
// }

// Array Division
// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     long long low = *max_element(a.begin(), a.end());
//     long long high = accumulate(a.begin(), a.end(), 0LL);

//     while(low <= high){
//         long long mid = low + (high - low) / 2;
//         long long curSum = 0;
//         long long sum = 1;
//         for(int i = 0; i < n; i++){
//             if(curSum + a[i] <= mid){
//                 curSum += a[i];
//             }else{
//                 sum++;
//                 curSum = a[i];
//             }
//         }
//         if(sum <= k){
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }
//     cout << low << "\n";    
// }


int main()
{
    int t = 1;
    // cin >> t;
    while(t--){
        // solve();
    }
    return 0;
}