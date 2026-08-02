#include <bits/stdc++.h>
using namespace std;
// CSES problem based on tree
// // 1. Subordinates
// void dfs(int node, vector<vector<int>> &adj, vector<int> &subordinates){
//     for(auto it : adj[node]){
//         dfs(it, adj, subordinates);
//         subordinates[node] += 1 + subordinates[it];
//     }
// }
// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1);
//     vector<int> subordinates(n + 1, 0);
//     for(int i = 2; i <= n; i++){
//         int manager;
//         cin >> manager;
//         adj[manager].push_back(i);
//     }
//     dfs(1, adj, subordinates);
//     for(int i = 1; i <= n; i++){
//         cout << subordinates[i] << " ";
//     }
//     cout << "\n";
// }

// // 2. Tree Matching
// int dfs(int node, int isIncluded, vector<vector<int>> &adj, int parent, vector<vector<int>> &dp){
//     if(dp[node][isIncluded] != -1) return dp[node][isIncluded];
//     if(isIncluded == 0){
//         int ans = 0;
//         for(int it : adj[node]){
//             if(it != parent){
//                 ans += dfs(it, 0, adj, node, dp);
//             }
//         }
//         int result = 0;
//         for(int it : adj[node]){
//             if(it != parent){
//                 result = max(result, ans - dfs(it, 0, adj, node, dp) + dfs(it, 1, adj, node, dp) + 1);
//             }
//         }
//         return dp[node][isIncluded] = result;
//     }else{
//         int ans = 0;
//         for(int it : adj[node]){
//             if(it != parent){
//                 ans += dfs(it, 0, adj, node, dp);
//             }
//         }
//         return dp[node][isIncluded] = ans;
//     }
// }
// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 1; i < n; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<vector<int>> dp(n + 1, vector<int>(2, -1));
//     // vector<int> parent(n + 1, -1);
//     cout << dfs(1, 0, adj, -1, dp) << "\n";
// }

// // 3. Tree Diameter
// MY LOGIC
// int dfs(int node, vector<vector<int>> &adj, vector<int> &dp, int &ans, int parent){
//     if(dp[node] != -1) return dp[node];
//     int maxF = 0, maxS = -1;
//     for(int neighbour : adj[node]){
//         if(neighbour == parent) continue;
//         int temp = dfs(neighbour, adj, dp, ans, node);
//         if(temp >= maxF){
//             maxS = maxF;
//             maxF = temp;
//         }else if(temp >= maxS){
//             maxS = temp;
//         }
//         ans = max(ans, maxF + maxS);
//     }
//     return dp[node] = maxF + 1;
// }
// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 1; i < n; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int ans = 0;
//     vector<int> dp(n + 1, -1);
//     int maxLen = dfs(1, adj, dp, ans, -1);
//     cout << ans << endl;
// }
// // 2DFS LOGIC
// void dfs(int node, int dist, vector<vector<int>> &adj, int &farNode, int &maxDist, int parent){
//     if(dist > maxDist){
//         maxDist = dist;
//         farNode = node;
//     }
    
//     for(int neighbour : adj[node]){
//         if(neighbour == parent) continue;
//         dfs(neighbour, dist + 1, adj, farNode, maxDist, node);
//     }
// }
// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 1; i < n; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int farNode = 1;
//     int maxDist = -1;
//     dfs(1, 0, adj, farNode, maxDist, -1);

//     maxDist = -1;
//     dfs(farNode, 0, adj, farNode, maxDist, -1);
//     cout << maxDist << "\n";
// }

