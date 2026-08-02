#include <bits/stdc++.h>
using namespace std;

// void shortest_distance(vector<vector<int>>&matrix){
//       // Code here
//       int n = matrix.size();
//       for(int i = 0; i < n; i++){
//           for(int j = 0; j < n; j++){
//               if(matrix[i][j] == -1){
//                   matrix[i][j] = 1e9;
//               }
//               if(i == j) matrix[i][j] = 0;
//           }
//       }
      
//       for(int k = 0; k < n; k++){
//           for(int i = 0; i < n; i++){
//               for(int j = 0; j < n; j++){
//                   matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
//               }
//           }
//       }
      
      
      
//       for(int i = 0; i < n; i++){
//           for(int j = 0; j < n; j++){
//               if(matrix[i][j] == 1e9){
//                   matrix[i][j] = -1;
//               }
//              // if(i == j) matrix[i][j] = 0;
//           }
//       }
//   }

// int main() {
//     int t;
//     cin >> t;
//     while(t--){
//         int n, q;
//         cin >> n >> q;
//         // DisjointSet d;
//         vector<string> a(n);
//         for(int i = 0; i < n; i++) cin >> a[i];
//         vector<vector<int>> dist(n, vector<int> (n, -1));
//         for(int i = 0; i < n; i++) dist[i][i] = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(i != j){
//                     if(a[i][0] == a[j][0] or a[i][0] == a[j][1] or a[i][1] == a[j][0] or a[i][1] == a[j][1]){
//                         dist[i][j] = abs(i - j);
//                     }
//                 }
//             }
//         }

//         shortest_distance(dist);

//         while(q--){
//             int g, h;
//             cin >> g >> h;
//             cout << dist[g - 1][h - 1] << endl;
//         }
//     }
//     return 0;
// }

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> visited(n, 0);
    int ans = 0;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}