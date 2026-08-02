#include <bits/stdc++.h>
using namespace std;

// Counting Rooms
// void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
//     int n = grid.size();
//     int m = grid[0].size();
//     if(i < 0 or j < 0 or i >= n or j >= m){
//         return;
//     }
//     if(grid[i][j] == '#' or visited[i][j]){
//         return;
//     }
//     visited[i][j] = true;
//     dfs(i + 1, j, grid, visited);
//     dfs(i - 1, j, grid, visited);
//     dfs(i, j + 1, grid, visited);
//     dfs(i, j - 1, grid, visited);
// }

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<char>> grid(n, vector<char>(m));
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cin >> grid[i][j];
//         }        
//     }
//     int ans = 0;
//     vector<vector<bool>> visited(n, vector<bool>(m, false));

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(grid[i][j] == '.' and !visited[i][j]){
//                 ans++;
//                 dfs(i, j, grid, visited);
//             }
//         }
//     }
//     cout << ans << "\n";
// }

// // // Labyrinth 
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<char>> grid(n, vector<char>(m));
//     pair<int, int> start, end;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cin >> grid[i][j];
//             if(grid[i][j] == 'B'){
//                 start = {i, j};
//             }
//             if(grid[i][j] == 'A'){
//                 end = {i, j};
//             }
//         }        
//     }
//     queue<pair<int, int>> q;
//     q.push(start);
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     visited[start.first][start.second] = true;
//     map<pair<int, int>, pair<int, int>> parent;
//     vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     bool found = false;
//     while(!q.empty()){
//         auto it = q.front();
//         q.pop();
//         if(it == end){
//             found = true;
//             break;
//         }
//         for(auto iter : directions){
//             int x = it.first + iter.first;
//             int y = it.second + iter.second;
//             if(x >= 0 and y >= 0 and x < n and y < m and grid[x][y] != '#' and !visited[x][y]){
//                 visited[x][y] = true;
//                 q.push({x, y});
//                 parent[{x, y}] = it;
//             }
//         }
//     }
//     if(!found){
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
//     vector<char> path;
//     pair<int, int> curr = end;

//     while(curr != start){
//         auto it = parent[curr];
//         if(it.first == curr.first + 1){
//             path.push_back('D');
//         }
//         else if(it.first == curr.first - 1){
//             path.push_back('U');
//         }
//         else if(it.second == curr.second + 1){
//             path.push_back('R');
//         }
//         else if(it.second == curr.second - 1){
//             path.push_back('L');
//         }
//         curr = it;
//     }
//     // reverse(path.begin(), path.end());
//     cout << path.size() << "\n";
//     for(auto it : path){
//         cout << it;
//     }
//     cout << "\n";
// }

// Building Roads
// class DisjointSet{
//     vector<int> rank, parent, size;// add size when using unione by size,
// public:
//     DisjointSet(int n){
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1, 0);
//         // size.resize(n + 1, 0);

//         for (int i = 0; i <= n; i++){
//             parent[i] = i;
//         }
//     }

//     int findUPar(int node){
//         if(node == parent[node]){
//             return node;
//         }
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionByRank(int u, int v){
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u] < rank[ulp_v]){
//             parent[ulp_u] = ulp_v;
//         }
//         else if(rank[ulp_v] < rank[ulp_u]){
//             parent[ulp_v] = ulp_u;
//         }
//         else{
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }
//     // for using uninone by size we have to declare the size vector that we dont need in the union by rank so use one of the at a time dont use bth of them at a time and while using using by rank comment out the size part

//     // void unionBySize(int u, int v){
//     //     int ulp_u = findUPar(u);
//     //     int ulp_v = findUPar(v);
//     //     if(ulp_u == ulp_v) return;
//     //     if(size[ulp_u] < size[ulp_v]){
//     //         parent[ulp_u] = ulp_v;
//     //         size[ulp_v] += size[ulp_u]; 
//     //     }
//     //     else{
//     //         parent[ulp_v] = ulp_u;
//     //         size[ulp_u] += size[ulp_v]; 
//     //     }
//     // }
// };

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     DisjointSet ds(n);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         ds.unionByRank(u, v);
//     }
//     vector<int> leaders;
//     for(int i = 1; i <= n; i++){
//         if(ds.findUPar(i) == i){
//             leaders.push_back(i);
//         }
//     }
//     int count = leaders.size() - 1;
//     vector<pair<int, int>> newRoads;
//     for(int i = 0; i < leaders.size() - 1; i++){
//         newRoads.push_back({leaders[i], leaders[i + 1]});
//     }
//     cout << count << "\n";
//     for(auto it : newRoads){
//         cout << it.first << " " << it.second << "\n";
//     }
// }