// // 4. Tree Distance I
// void dfs1(int node, vector<vector<int>> &adj, int parent, int dist, int &farNode, int &maxDist){
//     if(dist > maxDist){
//         maxDist = dist;
//         farNode = node;
//     }
//     for(int neighbour : adj[node]){
//         if(neighbour == parent) continue;
//         dfs1(neighbour, adj, node, dist + 1, farNode, maxDist);
//     }
// }
// void dfs2(int node, vector<vector<int>> &adj, int parent, int &farNode, int dist, int &maxDist, vector<int> &distanceVector){
//     if(dist > maxDist){
//         maxDist = dist;
//         farNode = node;
//     }
//     for(int neighbour : adj[node]){
//         if(neighbour == parent) continue;
//         dfs2(neighbour, adj, node, farNode, dist + 1, maxDist, distanceVector);
//     }
//     distanceVector[node] = dist;
// }
// void solve(){
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 1; i < n; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> distFromFirstFarthestNodeToAllNodes(n + 1, 0);
//     int maxDist = -1;
//     int farNode = 1;
//     dfs1(1, adj, -1, 0, farNode, maxDist);
//     vector<int> distFromSecondFarthestNodeToAllNodes(n + 1, 0);
//     maxDist = -1;
//     dfs2(farNode, adj, -1, farNode, 0, maxDist, distFromFirstFarthestNodeToAllNodes);
//     maxDist = -1;
//     dfs2(farNode, adj, -1, farNode, 0, maxDist, distFromSecondFarthestNodeToAllNodes);
//     for(int i = 1; i <= n; i++){
//         cout << max(distFromFirstFarthestNodeToAllNodes[i], distFromSecondFarthestNodeToAllNodes[i]) << " ";
//     }
//     cout << "\n";
// }

// 5. Tree Distance II // Not completely understood so check before going ahead
void dfs1(int node, int parent, int depth, vector<vector<int>> &adj, vector<int> &subTreeSize, long long&rootSum){
    rootSum += depth;
    subTreeSize[node] = 1;
    for(int neighbour : adj[node]){
        if(neighbour == parent) continue;
        dfs1(neighbour, node, depth + 1, adj, subTreeSize, rootSum);
        subTreeSize[node] += subTreeSize[neighbour];
    }
}

