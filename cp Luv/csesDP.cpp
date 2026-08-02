#include <bits/stdc++.h>
using namespace std;

// CSES DP problem set solutions
// Dive Combinations
// void solve(){
//     int n;
//     cin >> n;
//     vector<long long> dp(n + 1, 0);
//     dp[0] = 1;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= 6; j++){
//             if(i - j >= 0){
//                 dp[i] = (dp[i] + dp[i - j]) % 1000000007;
//             }
//         }
//     }
//     cout << dp[n] << "\n";
// }

// Minimizing Coins
// long long dpArray(int sum, vector<int> &a, vector<long long> &dp){
//     if(sum == 0) return 0;
//     if(sum < 0) return 1e18;

//     int n = a.size();

//     if(dp[sum] != -1) return dp[sum];
//     long long ans = 1e18;
//     for(int i = 0; i < n; i++){
//         ans = min(ans, 1 + dpArray(sum - a[i], a, dp));
//     }

//     return dp[sum] = ans;
// }

// void solve(){
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<long long> dp(x + 1, -1);
//     long long ans = dpArray(x, a, dp);
//     if(ans >= 1e9) cout << -1 << "\n";
//     else cout << ans << "\n";
// }

// // Coin Combinations I
// void solve(){
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<long long> dp(x + 1, 0);
//     dp[0] = 1;

//     for(int i = 1; i <= x; i++){
//         for(int j = 0; j < n; j++){
//             if(i - a[j] >= 0){
//                 dp[i] = (dp[i] + dp[i - a[j]]) % 1000000007;
//             }
//         }
//     }
//     cout << dp[x] << "\n";
// }

// // Coin Combinations II
// long long dpArray(int index, int sum, vector<int> &a, vector<vector<long long>> &dp){
//     if(sum == 0) return 1;
//     if(sum < 0) return 0;
//     if(index < 0) return 0;

//     int n = a.size();
//     if(dp[index][sum] != -1) return dp[index][sum];

//     int notTake = dpArray(index - 1, sum, a, dp);
//     int take = 0;
//     if(sum - a[index] >= 0) take = dpArray(index, sum - a[index], a, dp);
//     return dp[index][sum] = (notTake + take) % 1000000007;
// }

// void solve(){
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     // Tabulation
//     // vector<long long> dp(x + 1, 0);
//     // dp[0] = 1;
//     // for(int i = 0; i < n; i++){
//     //     for(int j = a[i]; j <= x; j++){
//     //         dp[j] = (dp[j] + dp[j - a[i]]) % 1000000007;
//     //     }
//     // }
//     // cout << dp[x] << "\n";
//     // Memoization // gives runtime errror
//     // vector<vector<long long>> dp(n, vector<long long>(x + 1, -1));
//     // long long ans = dpArray(n - 1, x, a, dp);
//     // cout << ans << "\n";
// }

// // Removing Digits
// void solve(){
//     int n;
//     cin >> n;
    
//     int ans = 0;
//     while(n > 0){
//         int temp = n;
//         int maxDigit = 0;
//         while(temp > 0){
//             maxDigit = max(maxDigit, temp % 10);
//             temp /= 10;
//         }
//         ans++;
//         n -= maxDigit;
//     }
//     cout << ans << "\n";
// }

// // Grid Paths I
// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<char>> grid(n, vector<char>(n));
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> grid[i][j];
//         }
//     }
//     vector<vector<long long>> dp(n, vector<long long>(n, 0));
//     for(int i = 0; i < n; i++){
//         if(grid[i][0] == '*') break;
//         dp[i][0] = 1;
//     }
//     for(int j = 0; j < n; j++){
//         if(grid[0][j] == '*') break;
//         dp[0][j] = 1;
//     }
//     for(int i = 1; i < n; i++){
//         for(int j = 1; j < n; j++){
//             if(grid[i][j] == '*') continue;
//             dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
//         }
//     }
//     cout << dp[n - 1][n - 1] << "\n";
// }