// Message Route
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     map<int, int> parent;
//     vector<bool> visited(n + 1, false);
//     queue<int> q;
//     q.push(1);
//     visited[1] = true;
//     bool found = false;
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         if(curr == n){
//             found = true;
//             break;
//         }
//         for(auto it : adj[curr]){
//             if(!visited[it]){
//                 visited[it] = true;
//                 parent[it] = curr;
//                 q.push(it);
//             }
//         }
//     }
//     if(!found){
//         cout << "IMPOSSIBLE\n";
//         return;
//     }
//     vector<int> path;
//     int curr = n;
//     while(curr != 1){
//         path.push_back(curr);
//         curr = parent[curr];
//     }
//     path.push_back(1);
//     reverse(path.begin(), path.end());
//     cout << path.size() << "\n";
//     for(auto it : path){
//         cout << it << " ";
//     }
//     cout << "\n";
// }

// Building Teams
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> team(n + 1, -1);
//     bool possible = true;
//     for(int i = 1; i <= n; i++){
//         if(team[i] == -1){
//             queue<int> q;
//             q.push(i);
//             team[i] = 0;
//             while(!q.empty()){
//                 int curr = q.front();
//                 q.pop();
//                 for(auto it : adj[curr]){
//                     if(team[it] == -1){
//                         team[it] = 1 - team[curr];
//                         q.push(it);
//                     }
//                     else if(team[it] == team[curr]){
//                         possible = false;
//                     }
//                 }
//             }
//         }
//     }
//     if(!possible){
//         cout << "IMPOSSIBLE\n";
//         return;
//     }else{
//         for(int i = 1; i <= n; i++){
//             cout << team[i] + 1 << " ";
//         }
//         cout << "\n";
//     }
// }

//  Round Trip
// void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path, bool &found){
//     if(found) return;
//     visited[node] = 1;
//     path.push_back(node);
//     for(auto it : adj[node]){
//         if(!visited[it]){
//             dfs(it, node, adj, visited, path, found);
//             if(found) return;
//         }
//         else if(visited[it] == 1 and it != parent){
//             found = true;
//             path.push_back(it);
//             return;
//         }
//     }
//     if(!found){
//         visited[node] = 2;
//         path.pop_back();
//     }
// }
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> visited(n + 1, 0);
//     vector<int> parent(n + 1, -1);
//     bool found = false;
//     vector<int> path;
//     for(int i = 1; i <= n; i++){
//         if(!visited[i] and !found){
//             dfs(i, -1, adj, visited, path, found);
//         }
//     }
//     if(!found){
//         cout << "IMPOSSIBLE\n";
//         return;
//     }
//     reverse(path.begin(), path.end());
//     vector<int> cycle;
//     int start = path[0];
//     cycle.push_back(start);
//     for(int i = 1; i < path.size(); i++){
//         cycle.push_back(path[i]);
//         if(path[i] == start) break;
//     }
//     reverse(cycle.begin(), cycle.end());
//     cout << cycle.size() << "\n";
//     for(auto it : cycle){
//         cout << it << " ";
//     }
//     cout << "\n";
// }

// Monsters
// void solve() {
//     int n, m;
//     cin >> n >> m;

//     vector<string> grid(n);
//     for (int i = 0; i < n; i++) cin >> grid[i];

//     vector<vector<int>> distM(n, vector<int>(m, 1e9));
//     vector<vector<int>> distA(n, vector<int>(m, -1));
//     vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));

//     queue<pair<int,int>> q;

//     pair<int,int> start;

//     // Monsters BFS initialization
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (grid[i][j] == 'M') {
//                 q.push({i, j});
//                 distM[i][j] = 0;
//             }
//             if (grid[i][j] == 'A') {
//                 start = {i, j};
//             }
//         }
//     }

//     vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

//     // BFS for monsters
//     while (!q.empty()) {
//         auto [x, y] = q.front(); q.pop();
//         for (auto [dx, dy] : dirs) {
//             int nx = x + dx, ny = y + dy;
//             if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
//                 grid[nx][ny] != '#' && distM[nx][ny] > distM[x][y] + 1) {
//                 distM[nx][ny] = distM[x][y] + 1;
//                 q.push({nx, ny});
//             }
//         }
//     }

//     // BFS for A
//     queue<pair<int,int>> qa;
//     qa.push(start);
//     distA[start.first][start.second] = 0;

//     while (!qa.empty()) {
//         auto [x, y] = qa.front(); qa.pop();

//         // reached boundary
//         if (x == 0 || y == 0 || x == n-1 || y == m-1) {
//             cout << "YES\n";
//             vector<char> path;
//             pair<int,int> cur = {x, y};

//             while (cur != start) {
//                 auto p = parent[cur.first][cur.second];
//                 if (p.first == cur.first + 1) path.push_back('U');
//                 else if (p.first == cur.first - 1) path.push_back('D');
//                 else if (p.second == cur.second + 1) path.push_back('L');
//                 else if (p.second == cur.second - 1) path.push_back('R');
//                 cur = p;
//             }

//             reverse(path.begin(), path.end());
//             cout << path.size() << "\n";
//             for (char c : path) cout << c;
//             cout << "\n";
//             return;
//         }

//         for (auto [dx, dy] : dirs) {
//             int nx = x + dx, ny = y + dy;
//             if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
//                 grid[nx][ny] != '#' && distA[nx][ny] == -1 &&
//                 distA[x][y] + 1 < distM[nx][ny]) {
//                 distA[nx][ny] = distA[x][y] + 1;
//                 parent[nx][ny] = {x, y};
//                 qa.push({nx, ny});
//             }
//         }
//     }

//     cout << "NO\n";
// }

// Shortest Routes I // Dikstra Algo not Bellman-Ford Algorithm
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, long long>>> graph(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         graph[u].push_back({v, w});
//     }

//     vector<long long> dist(n + 1, 1e18);
//     dist[1] = 0;
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//     pq.push({0, 1}); // {distance, node}
//     while(!pq.empty()){
//         auto it = pq.top();
//         pq.pop();
//         if (it.first > dist[it.second]) continue;
//         int node = it.second;
//         long long distance = it.first;

//         for(auto iter : graph[node]){
//             int adjNode = iter.first;
//             long long edgeWeight = iter.second;
//             if(distance + edgeWeight < dist[adjNode]){
//                 dist[adjNode] = distance + edgeWeight;
//                 pq.push({dist[adjNode], adjNode});
//             }
//         }
//     }
//     for(int i = 1; i <= n; i++){
//         if(dist[i] == 1e18){
//             cout << "INF";
//         }else{
//             cout << dist[i] << " ";
//         }
//     }
// }

// Shortest Routes II //  Floyd-Warshall Algorithm
// void solve(){
//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 1e18));
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         dist[u][v] = min(dist[u][v], (long long)w);
//         dist[v][u] = min(dist[v][u], (long long)w);
//     }
//     for(int i = 1; i <= n; i++){
//         dist[i][i] = 0;
//     }
//     for(int k = 1; k <= n; k++){
//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= n; j++){
//                 if(dist[i][k] + dist[k][j] < dist[i][j]){
//                     dist[i][j] = dist[i][k] + dist[k][j];
//                 }
//             }
//         }
//     }
//     for(int i = 0; i < q; i++){
//         int u, v;
//         cin >> u >> v;
//         if(dist[u][v] == 1e18){
//             cout << -1 << "\n";
//         }else{
//             cout << dist[u][v] << "\n";
//         }
//     }
// }

// High score
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> u(m), v(m);
//     vector<long long> w(m);
//     for(int i = 0; i < m; i++){
//         cin >> u[i] >> v[i] >> w[i];
//         w[i] = -w[i];
//     }   

//     const long long INF = 1e18;
//     vector<long long> dist(n + 1, INF);
//     dist[1] = 0;

//     // bellman ford relaxation
//     for(int i = 1; i <= n - 1; i++){
//         for(int j = 0; j < m; j++){
//             if(dist[u[j]] != INF and dist[u[j]] + w[j] < dist[v[j]]){
//                 dist[v[j]] = dist[u[j]] + w[j];
//             }
//         }
//     }

//     // detect negative cycle
//     vector<bool> inNegativeCycle(n + 1, false);
//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j < m; j++){
//             int U = u[j], V = v[j];
//             long long W = w[j];

//             if(dist[U] != INF and dist[U] + W < dist[V]){
//                 dist[V] = dist[U] + W;
//                 inNegativeCycle[V] = true;
//             }
//             if(inNegativeCycle[U]){
//                 inNegativeCycle[V] = true;
//             }
//         }
//     }

//     if(inNegativeCycle[n]){
//         cout << -1 << "\n";
//         return;
//     }else{
//         cout << -dist[n] << "\n";
//     }
//     return;
// }

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> u(m), v(m);
//     vector<long long> w(m);
//     for(int i = 0; i < m; i++){
//         cin >> u[i] >> v[i] >> w[i];
//         w[i] = -w[i];
//     }

//     long long INF = 1e18;
//     vector<long long> dist(n + 1, INF);
//     dist[1] = 0;

//     // bellman ford relaxation
//     for(int i = 1; i <= n - 1; i++){
//         for(int j = 0; j < m; j++){
//             if(dist[u[j]] != INF and dist[u[j]] + w[j] < dist[v[j]]){
//                 dist[v[j]] = dist[u[j]] + w[j];   
//             }
//         }
//     }
    
//     // detect negative cycle
//     vector<bool> isNegativeCycle(n + 1, false);
//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j < m; j++){
//             int U = u[j], V = v[j];
//             long long W = w[j];

//             if(dist[U] != INF and dist[U] + W < dist[V]){
//                 dist[V] = dist[U] + W;
//                 isNegativeCycle[v[j]] = true;
//             }
//             if(isNegativeCycle[U]){
//                 isNegativeCycle[V] = true;
//             }
//         }
//     }

//     if(isNegativeCycle[n]){
//         cout << -1 << "\n";
//         return;
//     }else{
//         cout << -dist[n] << "\n";
//     }
//     return;
// }

// Flight Discount
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, long long>>> graph(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         graph[u].push_back({v, w});
//     }
//     // vector<long long> dist(n + 1, 1e18);
//     vector<vector<long long>> dist(n+1, vector<long long>(2, 1e18));
//     // dist[node][0] = discount not used
//     // dist[node][1] = discount used
//     dist[1][0] = 0;

//     priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> pq; // {{distance, node}, discountUsed}
//     pq.push({{0, 1}, 0}); // {{distance, node}, discountUsed}
//     while(!pq.empty()){
//         long long wt = pq.top().first.first;
//         int node = pq.top().first.second;
//         int discount = pq.top().second;
//         pq.pop();
//         if(wt > dist[node][discount]) continue;


//         if(discount == 0){
//             for(auto iter : graph[node]){
//                 int adjNode = iter.first;
//                 long long edgeWeight = iter.second;
//                 if(wt + edgeWeight < dist[adjNode][0]){
//                     dist[adjNode][0] = wt + edgeWeight;
//                     pq.push({{dist[adjNode][0], adjNode}, 0});
//                 }
//                 if(wt + edgeWeight / 2 < dist[adjNode][1]){
//                     dist[adjNode][1] = wt + edgeWeight / 2;
//                     pq.push({{dist[adjNode][1], adjNode}, 1});
//                 }
//             }
//         }
//         else{
//             for(auto iter : graph[node]){
//                 int adjNode = iter.first;
//                 long long edgeWeight = iter.second;
//                 if(wt + edgeWeight < dist[adjNode][1]){
//                     dist[adjNode][1] = wt + edgeWeight;
//                     pq.push({{dist[adjNode][1], adjNode}, 1});
//                 }
//             }
//         }
//     }
//     cout << dist[n][1] << "\n";
// }

// // Cycle Finding
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<int> u(m), v(m);
//     vector<long long> w(m);
//     for(int i = 0; i < m; i++){
//         cin >> u[i] >> v[i] >> w[i];
//     }
//     vector<long long> dist(n + 1, 0);
//     dist[1] = 0;
//     // bellman ford relaxation
//     vector<int> parent(n + 1, -1);
//     for(int i = 1; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(dist[u[j]] + w[j] < dist[v[j]]){
//                 dist[v[j]] = dist[u[j]] + w[j];
//                 parent[v[j]] = u[j];
//             }
//         }
//     }

//     // detect negative cycle and print negative cycle
//     int lastUpdatedNode = -1;
//     for(int j = 1; j <= n; j++){
//         for(int i = 0; i < m; i++){
//             int U = u[i], V = v[i];
//             long long W = w[i];

//             if(dist[U] + W < dist[V]){
//                 dist[V] = dist[U] + W;
//                 parent[V] = U;
//                 lastUpdatedNode = V;
//             }
//         }
//     }

//     if(lastUpdatedNode == -1){
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
//     for(int i = 1; i <= n; i++){
//         lastUpdatedNode = parent[lastUpdatedNode];
//     }

//     vector<int> cycle;
//     int curr = lastUpdatedNode;
//     cycle.push_back(lastUpdatedNode);
//     do{
//         curr = parent[curr];
//         cycle.push_back(curr);
//     }while(curr != lastUpdatedNode);

//     reverse(cycle.begin(), cycle.end());
//     for(auto it : cycle){
//         cout << it << " ";
//     }
//     cout << "\n";
//     return;
// }

// Flights Routes
// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<vector<pair<int, long long>>> graph(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         graph[u].push_back({v, w});
//     }
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {{distance, node}, discountUsed}
//     pq.push({0, 1}); // {{distance, node},
//     vector<long long> ans;
//     vector<int> used(n + 1, 0);
//     while(!pq.empty()){
//         long long wt = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();
//         used[node]++;
//         if(used[node] > k) continue;
//         if(node == n){
//             ans.push_back(wt);
//             if(int(ans.size()) == k){
//                 break;
//             }
//         }
//         for(auto iter : graph[node]){
//             int adjNode = iter.first;
//             long long edgeWeight = iter.second;
//             pq.push({wt + edgeWeight, adjNode});
//         }
//     }
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     cout << "\n";
//     return;
// }

// // Round Trip II
// void dfs(int node, vector<vector<int>> &adj, vector<int> &parent, vector<bool> &visited, vector<int> &pathVisited, bool &cycleFound, int &cycleEnd, int &cycleStart){
//     if(cycleFound) return;
//     visited[node] = true;
//     pathVisited[node] = true;
//     for(auto it : adj[node]){
//         if(!visited[it]){
//             parent[it] = node;
//             dfs(it, adj, parent, visited, pathVisited, cycleFound, cycleEnd, cycleStart);
//             if(cycleFound) return;
//         }
//         else if(pathVisited[it]){
//             cycleFound = true;
//             cycleEnd = node;
//             cycleStart = it;
//             return;
//         }
//     }
//     pathVisited[node] = false;
// }
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }
//     vector<int> parent(n + 1, -1);
//     vector<bool> visited(n + 1, false);
//     vector<int> pathVisited(n + 1, false);
//     int cycleStart = -1;
//     int cycleEnd = -1;
//     bool cycleFound = false;
//     for(int i = 1; i <= n; i++){
//         if(!visited[i]){
//             dfs(i, adj, parent, visited, pathVisited, cycleFound, cycleEnd, cycleStart);
//         }
//     }
//     if(!cycleFound){
//         cout << "IMPOSSIBLE\n";
//         return;
//     }
//     vector<int> cycle;
//     cycle.push_back(cycleStart);
//     int curr = cycleEnd;

//     while(curr != cycleStart){
//         cycle.push_back(curr);
//         curr = parent[curr];
//     }
//     cycle.push_back(cycleStart);
//     reverse(cycle.begin(), cycle.end());
//     cout << cycle.size() << "\n";
//     for(auto it : cycle){
//         cout << it << " ";
//     }
//     cout << "\n";
//     return;
// }

// // Course Schedule
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     vector<int> indegree(n + 1, 0);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         indegree[v]++;
//     }
//     queue<int> q;
//     for(int i = 1; i <= n; i++){
//         if(indegree[i] == 0){
//             q.push(i);
//         }
//     }
//     vector<int> topoOrder;
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         topoOrder.push_back(curr);
//         for(auto it : adj[curr]){
//             indegree[it]--;
//             if(indegree[it] == 0){
//                 q.push(it);
//             }
//         }
//     }
//     if(topoOrder.size() != n){
//         cout << "IMPOSSIBLE\n";
//         return;
//     }
//     for(auto it : topoOrder){
//         cout << it << " ";
//     }
//     cout << "\n";
// }

// Longest Flight Routes
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     vector<int> dist(n + 1, -1e9);
//     dist[1] = 1;
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }
//     vector<int> indegree(n + 1, 0);
//     for(int i = 1; i <= n; i++){
//         for(auto it : adj[i]){
//             indegree[it]++;
//         }
//     }
//     vector<int> parent(n + 1, -1);
//     queue<int> q;
//     for(int i = 1; i <= n; i++){
//         if(indegree[i] == 0){
//             q.push(i);
//         }
//     }
//     vector<int> topo;
//     bool found = false;
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         topo.push_back(curr);
//         for(auto it : adj[curr]){
//             if(dist[curr] != -1e9 && dist[it] < dist[curr] + 1){
//                 dist[it] = dist[curr] + 1;
//                 parent[it] = curr;
//             }
//             indegree[it]--;
//             if(indegree[it] == 0){
//                 q.push(it);
//             }
//         }
//     }
//     vector<int> path;
//     int curr = n;
//     while(curr != -1){
//         path.push_back(curr);
//         curr = parent[curr];
//     }
//     reverse(path.begin(), path.end());
//     if(dist[n] < 0){
//         cout << "IMPOSSIBLE\n";
//         return;
//     }
//     cout << path.size() << "\n";
//     for(auto it : path){
//         cout << it << " ";
//     }
//     cout << "\n";
// }

// // Game Routes
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     vector<int> indegree(n + 1, 0);
//     int mod = 1e9 + 7;
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         indegree[v]++;
//     }
//     vector<long long> times(n + 1, 0);
//     times[1] = 1;

//     queue<int> q;
//     for(int i = 1; i <= n; i++){
//         if(indegree[i] == 0){
//             q.push(i);
//         }
//     }
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         for(auto it : adj[curr]){
//             times[it] = (times[it] + times[curr]) % mod;
//             indegree[it]--;
//             if(indegree[it] == 0){
//                 q.push(it);
//             }
//         }
//     }
//     cout << times[n] << "\n";
// }

// // Investigation
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, long long>>> adj(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//     }
//     // approach
//     vector<long long> dist(n + 1, 1e18);
//     vector<int> paths(n + 1, 0);
//     vector<int> mn(n + 1, 1e9);
//     vector<int> mx(n + 1, 0);
//     dist[1] = 0;
//     paths[1] = 1;
//     mn[1] = 0;
//     mx[1] = 0;

//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {{distance, node}}
//     pq.push({0, 1});
//     while(!pq.empty()){
//         long long wt = pq.top().first;
//         int node = pq.top().second;

//         pq.pop();
//         if(wt > dist[node]) continue;
//         for(auto it : adj[node]){
//             int adjNode = it.first;
//             long long edgeWeight = it.second;
//             if(wt + edgeWeight < dist[adjNode]){
//                 dist[adjNode] = wt + edgeWeight;
//                 paths[adjNode] = paths[node];
//                 mn[adjNode] = mn[node] + 1;
//                 mx[adjNode] = mx[node] + 1;
//                 pq.push({dist[adjNode], adjNode});
//             } else if(wt + edgeWeight == dist[adjNode]){
//                 paths[adjNode] = (paths[adjNode] + paths[node]) % 1000000007;
//                 mn[adjNode] = min(mn[adjNode], mn[node] + 1);
//                 mx[adjNode] = max(mx[adjNode], mx[node] + 1);
//             }
//         }
//     }
//     cout << dist[n] << " " << paths[n] << " " << mn[n] << " " << mx[n] << "\n";
// }

// 
// Planets Queries I
// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> next(n + 1);
//     for(int i = 1; i <= n; i++){
//         cin >> next[i];
//     }
//     vector<vector<int>> up(n + 1, vector<int>(32)); // up[i][j] represents the node reachable from i after 2^j jumps
//     for(int i = 1; i <= n; i++){
//         up[i][0] = next[i];
//     }
//     for(int j = 1; j < 31; j++){
//         for(int i = 1; i <= n; i++){
//             up[i][j] = up[up[i][j - 1]][j - 1];
//         }
//     }
//     while(q--){
//         int x, k;
//         cin >> x >> k;
//         int curr = x;
//         for(int j = 0; j < 31; j++){
//             if(k & (1 << j)){
//                 curr = up[curr][j];
//             }
//         }
//         cout << curr << "\n";
//     }
// } 

// // Planet Queries II
// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> next(n + 1);
//     for(int i = 1; i <= n; i++){
//         cin >> next[i];
//     }
//     vector<vector<int>> up(n + 1, vector<int>(32)); // up[i][j] represents the node reachable from i after 2^j jumps
//     for(int i = 1; i <= n; i++){
//         up[i][0] = next[i];
//     }
//     for(int j = 1; j < 31; j++){
//         for(int i = 1; i <= n; i++){
//             up[i][j] = up[up[i][j - 1]][j - 1];
//         }
//     }
//     vector<int> indegree(n + 1, 0);
//     for(int i = 1; i <= n; i++){
//         indegree[next[i]]++;
//     }
//     queue<int> que;
//     for(int i = 1; i <= n; i++){
//         if(indegree[i] == 0){
//             que.push(i);
//         }
//     }
//     vector<int> inCycle(n + 1, 1);
//     while(!que.empty()){
//         int curr = que.front();
//         que.pop();
//         inCycle[curr] = 0;
//         int nextNode = next[curr];
//         indegree[nextNode]--;
//         if(indegree[nextNode] == 0){
//             que.push(nextNode);
//         }
//     }
//     vector<int> cycleID(n + 1, -1);
//     vector<int> cyclePos(n + 1);
//     vector<int> dist(n + 1, 0);
//     vector<int> cycleSize;
//     // find cycle
//     int CycleId = 0;
//     for(int i = 1; i <= n; i++){
//         if(inCycle[i] and cycleID[i] == -1){
//             int v = i;
//             vector<int> cycle;
//             while(cycleID[v] == -1){
//                 cycleID[v] = CycleId;
//                 cycle.push_back(v);
//                 v = next[v];
//             }
//             int size = cycle.size();
//             cycleSize.push_back(size);
//             for(int j = 0; j < size; j++){
//                 cyclePos[cycle[j]] = j;
//             }
//             CycleId++;
//         }
//     }
//     // compute the distance to the cycle
//     vector<vector<int>> rev(n + 1);
//     for(int i = 1; i <= n; i++){
//         rev[next[i]].push_back(i);
//     }
//     queue<int> bfs;
//     for(int i = 1; i <= n; i++){
//         if(inCycle[i]){
//             bfs.push(i);
//         }
//     }
//     while(!bfs.empty()){
//         int v = bfs.front();
//         bfs.pop();
//         for(auto it : rev[v]){
//             if(!inCycle[it]){
//                 dist[it] = dist[v] + 1;
//                 cycleID[it] = cycleID[v];
//                 bfs.push(it);
//                 inCycle[it] = 1;
//             }
//         }
//     }
//     auto jump = [&](int v, int k){
//         for(int j = 0; j < 31; j++){
//             if(k & (1 << j)){
//                 v = up[v][j];
//             }
//         }
//         return v;
//     };
//     while(q--){
//         int x, y;
//         cin >> x >> y;
//         if(dist[x] >= dist[y]){
//             int diff = dist[x] - dist[y];
//             int a = jump(x, diff);
//             if(a == y){
//                 cout << diff << "\n";
//                 continue;
//             }
//         }
//         int ac = jump(x, dist[x]);
//         if(cycleID[ac] != cycleID[y] or dist[y] > 0){
//             cout << -1 << "\n";
//             continue;
//         }
//         int ans = dist[x];
//         int sz = cycleSize[cycleID[ac]];
//         int diff = (cyclePos[y] - cyclePos[ac] + sz) % sz;
//         cout << ans + diff << "\n";
//     }
// }

// // Planet Cycles
// void solve(){
//     int n;
//     cin >> n;
//     vector<int> next(n + 1);
//     for(int i = 1; i <= n; i++){
//         cin >> next[i];
//     }
//     vector<vector<int>> up(n + 1, vector<int>(32));
//     // done give me suggestions for this code
//     vector<int> indegree(n + 1, 0);
//     for(int i = 1; i <= n; i++){
//         up[i][0] = next[i];
//         indegree[next[i]]++;
//     }
//     vector<int> isCycle(n + 1, 1);
//     queue<int> q;
//     for(int i = 1; i <= n; i++){
//         if(indegree[i] == 0){
//             q.push(i);
//         }
//     }
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         isCycle[curr] = 0;
//         int nextNode = next[curr];
//         indegree[nextNode]--;
//         if(indegree[nextNode] == 0){
//             q.push(nextNode);
//         }
//     }
//     int cycleID = 0;
//     vector<int> cycleIDofEachELement(n + 1, -1);
//     vector<int> cycleSize;
//     for(int i = 1; i <= n; i++){
//         if(isCycle[i] and cycleIDofEachELement[i] == -1){
//             int v = i;
//             vector<int> cycle;
//             while(cycleIDofEachELement[v] == -1){
//                 cycleIDofEachELement[v] = cycleID;
//                 cycle.push_back(v);
//                 v = next[v];
//             }
//             int size = cycle.size();
//             cycleSize.push_back(size);
//             cycleID++;
//         }
//     }
//     // computing the distance to the cycle
//     vector<vector<int>> rev(n + 1);
//     for(int i = 1; i <= n; i++){
//         rev[next[i]].push_back(i);
//     }
//     vector<int> dist(n + 1, 0);
//     queue<int> bfs;
//     for(int i = 1; i <= n; i++){
//         if(isCycle[i]){
//             bfs.push(i);
//         }
//     }
//     while(!bfs.empty()){
//         int v = bfs.front();
//         bfs.pop();
//         for(auto it : rev[v]){
//             if(!isCycle[it]){
//                 dist[it] = dist[v] + 1;
//                 cycleIDofEachELement[it] = cycleIDofEachELement[v];
//                 bfs.push(it);
//                 isCycle[it] = 1;
//             }
//         }
//     }
//     for(int i = 1; i <= n; i++){
//         cout << dist[i] + cycleSize[cycleIDofEachELement[i]] << " ";
//     }
//     cout << "\n";
//     return;
// }

// // // Road Reparation
// // Prim's Algorithm
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, long long>>> adj(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }
//     int ct = 0;
//     long long cost = 0;
//     vector<int> visited(n + 1, 0);
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {{cost, node}}
//     pq.push({0, 1});

//     while(!pq.empty()){
//         long long curWt = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();
//         if(visited[node]) continue;
//         visited[node] = 1;
//         cost += curWt;
//         ct++;
//         for(auto it : adj[node]){
//             int adjNode = it.first;
//             long long edgeWeight = it.second;
//             if(!visited[adjNode]){
//                 pq.push({edgeWeight, adjNode});
//             }
//         }
//     }
//     if(ct == n){
//         cout << cost << "\n";
//     }else{
//         cout << "IMPOSSIBLE\n";
//     }
// }

// // Kruskal's Algorithm
// class disjointSet{
//     vector<int> parent, rank;
// public:
//     disjointSet(int n){
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         for(int i = 1; i <= n; i++){
//             parent[i] = i;
//         }
//     }

//     int findUPar(int node){
//         if(node == parent[node]){
//             return node;
//         }
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionByRank(int u, int v){
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u] < rank[ulp_v]){
//             parent[ulp_u] = ulp_v;
//         }else if(rank[ulp_u] > rank[ulp_v]){
//             parent[ulp_v] = ulp_u;
//         }else{
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }
// };
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> edges;
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges.push_back({w, u, v});
//     }
//     sort(edges.begin(), edges.end());
//     disjointSet ds(n);
//     long long cost = 0;
//     int ct = 0;
//     for(auto it : edges){
//         int w = it[0], u = it[1], v = it[2];
//         if(ds.findUPar(u) != ds.findUPar(v)){
//             ds.unionByRank(u, v);
//             cost += w;
//             ct++;
//         }
//     }
//     if(ct == n - 1){
//         cout << cost << "\n";
//     }else{
//         cout << "IMPOSSIBLE\n"; 
//     }
// }

// // Road COnstruction
// class DisjointSet{
// public:
//     vector<int> rank, parent, sizeofComp;// add size when using unione by size,
//     DisjointSet(int n){
//         // rank.resize(n + 1, 0);
//         parent.resize(n + 1, 0);
//         sizeofComp.resize(n + 1, 1);

//         for (int i = 0; i <= n; i++){
//             parent[i] = i;
//         }
//     }

//     int findUPar(int node){
//         if(node == parent[node]){
//             return node;
//         }
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v){
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if(ulp_u == ulp_v) return;
//         if(sizeofComp[ulp_u] < sizeofComp[ulp_v]){
//             parent[ulp_u] = ulp_v;
//             sizeofComp[ulp_v] += sizeofComp[ulp_u]; 
//         }
//         else{
//             parent[ulp_v] = ulp_u;
//             sizeofComp[ulp_u] += sizeofComp[ulp_v]; 
//         }
//     }
// };
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     int comps = n;
//     int biggestcomp = 1;
//     DisjointSet ds(n);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         if(ds.findUPar(u) != ds.findUPar(v)){
//             ds.unionBySize(u, v);
//             comps--;
//             biggestcomp = max(biggestcomp, max(ds.sizeofComp[ds.findUPar(u)], ds.sizeofComp[ds.findUPar(v)]));
//         }
//         cout << comps << " " << biggestcomp << "\n";
//     }
// }

// // Flights Route check
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1), adjRev(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adjRev[v].push_back(u);
//     }
//     vector<int> visited(n + 1, 0);
//     visited[1] = 1;
//     queue<int> q;
//     q.push(1);
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         for(auto it : adj[curr]){
//             if(!visited[it]){
//                 visited[it] = 1;
//                 q.push(it);
//             }
//         }
//     }
//     for(int i = 1; i <= n; i++){
//         if(visited[i] == 0){
//             cout << "NO\n";
//             cout << 1 << " " << i << "\n";
//             return;
//         }
//     }

//     fill(visited.begin(), visited.end(), 0);
//     visited[1] = 1;
//     q.push(1);
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         for(auto it : adjRev[curr]){
//             if(!visited[it]){
//                 visited[it] = 1;
//                 q.push(it);
//             }
//         }
//     }
//     for(int i = 1; i <= n; i++){
//         if(visited[i] == 0){
//             cout << "NO\n";
//             cout << i << " " << 1 << "\n";
//             return;
//         }
//     }
//     cout << "YES\n";
//     return;
// }

// // Planets and Kingdoms
// void dfs1(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st){
//     visited[node] = 1;
//     for(auto it : adj[node]){
//         if(!visited[it]){
//             dfs1(it, adj, visited, st);
//         }
//     }
//     st.push(node);
// }

// void dfs2(int node, vector<vector<int>> &adjRev, vector<int> &visited, int sccNum, vector<int> &scc){
//     visited[node] = 1;
//     scc[node] = sccNum;
//     for(auto it : adjRev[node]){
//         if(!visited[it]){
//             dfs2(it, adjRev, visited, sccNum, scc);
//         }
//     }
// }
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);
//     vector<vector<int>> adjRev(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adjRev[v].push_back(u);
//     }
//     vector<int> visited(n + 1, 0);
//     int sccNum = 1;
//     vector<int> scc(n + 1);
//     stack<int> st;
//     for(int i = 1; i <= n; i++){
//         if(!visited[i]){
//             dfs1(i, adj, visited, st);
//         }
//     }
//     fill(visited.begin(), visited.end(), 0);
//     while(!st.empty()){
//         int node = st.top();
//         st.pop();
//         if(!visited[node]){
//             dfs2(node, adjRev, visited, sccNum, scc);
//             sccNum++;
//         }
//     }
//     cout << sccNum - 1 << "\n";
//     for(int i = 1; i <= n; i++){
//         cout << scc[i] << " ";
//     }
//     cout << "\n";
// }

// coin collector


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}