#include <bits/stdc++.h>
using namespace std;

// // Q1
// void solve(){
//     int n;
//     cin >> n;
//     int isNonNegative = 0;
//     for(int i = 0; i < n; i++){
//         int x;
//         cin >> x;
//         if(x >= 0){
//             isNonNegative = 1;
//         }
//     }
//     if(isNonNegative) cout << "No" << endl;
//     else cout << "Yes" << endl;
//     return;
// }

// // Q2
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> color(n), size(n, -1);
//     vector<int> maxSize(m + 1, -1);
//     for(int i = 0; i < n; i++){
//         cin >> color[i];
//         cin >> size[i];
//         maxSize[color[i]] = max(maxSize[color[i]], size[i]);
//     }
//     for(int i = 1; i <= m; i++){
//         cout << maxSize[i] << " ";
//     }
//     cout << endl;
// }

// // Q3
// void solve(){
//     int n;
//     cin >> n;
//     long long ans = 0;
//     int j = 0;
    
//     for(int i = 1; i <= n; i++){
//         if(j < i) j = i;

//         while(j < n){
//             cout << "? " << i << " " << j + 1 << endl;
//             cout.flush();

//             string res;
//             cin >> res;
//             if(res == "Yes"){
//                 j++;
//             }else{
//                 break;
//         }
//         }
//         ans += (j - i);
//     }
//     cout << "! " << ans << "\n";
//     cout.flush();
// }

// Q 4
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> row(n + 1, 0), colOfRow(n + 1, 0);
    vector<int> col(n + 1, 0), rowOfCol(n + 1, 0);

    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;

        if(row[x]){
            int tempcol = colOfRow[x];
            row[x] = 0;
            colOfRow[x] = 0;
            col[tempcol] = 0;
            rowOfCol[tempcol] = 0;
        }
        if(col[y]){
            int temprow = rowOfCol[y];
            col[y] = 0;
            rowOfCol[y] = 0;
            row[temprow] = 0;
            colOfRow[temprow] = 0;
        }

        row[x] = 1;
        colOfRow[x] = y;
        col[y] = 1;
        rowOfCol[y] = x;

    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(row[i]){
            ans++;
        }
    }
    cout << ans << "\n";
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