// // Book Shop
// // Memoization gives runtime error
// // long long dpFunction(int index, int sum, vector<int> &price, vector<int> &pages, vector<vector<long long>> &dp){
// //     if(index < 0) return 0;
// //     if(sum == 0) return 0;
// //     if(dp[index][sum] != -1) return dp[index][sum];

// //     long long notTake = dpFunction(index - 1, sum, price, pages, dp);
// //     long long take = 0;
// //     if(sum - price[index] >= 0) take = pages[index] + dpFunction(index - 1, sum - price[index], price, pages, dp);

// //     return dp[index][sum] = max(notTake, take);
// // }
// void solve(){
//     int n, x;
//     cin >> n >> x;
//     vector<int> price(n), pages(n);
//     for(int i = 0; i < n; i++){
//         cin >> price[i];
//     }
//     for(int i = 0; i < n; i++){
//         cin >> pages[i];
//     }
//     // Memoization gives runtime error
//     // vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -1));
//     // long long ans = dpFunction(n - 1, x, price, pages, dp);
//     // cout << ans << "\n";

//     // Tabulation give runtime error
//     // vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
//     // for(int i = 1; i <= n; i++){
//     //     for(int j = 1; j <= x; j++){
//     //         long long notTake = dp[i - 1][j];
//     //         long long take = 0;
//     //         if(j - price[i - 1] >= 0) take = pages[i - 1] + dp[i - 1][j - price[i - 1]];
//     //         dp[i][j] = max(notTake, take);
//     //     }
//     // }
//     // cout << dp[n][x] << "\n";

//     // Tabulation space optimized
//     // vector<long long> dp(x + 1, 0);
//     // for(int i = 0; i < n; i++){
//     //     for(int j = x; j >= price[i]; j--){
//     //         dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
//     //     }
//     // }

//     // cout << dp[x] << "\n";
// }

// Array Description
// long long dpFunction(int index, int prev, vector<int> &a, vector<vector<long long>> &dp, int m){
//     if(index == a.size()) return 1;

//     if(dp[index][prev] != -1){
//         return dp[index][prev];
//     }

//     long long ways = 0;
//     if(a[index] == 0){
//         for(int val = prev - 1; val <= prev + 1; val++){
//             if(val >= 1 and val <= m)
//                 ways = (ways + dpFunction(index + 1, val, a, dp, m)) % 1000000007;
//         }
//     }else{
//         if(index == 0 or abs(a[index] - prev) <= 1){
//             ways = dpFunction(index + 1, a[index], a, dp, m);
//         }
//     }
//     return dp[index][prev] = ways;
// }
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<vector<long long>> dp(n, vector<long long>(m + 1, -1));
//     long long ans = 0;
//     if(a[0] == 0){
//         for(int i = 1; i <= m; i++){
//             ans = (ans + dpFunction(1, i, a, dp, m)) % 1000000007;
//         }
//     }else{
//         ans = dpFunction(1, a[0], a, dp, m);
//     }
//     cout << ans << "\n";
// }

// // Counting Towers
// void solve(){
//     int n = 1e6;
//     vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

//     dp[1][0] = 1;
//     dp[1][1] = 1;

//     for(int i = 2; i <= n; i++){
//         dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
//         dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % 1000000007;
//     }
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         cout << (dp[n][0] + dp[n][1]) % 1000000007 << "\n";
//     }
//     return;
// }

