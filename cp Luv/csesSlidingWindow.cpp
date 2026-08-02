#include <bits/stdc++.h>
using namespace std;

// Sliding Window problems from CSES

// // Sliding Window Sum
// void solve(){
//     int n, k;
//     cin >> n >> k;
//     long long x, a, b, c;
//     cin >> x >> a >> b >> c;
//     vector<long long> arr;
//     arr.push_back(x);
//     for(int i = 0; i < n - 1; i++){
//         x = (a * x + b) % c;
//         arr.push_back(x);
//     }
//     long long Xor = 0;
//     long long sum = 0;
//     for(int i = 0; i < k; i++){
//         sum += arr[i];
//     }
//     Xor = sum;
//     for(int i = k; i < n; i++){
//         sum += arr[i] - arr[i - k];
//         Xor ^= sum;
//     }
//     cout << Xor << "\n";
// }

// // Sliding Window Minimum
// void solve(){
//     int n, k;
//     cin >> n >> k;
//     long long x, a, b, c;
//     cin >> x >> a >> b >> c;
//     vector<long long> arr;
//     arr.push_back(x);
//     for(int i = 0; i < n - 1; i++){
//         x = (a * x + b) % c;
//         arr.push_back(x);
//     }

//     deque<pair<long long, int>> dq;
//     int result = 0;
//     for(int i = 0; i < n; i++){
//         while(!dq.empty() and dq.back().first >= arr[i]){
//             dq.pop_back();
//         }
//         dq.push_back({arr[i], i});

//         if(i - k >= dq.front().second){
//             dq.pop_front();
//         }
//         if(i >= k - 1){
//             result ^= dq.front().first;
//         }
//     }
//     cout << result << "\n";
// }

// Sliding Window Xor
// void solve(){
//     int n, k;
//     cin >> n >> k;
//     long long x, a, b, c;
//     cin >> x >> a >> b >> c;
//     vector<long long> arr;
//     arr.push_back(x);
//     for(int i = 0; i < n - 1; i++){
//         x = (a * x + b) % c;
//         arr.push_back(x);
//     }
//     long long result = 0;
//     long long XOR = 0;
//     int start = 0;
//     for(int i = 0; i < n; i++){
//         XOR ^= arr[i];
//         if(i - start + 1 > k){
//             XOR ^= arr[start];
//             start++;
//         }
//         if(i - start + 1 == k){
//             result ^= XOR;
//         }
//     }
//     cout << result << "\n";
// }

// Sliding Window Distinct Values
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int, int> freq;
    // First window
    for(int i = 0; i < k; i++){
        freq[a[i]]++;
    }
    int ct = freq.size();
    cout << ct << " ";
    for(int i = k; i < n; i++){
        freq[a[i - k]]--;
        if(freq[a[i - k]] == 0){
            freq.erase(a[i - k]);
        }
        freq[a[i]]++;
        ct = freq.size();
        cout << ct << " ";
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