void dfs2(int node, int parent, vector<vector<int>> &adj, vector<int> &subTreeSize, vector<long long> &ans, int n){
    for(int neighbour : adj[node]){
        if(neighbour == parent) continue;
        ans[neighbour] = ans[node] + n - 2 * subTreeSize[neighbour];
        dfs2(neighbour, node, adj, subTreeSize, ans, n);
    }
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    vector<int> subTreeSize(n + 1);
    vector<long long> ans(n + 1);
    long long rootSum = 0;

    dfs1(1, -1, 0, adj, subTreeSize, rootSum);
    ans[1] = rootSum;
    dfs2(1, -1, adj, subTreeSize, ans, n);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

// Company Quesries I
// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<vector<int>> adj(n + 1);
//     vector<int> parent(n + 1, -1);
//     for(int i = 2; i <= n; i++){
//         int par;
//         cin >> par;
//         parent[i] = par;
//         adj[par].push_back(i);
//     }
//     vector<vector<int>> up(n + 1, vector<int>(20, -1));
//     for(int i = 1; i <= n; i++){
//         up[i][0] = parent[i];
//         for(int j = 1; j < 20; j++){
//             if(up[i][j - 1] != -1){
//                 up[i][j] = up[up[i][j - 1]][j - 1];
//             }
//         }
//     }
//     while(q--){
//         int node, k;
//         cin >> node >> k;
//         for(int j = 0; j < 20; j++){
//             if((k >> j) & 1){
//                 node = up[node][j];
//                 if(node == -1) break;
//             }
//         }
//         cout << node << "\n";
//     }
// }

// // Company Queries II
// void dfs(int node, vector<vector<int>> &adj, vector<int> &depth, int parent){
//     for(auto it : adj[node]){
//         if(it != parent){
//             depth[it] = depth[node] + 1;
//             dfs(it, adj, depth, node);
//         }
//     }
// }
// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<vector<int>> adj(n + 1);
//     vector<int> parent(n + 1, -1);
//     for(int i = 2; i <= n; i++){
//         int par;
//         cin >> par;
//         parent[i] = par;
//         adj[par].push_back(i);
//     }
//     vector<vector<int>> up(n + 1, vector<int>(20, -1));
//     vector<int> depth(n + 1, 0);
//     for(int i = 1; i <= n; i++){
//         up[i][0] = parent[i];
//         for(int j = 1; j < 20; j++){
//             if(up[i][j - 1] != -1){
//                 up[i][j] = up[up[i][j - 1]][j - 1];
//             }
//         }
//     }
//     dfs(1, adj, depth, -1);
//     while(q--){
//         int u, v;
//         cin >> u >> v;
//         if(depth[u] < depth[v]) swap(u, v);
//         int diff = depth[u] - depth[v];
//         for(int j = 0; j < 20; j++){
//             if((diff >> j) & 1){
//                 u = up[u][j];
//             }
//         }
//         if(u == v) cout << u << "\n";
//         else{
//             for(int j = 19; j >= 0; j--){
//                 if(up[u][j] != up[v][j]){
//                     u = up[u][j];
//                     v = up[v][j];
//                 }
//             }
//             cout << up[u][0] << "\n";
//         }
//     }
// }

// // Distance Queries
// void solve() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, q;
//     cin >> n >> q;

//     vector<vector<int>> adj(n + 1);
//     for (int i = 0; i < n - 1; i++) {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     int LOG = 18; // enough for n ≤ 2e5
//     vector<vector<int>> up(n + 1, vector<int>(LOG));
//     vector<int> depth(n + 1);

//     // iterative DFS (stack)
//     stack<pair<int,int>> st;
//     st.push({1, 1});
//     depth[1] = 0;

//     while (!st.empty()) {
//         auto [node, parent] = st.top();
//         st.pop();

//         up[node][0] = parent;
//         for (int j = 1; j < LOG; j++) {
//             up[node][j] = up[up[node][j - 1]][j - 1];
//         }

//         for (auto it : adj[node]) {
//             if (it == parent) continue;
//             depth[it] = depth[node] + 1;
//             st.push({it, node});
//         }
//     }

//     auto lca = [&](int u, int v) {
//         if (depth[u] < depth[v]) swap(u, v);

//         int diff = depth[u] - depth[v];
//         for (int j = 0; j < LOG; j++) {
//             if (diff & (1 << j)) {
//                 u = up[u][j];
//             }
//         }

//         if (u == v) return u;

//         for (int j = LOG - 1; j >= 0; j--) {
//             if (up[u][j] != up[v][j]) {
//                 u = up[u][j];
//                 v = up[v][j];
//             }
//         }

//         return up[u][0];
//     };

//     while (q--) {
//         int a, b;
//         cin >> a >> b;

//         int L = lca(a, b);
//         cout << depth[a] + depth[b] - 2 * depth[L] << '\n';
//     }
// }

// // Counting paths
// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 1; i < n; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<vector<int>> up(n + 1, vector<int>(20));
//     vector<int> depth(n + 1, 0);

//     stack<pair<int, int>> st;
//     st.push({1, 1});
//     depth[1] = 0;

//     while (!st.empty()) {
//         int node = st.top().first;
//         int parent = st.top().second;
//         st.pop();

//         up[node][0] = parent;
//         for (int j = 1; j < 20; j++) {
//             up[node][j] = up[up[node][j - 1]][j - 1];
//         }

//         for (auto it : adj[node]) {
//             if (it == parent) continue;
//             depth[it] = depth[node] + 1;
//             st.push({it, node});
//         }
//     }


//     auto lca = [&](int u, int v){
//         if(depth[u] < depth[v]) swap(u, v);
//         int diff = depth[u] - depth[v];
//         for(int j = 0; j < 20; j++){
//             if((diff >> j) & 1){
//                 u = up[u][j];
//             }
//         }
//         if(u == v) return u;
//         for(int j = 19; j >= 0; j--){
//             if(up[u][j] != up[v][j]){
//                 u = up[u][j];
//                 v = up[v][j];
//             }
//         }
//         return up[u][0];
//     };
//     vector<long long> countedPaths(n + 1, 0);
//     while(q--){
//         int u, v;
//         cin >> u >> v;
        
//         int L = lca(u, v);
//         countedPaths[u]++;
//         countedPaths[v]++;
//         countedPaths[L]--;
//         if(L != 1) countedPaths[up[L][0]]--;
//     }
//     function<void(int,int)> dfs = [&](int node, int parent) {
//         for (auto it : adj[node]) {
//             if (it == parent) continue;
//             dfs(it, node);
//             countedPaths[node] += countedPaths[it];
//         }
//     };
//     dfs(1, 0);
//     for(int i = 1; i <= n; i++){
//         cout << countedPaths[i] << " ";
//     }
//     cout << "\n";
// }

// // Subtree Queries
// void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &inTime, vector<int> &outTime, vector<int> &flatTree, int &timer){
//     inTime[node] = timer;
//     flatTree[timer] = node;
//     timer++;
//     for(int neighbour : adj[node]){
//         if(neighbour == parent) continue;
//         dfs(neighbour, node, adj, inTime, outTime, flatTree, timer);
//     }
//     outTime[node] = timer - 1;
// }
// void buildTree(int index, int left, int right, vector<int> &a, vector<long long> &segmentTree){
//     if(left == right){
//         segmentTree[index] = a[left];
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     buildTree(2 * index + 1, left, mid, a, segmentTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segmentTree);

//     segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
// }

// long long query(int index, int left, int right, int l, int r, vector<long long> &segmentTree){
//     // No overlap
//     if(r < left or l > right){
//         return 0;
//     }
//     // complete overlap
//     if(l <= left and r >= right){
//         return segmentTree[index];
//     }
//     int mid = left + (right - left) / 2;
//     long long leftSum = query(2 * index + 1, left, mid, l, r, segmentTree);
//     long long rightSum = query(2 * index + 2, mid + 1, right, l, r, segmentTree);
//     return leftSum + rightSum;
// }

// void update(int index, int left, int right, int pos, int val, vector<int> &a, vector<long long> &segmentTree){
//     if(left == right){
//         a[pos] = val;
//         segmentTree[index] = val;
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     if(pos <= mid){
//         update(2 * index + 1, left, mid, pos, val, a, segmentTree);
//     } else {
//         update(2 * index + 2, mid + 1, right, pos, val, a, segmentTree);
//     }
//     segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
// }
// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n + 1);
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     vector<vector<int>> adj(n + 1);
//     for(int i = 1; i < n; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> inTime(n + 1), outTime(n + 1);
//     vector<int> flatTree(2 * n + 1);
//     int timer = 0;
//     dfs(1, -1, adj, inTime, outTime, flatTree, timer);
//     vector<long long> segmentTree(4 * n);
//     // for(int i = 0; i < n; i++){
//     //     cout << inTime[i + 1] << " ";
//     // }
//     // cout << "\n";
//     // for(int i = 0; i < n; i++){
//     //     cout << outTime[i + 1] << " ";
//     // }
//     // cout << "\n";

//     vector<int> aFlat(n);
//     for(int i = 0; i < n; i++){
//         aFlat[i] = a[flatTree[i]];
//     }   

//     buildTree(0, 0, n - 1, aFlat, segmentTree);
//     while(q--){
//         int type;
//         cin >> type;
//         if(type == 1){
//             int pos, val;
//             cin >> pos >> val;
//             update(0, 0, n - 1, inTime[pos], val, aFlat, segmentTree);
//         }else {
//             int node;
//             cin >> node;
//             long long ans = query(0, 0, n - 1, inTime[node], outTime[node], segmentTree);
//             cout << ans << "\n";
//         }
//     }
// }

int main()
{
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}