// // Edit Distance
// void solve(){
//     string a, b;
//     cin >> a >> b;
//     int n = a.size(), m = b.size();
//     vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
//     for(int i = 0; i <= n; i++) dp[i][0] = i;
//     for(int j = 0; j <= m; j++) dp[0][j] = j;

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(a[i - 1] == b[j - 1]){
//                 dp[i][j] = dp[i - 1][j - 1];
//             }else{
//                 dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
//             }
//         }
//     }
//     cout << dp[n][m] << "\n";
// }

// // Longest Common Subsequence
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n), b(m);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < m; i++){
//         cin >> b[i];
//     }
//     vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(a[i - 1] == b[j - 1]){
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             }else{
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     vector<int> ans;
//     int j = n, k = m;
//     while(j > 0 and k > 0){
//         if(a[j - 1] == b[k - 1]){
//             ans.push_back(a[j - 1]);
//             j--;
//             k--;
//         }else if(dp[j - 1][k] > dp[j][k - 1]){
//             j--;
//         }else{
//             k--;
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     cout << ans.size() << "\n";
//     for(int i = 0; i < ans.size(); i++){
//         cout << ans[i] << " ";
//     }
//     cout << "\n";
// }

// Cutting Rectangles
// Recursion will give tle
// long long dpFunction(int n, int m, vector<vector<long long>> &dp){
//     if(n == m) return 0;
//     if(dp[n][m] != -1) return dp[n][m];
//     long long ans = 1e18;
//     for(int i = 1; i < n; i++){
//         ans = min(ans, 1 + dpFunction(i, m, dp) + dpFunction(n - i, m, dp));
//     }   
//     for(int j = 1; j < m; j++){
//         ans = min(ans, 1 + dpFunction(n, j, dp) + dpFunction(n, m - j, dp));
//     }
//     return dp[n][m] = ans;
// }
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e9));

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(i == j) dp[i][j] = 0;
//             else{
//                 for(int k = 1; k < i; k++){
//                     dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
//                 }
//                 for(int k = 1; k < j; k++){
//                     dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
//                 }
//             }
//         }
//     }
//     cout << dp[n][m] << "\n";
// }

// // Money Sums
// void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
    
//     int sum = 0;
//     set<int> ans;
//     for(int i = 0; i < n; i++){
//         sum += a[i];
//         set<int> temp;
//         for(auto it : ans){
//             temp.insert(it);
//             temp.insert(it + a[i]);
//         }
//         temp.insert(a[i]);
//         ans = temp;
//     }
//     cout << ans.size() << "\n";
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     cout << "\n";
// }

// // Increasing Subsequence
// void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<int> temp = {a[0]};
//     for(int i = 1; i < n; i++){
//         if(temp.back() < a[i]){
//             temp.push_back(a[i]);
//         }else{
//             int index = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
//             temp[index] = a[i];
//         }
//     }
//     cout << temp.size() << "\n";
// }

// // Removal Game
// void solve(){
//     int n;
//     cin >> n;

//     vector<long long> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     vector<vector<long long>> dp(n, vector<long long>(n, 0));

//     // base case
//     for(int i = 0; i < n; i++) dp[i][i] = a[i];

//     for(int len = 2; len <= n; len++){
//         for(int i = 0; i + len - 1 < n; i++){
//             int j = i + len - 1;

//             long long x = (i+2 <= j) ? dp[i+2][j] : 0;
//             long long y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
//             long long z = (i <= j-2) ? dp[i][j-2] : 0;

//             dp[i][j] = max(
//                 a[i] + min(x, y),
//                 a[j] + min(y, z)
//             );
//         }
//     }

//     cout << dp[0][n-1] << "\n";
// }

// // Two sets II
// void solve(){
//     int n;
//     cin >> n;
//     long long sum = (1LL * n * (n + 1)) / 2;
//     if(sum % 2 != 0){
//         cout << 0 << "\n";
//         return;
//     }
//     sum /= 2;
//     vector<long long> dp(sum + 1, 0);
//     dp[0] = 1;
//     for(int i = 1; i <= n; i++){
//         for(int j = sum; j >= i; j--){
//             dp[j] = (dp[j] + dp[j - i]) % 1000000007;
//         }
//     }
//     cout << (1LL * dp[sum] * 500000004 % 1000000007) << "\n";
//     return;
// }

// Projects
bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> price(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> price[i][j];
        }
    }
    sort(price.begin(), price.end(), cmp);

    vector<long long> endTimes(n);
    for(int i = 0; i < n; i++){
        endTimes[i] = price[i][1];
    }
    vector<long long> dp(n);
    for (int i = 0; i < n; i++){
        long long take = price[i][2];
        int index = upper_bound(endTimes.begin(), endTimes.end(), price[i][0] - 1) - endTimes.begin() - 1;

        if(index >= 0){
            take += dp[index];
        }
        long long notTake = (i > 0) ? dp[i - 1] : 0;
        dp[i] = max(take, notTake);
    }
    cout << dp[n - 1] << "\n";
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