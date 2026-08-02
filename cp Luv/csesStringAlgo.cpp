#include <bits/stdc++.h>
using namespace std;

// vector<int> buildLPS(string s){
//     int n = s.size();
//     vector<int> lps(n, 0);

//     int i = 1, len = 0;

//     while(i < n){
//         if(s[i] == s[len]){
//             len++;
//             lps[i] = len;
//             i++;
//         }else{
//             if(len != 0){
//                 len = lps[len - 1];
//             }else{
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
//     return lps;
// }

// string matching
// void solve(){
//     string a, b;
//     cin >> a >> b;
//     vector<int> lps = buildLPS(b);
//     int i = 0, j = 0;
//     int n = a.size();
//     int m = b.size();
//     int ans = 0;
//     while(i < n){
//         if(a[i] == b[j]){
//             i++, j++;
//         }
//         if(j == m){
//             ans++;
//             j = lps[j - 1];
//         }
//         else if(i < n and a[i] != b[j]){
//             if(j != 0){
//                 j = lps[j - 1];
//             }else{
//                 i++;
//             }
//         }
//     }
//     cout << ans << "\n";
//     return;
// }

// // Finding borders
// void solve(){
//     string s;
//     cin >> s;

//     vector<int> lps = buildLPS(s);
//     vector<int> ans;

//     int border = lps.back();

//     while(border > 0){
//         ans.push_back(border);
//         border = lps[border - 1];
//     }

//     reverse(ans.begin(), ans.end());

//     for(int x : ans)
//         cout << x << " ";
// }

// Minimal rotations
// void solve(){
//     string s;
//     cin >> s;
//     string t = s + s;
//     int n = s.size();

//     int i=0, j=1, k=0;

//     while(i<n && j<n && k<n){
//         if(t[i+k]==t[j+k]){
//             k++;
//         }
//         else if(t[i+k] > t[j+k]){
//             i = i + k + 1;
//             if(i<=j) i = j+1;
//             k=0;
//         }
//         else{
//             j = j + k + 1;
//             if(j<=i) j = i+1;
//             k=0;
//         }
//     }

//     cout << t.substr(min(i,j), n) << "\n";
//     return;
// }

// Longest Palindrome
// O(n^2) appraoch
// int expand(string s, int left, int right){
//     int n = s.size();
//     while(left >= 0 and right < n and s[left] == s[right]){
//         left--;
//         right++;
//     }
//     int len = right - left - 1;
//     return len;
// }
// void solve(){
//     string s;
//     cin >> s;
//     int maxLen = 0;
//     int start;
//     for(int i = 0; i < s.size(); i++){
//         int odd = expand(s, i, i);
//         int even = expand(s, i, i + 1);
//         maxLen = max(maxLen, max(odd, even));
//         if(maxLen == odd){
//             start = i - (odd - 1) / 2;
//         }
//         else if(maxLen == even){
//             start = i - (even / 2) + 1;
//         }
//     }
//     cout << s.substr(start, maxLen) << "\n";
//     return;
// }
// O(n) approach using manachers algorithm
// void solve(){
//     string s;
//     cin >> s;
//     string t = "#";
//     for(char c : s){
//         t += c;
//         t += "#";
//     }

//     int n = t.size();
//     vector<int> p(n, 0);

//     int center = 0, right = 0;
//     int maxLen = 0, bestCenter = 0;

//     for(int i = 0; i < n; i++){
//         int mirror = 2*center - i;

//         // reuse previous info
//         if(i < right)
//             p[i] = min(right - i, p[mirror]);

//         // expand only if needed
//         while(i - p[i] - 1 >= 0 &&
//               i + p[i] + 1 < n &&
//               t[i - p[i] - 1] == t[i + p[i] + 1]){
//             p[i]++;
//         }

//         // update boundary
//         if(i + p[i] > right){
//             center = i;
//             right = i + p[i];
//         }

//         // track best answer
//         if(p[i] > maxLen){
//             maxLen = p[i];
//             bestCenter = i;
//         }
//     }

//     int start = (bestCenter - maxLen) / 2;
//     cout << s.substr(start, maxLen) << "\n";
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