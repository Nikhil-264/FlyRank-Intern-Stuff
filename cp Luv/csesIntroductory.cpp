#include <bits/stdc++.h>
using namespace std;

// Introductory Problems
// // Chessboard and queen 
// void dp(int r, int &ans, vector<int> &diag1, vector<int> &diag2, vector<int> &col, vector<vector<char>> &chess){
//     if(r == 8){
//         ans++;
//         return;
//     }
//     for(int c = 0; c < 8; c++){
//             if(chess[r][c] == '*') continue;
//             if(col[c] == 0 and diag1[r + c] == 0 and diag2[r - c + 7] == 0){
//                 col[c] = 1;
//                 diag1[r + c] = 1;
//                 diag2[r - c + 7] = 1;
//                 dp(r + 1, ans, diag1, diag2, col, chess);
//                 col[c] = 0;
//                 diag1[r + c] = 0;
//                 diag2[r - c + 7] = 0;
//             }
//     }
// }
// void solve(){
//     vector<vector<char>> chess(8, vector<char>(8));
//     for(int i = 0; i < 8; i++){
//         for(int j = 0; j < 8; j++){
//             cin >> chess[i][j];
//         }
//     }
//     vector<int> diag1(15, 0), diag2(15, 0);
//     vector<int> col(8, 0);
//     int ct = 0;
//     int ans = 0;
//     dp(0, ans, diag1, diag2, col, chess);
//     cout << ans << "\n";
// }

// // Raab Game I
// void solve(){
//     int n, a, b;
//     cin >> n >> a >> b;
//     if(a == 0 and b == 0){
//         cout << "YES" << endl;
//         for(int i = 0; i < n; i++){
//             cout << i + 1 << " ";
//         }
//         cout << "\n";
//         for(int i = 0; i < n; i++){
//             cout << i + 1 << " ";
//         }
//         cout << "\n";
//     }
//     else if((a == 0 or b == 0) or (a + b > n)) cout << "NO" << endl;
//     else if(a + b == n){
//         cout << "YES" << endl;
//         for(int i = 0; i < n; i++){
//             cout << i + 1 << " ";
//         }
//         cout << "\n";
//         for(int i = 0; i < n; i++){
//             cout << (i + a) % n + 1 << " ";
//         }
//         cout << "\n";
//     }else{
//         cout << "YES" << endl;
//         int temp = a + b;
//         for(int i = 0; i < n; i++){
//             cout << i + 1 << " ";
//         }
//         cout << "\n";
//         for(int i = 0; i < temp; i++){
//             cout << (i + a) % temp + 1 << " ";
//         }
//         for(int i = temp; i < n; i++){
//             cout << i + 1 << " ";
//         }
//         cout << "\n";
//     }
// }

// // Grid Path Description
// bool inside(int r, int c){
//     return r >= 0 and r < 7 and c >= 0 and c < 7;
// }
// void resurse(int r, int c, int index, string &s, vector<vector<int>> &visited, int &ans){
//     if(r == 6 and c == 6){
//         if(index == 48) ans++;
//         return;
//     }

//     if(index == 48) return;

//     visited[r][c] = 1;
//     bool up = inside(r-1,c) && !visited[r-1][c];
//     bool down = inside(r+1,c) && !visited[r+1][c];
//     bool left = inside(r,c-1) && !visited[r][c-1];
//     bool right = inside(r,c+1) && !visited[r][c+1];

//     if(!up && !down && !left && !right){
//         visited[r][c] = 0;
//         return;
//     }

//     // ❌ split trap
//     if(up && down && !left && !right){
//         visited[r][c] = 0;
//         return;
//     }
//     if(left && right && !up && !down){
//         visited[r][c] = 0;
//         return;
//     }
//     char ch = s[index];

//     // try moves
//     if((ch == '?' || ch == 'U') && up)
//         resurse(r-1, c, index+1, s, visited, ans);

//     if((ch == '?' || ch == 'D') && down)
//         resurse(r+1, c, index+1, s, visited, ans);

//     if((ch == '?' || ch == 'L') && left)
//         resurse(r, c-1, index+1, s, visited, ans);

//     if((ch == '?' || ch == 'R') && right)
//         resurse(r, c+1, index+1, s, visited, ans);

//     visited[r][c] = 0;
// }

// void solve(){
//     string s;
//     cin >> s;
//     int x = 0, y = 0;
//     vector<vector<int>> visited(7, vector<int>(7, 0));
//     int ans = 0;
//     resurse(0, 0, 0, s, visited, ans);
//     cout << ans << "\n";
// }

// Path Queries
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> values(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> values[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
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