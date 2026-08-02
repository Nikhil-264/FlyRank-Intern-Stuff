#include <bits/stdc++.h>
using namespace std;

// // Static Range Sum Queries
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

// long long query(int index, int left, int right, int l, int r, vector<int> &a, vector<long long> &segmentTree){
//     // No overlap
//     if(r < left || l > right){
//         return 0;
//     }

//     // complete overlap
//     if(l <= left and r >= right){
//         return segmentTree[index];
//     }
//     // partial overlap
//     int mid = left + (right - left) / 2;
//     long long leftSum = query(2 * index + 1, left, mid, l, r, a, segmentTree);
//     long long rightSum = query(2 * index + 2, mid + 1, right, l, r, a, segmentTree);
//     return leftSum + rightSum;
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<long long> segmentTree(4 * n);
//     buildTree(0, 0, n - 1, a, segmentTree);
//     for(int i = 0; i < q; i++){
//         int l, r;
//         cin >> l >> r;
//         l--; r--;
//         long long ans = query(0, 0, n - 1, l, r, a, segmentTree);
//         cout << ans << "\n";
//     }
// }

// // Static Range Minimum Queries
// void buildTree(int index, int left, int right, vector<int> &a, vector<int> &segmentTree){
//     if(left == right){
//         segmentTree[index] = a[left];
//         return;
//     }

//     int mid = left + (right - left) / 2;    
//     buildTree(2 * index + 1, left, mid, a, segmentTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segmentTree);
//     segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
// }

// int query(int index, int left, int right, int l, int r, vector<int> &a, vector<int> &segmentTree){
//     // No overlap
//     if(r < left || l > right){
//         return INT_MAX;
//     }

//     // complete overlap
//     if(l <= left and r >= right){
//         return segmentTree[index];
//     }
//     // partial overlap
//     int mid = left + (right - left) / 2;
//     int leftMin = query(2 * index + 1, left, mid, l, r, a, segmentTree);
//     int rightMin = query(2 * index + 2, mid + 1, right, l, r, a, segmentTree);
//     return min(leftMin, rightMin);
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<int> segmentTree(4 * n);
//     buildTree(0, 0, n - 1, a, segmentTree);
//     for(int i = 0; i < q; i++){
//         int l, r;
//         cin >> l >> r;
//         l--; r--;
//         int ans = query(0, 0, n - 1, l, r, a, segmentTree);
//         cout << ans << "\n";
//     }
// }

// // Dynamic Range Sum Queries
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

// long long query(int index, int left, int right, int l, int r, vector<int> &a, vector<long long> &segmentTree){
//     // No overlap
//     if(r < left || l > right){
//         return 0;
//     }

//     // complete overlap
//     if(l <= left and r >= right){
//         return segmentTree[index];
//     }
//     // partial overlap
//     int mid = left + (right - left) / 2;
//     long long leftSum = query(2 * index + 1, left, mid, l, r, a, segmentTree);
//     long long rightSum = query(2 * index + 2, mid + 1, right, l, r, a, segmentTree);
//     return leftSum + rightSum;
// }

// void update(int index, int left, int right, int pos, int val, vector<int>&a, vector<long long>&segmentTree){
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
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<long long> segmentTree(4 * n);
//     buildTree(0, 0, n - 1, a, segmentTree);

//     for(int i = 0; i < q; i++){
//         int type;
//         cin >> type;
//         if(type == 2){
//             int l, r;
//             cin >> l >> r;
//             l--; r--;
//             long long ans = query(0, 0, n - 1, l, r, a, segmentTree);
//             cout << ans << "\n";
//         } else {
//             int pos, val;
//             cin >> pos >> val;
//             pos--;
//             update(0, 0, n - 1, pos, val, a, segmentTree);
//         }
//     }
// }

// Dynamic Range Minimum Queries
// void buildTree(int index, int left, int right, vector<int> &a, vector<int> &segmentTree){
//     if(left == right){
//         segmentTree[index] = a[left];
//         return;
//     }

//     int mid = left + (right - left) / 2;    
//     buildTree(2 * index + 1, left, mid, a, segmentTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segmentTree);
//     segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
// }

// int query(int index, int left, int right, int l, int r, vector<int> &a, vector<int> &segmentTree){
//     // No overlap
//     if(r < left || l > right){
//         return INT_MAX;
//     }

//     // complete overlap
//     if(l <= left and r >= right){
//         return segmentTree[index];
//     }
//     // partial overlap
//     int mid = left + (right - left) / 2;
//     int leftMin = query(2 * index + 1, left, mid, l, r, a, segmentTree);
//     int rightMin = query(2 * index + 2, mid + 1, right, l, r, a, segmentTree);
//     return min(leftMin, rightMin);
// }

// void update(int index, int left, int right, int pos, int val, vector<int>&a, vector<int>&segmentTree){
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
//     segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<int> segmentTree(4 * n);
//     buildTree(0, 0, n - 1, a, segmentTree);

//     for(int i = 0; i < q; i++){
//         int type;
//         cin >> type;
//         if(type == 2){
//             int l, r;
//             cin >> l >> r;
//             l--; r--;
//             long long ans = query(0, 0, n - 1, l, r, a, segmentTree);
//             cout << ans << "\n";
//         } else {
//             int pos, val;
//             cin >> pos >> val;
//             pos--;
//             update(0, 0, n - 1, pos, val, a, segmentTree);
//         }
//     }
// }

// XOR Queries
// void buildTree(int index, int left, int right, vector<int> &a, vector<int> &segmentTree){
//     if(left == right){
//         segmentTree[index] = a[left];
//         return;
//     }

//     int mid = left + (right - left) / 2;    
//     buildTree(2 * index + 1, left, mid, a, segmentTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segmentTree);
//     segmentTree[index] = segmentTree[2 * index + 1] ^ segmentTree[2 * index + 2];
// }

// int query(int index, int left, int right, int l, int r, vector<int> &a, vector<int> &segmentTree){
//     // No overlap
//     if(r < left || l > right){
//         return 0;
//     }

//     // complete overlap
//     if(l <= left and r >= right){
//         return segmentTree[index];
//     }
//     // partial overlap
//     int mid = left + (right - left) / 2;
//     int leftMin = query(2 * index + 1, left, mid, l, r, a, segmentTree);
//     int rightMin = query(2 * index + 2, mid + 1, right, l, r, a, segmentTree);
//     return leftMin ^ rightMin;
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<int> segmentTree(4 * n);
//     buildTree(0, 0, n - 1, a, segmentTree);

//     for(int i = 0; i < q; i++){
//         int l, r;
//         cin >> l >> r;
//         l--; r--;
//         long long ans = query(0, 0, n - 1, l, r, a, segmentTree);
//         cout << ans << "\n";
//     }
// }


// 2D Range Sum Queries
// void buildY(int nodeX, int nodeY,
//             int leftY, int rightY,
//             int row,
//             vector<vector<int>> &a,
//             vector<vector<long long>> &segmentTree) {

//     if (leftY == rightY) {
//         segmentTree[nodeX][nodeY] = a[row][leftY];
//         return;
//     }

//     int midY = leftY + (rightY - leftY) / 2;

//     buildY(nodeX, 2 * nodeY + 1, leftY, midY, row, a, segmentTree);
//     buildY(nodeX, 2 * nodeY + 2, midY + 1, rightY, row, a, segmentTree);

//     segmentTree[nodeX][nodeY] =
//         segmentTree[nodeX][2 * nodeY + 1] +
//         segmentTree[nodeX][2 * nodeY + 2];
// }

// void buildX(int nodeX, int leftX, int rightX,
//             vector<vector<int>> &a,
//             vector<vector<long long>> &segmentTree) {

//     if (leftX == rightX) {
//         buildY(nodeX, 0, 0, m - 1, leftX, a, segmentTree);
//         return;
//     }

//     int midX = leftX + (rightX - leftX) / 2;

//     buildX(2 * nodeX + 1, leftX, midX, a, segmentTree);
//     buildX(2 * nodeX + 2, midX + 1, rightX, a, segmentTree);

//     // Merge Y-trees
//     for (int i = 0; i < 4 * m; i++) {
//         segmentTree[nodeX][i] =
//             segmentTree[2 * nodeX + 1][i] +
//             segmentTree[2 * nodeX + 2][i];
//     }
// }

// void updateY(int nodeX, int nodeY,
//              int leftY, int rightY,
//              int y, long long val,
//              vector<vector<long long>> &segmentTree) {

//     if (leftY == rightY) {
//         segmentTree[nodeX][nodeY] = val;
//         return;
//     }

//     int midY = leftY + (rightY - leftY) / 2;

//     if (y <= midY)
//         updateY(nodeX, 2 * nodeY + 1, leftY, midY, y, val, segmentTree);
//     else
//         updateY(nodeX, 2 * nodeY + 2, midY + 1, rightY, y, val, segmentTree);

//     segmentTree[nodeX][nodeY] =
//         segmentTree[nodeX][2 * nodeY + 1] +
//         segmentTree[nodeX][2 * nodeY + 2];
// }
// void updateX(int nodeX, int leftX, int rightX,
//              int x, int y, long long val,
//              vector<vector<long long>> &segmentTree) {

//     if (leftX == rightX) {
//         updateY(nodeX, 0, 0, m - 1, y, val, segmentTree);
//         return;
//     }

//     int midX = leftX + (rightX - leftX) / 2;

//     if (x <= midX)
//         updateX(2 * nodeX + 1, leftX, midX, x, y, val, segmentTree);
//     else
//         updateX(2 * nodeX + 2, midX + 1, rightX, x, y, val, segmentTree);

//     // Re-merge Y-trees
//     for (int i = 0; i < 4 * m; i++) {
//         segmentTree[nodeX][i] =
//             segmentTree[2 * nodeX + 1][i] +
//             segmentTree[2 * nodeX + 2][i];
//     }
// }
// long long queryY(int nodeX, int nodeY,
//                  int leftY, int rightY,
//                  int y1, int y2,
//                  vector<vector<long long>> &segmentTree) {

//     // No overlap
//     if (y2 < leftY || y1 > rightY)
//         return 0;

//     // Complete overlap
//     if (y1 <= leftY && rightY <= y2)
//         return segmentTree[nodeX][nodeY];

//     // Partial overlap
//     int midY = leftY + (rightY - leftY) / 2;

//     return queryY(nodeX, 2 * nodeY + 1, leftY, midY, y1, y2, segmentTree) +
//            queryY(nodeX, 2 * nodeY + 2, midY + 1, rightY, y1, y2, segmentTree);
// }
// long long queryX(int nodeX, int leftX, int rightX,
//                  int x1, int x2,
//                  int y1, int y2,
//                  vector<vector<long long>> &segmentTree) {

//     // No overlap
//     if (x2 < leftX || x1 > rightX)
//         return 0;

//     // Complete overlap
//     if (x1 <= leftX && rightX <= x2) {
//         return queryY(nodeX, 0, 0, m - 1, y1, y2, segmentTree);
//     }

//     // Partial overlap
//     int midX = leftX + (rightX - leftX) / 2;

//     return queryX(2 * nodeX + 1, leftX, midX, x1, x2, y1, y2, segmentTree) +
//            queryX(2 * nodeX + 2, midX + 1, rightX, x1, x2, y1, y2, segmentTree);
// }

//

// Hotel QUeries
// void buildTree(int index, int left, int right, vector<int> &a, vector<int> &segTree){
//     if(left == right){
//         segTree[index] = a[left];
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     buildTree(2 * index + 1, left, mid, a, segTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segTree);
//     segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
//     return;
// }

// void update(int index, int left, int right, int val, vector<int> &segTree, vector<int> &ans, int i){
//     if(segTree[index] < val){
//         return;
//     }

//     if(left == right){
//         segTree[index] = segTree[index] - val;
//         ans[i] = left + 1;
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     if(segTree[2 * index + 1] >= val){
//         update(2 * index + 1, left, mid, val, segTree, ans, i);
//     } else {
//         update(2 * index + 2, mid + 1, right, val, segTree, ans, i);
//     }
//     segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     vector<int> ans(q, 0);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<int> segTree(4 * n);
//     buildTree(0, 0, n - 1, a, segTree);
//     for(int i = 0; i < q; i++){
//         int val;
//         cin >> val;
//         if(segTree[0] >= val)
//             update(0, 0, n - 1, val, segTree, ans, i);
//         else
//             ans[i] = 0;
//     }
//     for(int i = 0; i < ans.size(); i++){
//         cout << ans[i] << " ";
//     }
// }

// List Removals
// void buildTree(int index, int left, int right, vector<int> &a, vector<int> &segTree){
//     if(left == right){
//         segTree[index] = 1;
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     buildTree(2 * index + 1, left, mid, a, segTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segTree);
//     segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
//     return;
// }

// void update(int index, int left, int right, int pos, vector<int> &segTree){
//     if(left == right){
//         segTree[index] = 0;
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     if(pos <= mid){
//         update(2 * index + 1, left, mid, pos, segTree);
//     } else {
//         update(2 * index + 2, mid + 1, right, pos, segTree);
//     }
//     segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
// }

// int query(int index, int left, int right, int pos, vector<int> &segTree, vector<int> &a){
//     if(left == right){
//         return left;
//     }

//     int mid = left + (right - left) / 2;
//     if(segTree[2 * index + 1] >= pos){
//         return query(2 * index + 1, left, mid, pos, segTree, a);
//     } else {
//         return query(2 * index + 2, mid + 1, right, pos - segTree[2 * index + 1], segTree, a);
//     }
// }

// void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<int> segTree(4 * n);
//     buildTree(0, 0, n - 1, a, segTree);
//     for(int i = 0; i < n; i++){
//         int k;
//         cin >> k;
//         int pos = query(0, 0, n - 1, k, segTree, a);
//         cout << a[pos] << " ";
//         update(0, 0, n - 1, pos, segTree);
//     }
// }

// //  Salary Queries
// void buildTree(int index, int left, int right, vector<int> &a, vector<int> &segTree){
//     if(left == right){
//         segTree[index] = a[left];
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     buildTree(2 * index + 1, left, mid, a, segTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segTree);
//     segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
// }

// void update(int index, int left, int right, int pos, int val, vector<int> &segTree){
//     if(left == right){
//         segTree[index] += val;
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     if(pos <= mid){
//         update(2 * index + 1, left, mid, pos, val, segTree);
//     } else {
//         update(2 * index + 2, mid + 1, right, pos, val, segTree);
//     }
//     segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
// }

// int query(int index, int left, int right, int l, int r, vector<int> &segTree){
//     // No overlap
//     if(r < left || l > right){
//         return 0;
//     }

//     // complete overlap
//     if(l <= left and r >= right){
//         return segTree[index];
//     }

//     // partial overlap
//     int mid = left + (right - left) / 2;

//     int leftMax = query(2 * index + 1, left, mid, l, r, segTree);
//     int rightMax = query(2 * index + 2, mid + 1, right, l, r, segTree);
//     return leftMax + rightMax;
// }

// void solve() {
//     int n, q;
//     cin >> n >> q;

//     vector<int> salary(n);
//     for (int i = 0; i < n; i++)
//         cin >> salary[i];

//     vector<pair<char, pair<int,int>>> queries;
//     vector<int> values;

//     // collect initial salaries
//     for (int x : salary)
//         values.push_back(x);

//     // read queries
//     for (int i = 0; i < q; i++) {
//         char type;
//         int a, b;
//         cin >> type >> a >> b;
//         queries.push_back({type, {a, b}});
//         if (type == '!')
//             values.push_back(b);
//         else {
//             values.push_back(a);
//             values.push_back(b);
//         }
//     }

//     // coordinate compression
//     sort(values.begin(), values.end());
//     values.erase(unique(values.begin(), values.end()), values.end());

//     auto getIndex = [&](int x) {
//         return lower_bound(values.begin(), values.end(), x) - values.begin();
//     };

//     int m = values.size();
//     vector<int> freq(m, 0);

//     // build frequency array
//     for (int x : salary)
//         freq[getIndex(x)]++;

//     vector<int> segTree(4 * m);
//     buildTree(0, 0, m - 1, freq, segTree);

//     // process queries
//     for (auto &qr : queries) {
//         char type = qr.first;
//         int a = qr.second.first;
//         int b = qr.second.second;

//         if (type == '!') {
//             int employee = a - 1;

//             // remove old salary
//             update(0, 0, m - 1, getIndex(salary[employee]), -1, segTree);

//             // add new salary
//             salary[employee] = b;
//             update(0, 0, m - 1, getIndex(b), +1, segTree);

//         } else {
//             int l = lower_bound(values.begin(), values.end(), a) - values.begin();
//             int r = upper_bound(values.begin(), values.end(), b) - values.begin() - 1;

//             if (l > r)
//                 cout << 0 << "\n";
//             else
//                 cout << query(0, 0, m - 1, l, r, segTree) << "\n";
//         }
//     }
// }

// RAnge update queries
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

// void update(int index, int start, int end, int l, int r, int val,
//             vector<long long> &tree, vector<long long> &lazy) {
    
//     // Push pending lazy update
//     if (lazy[index] != 0) {
//         tree[index] += (end - start + 1) * lazy[index];

//         if (start != end) {
//             lazy[2 * index + 1] += lazy[index];
//             lazy[2 * index + 2] += lazy[index];
//         }

//         lazy[index] = 0;
//     }

//     // No overlap
//     if (r < start || l > end)
//         return;

//     // Complete overlap
//     if (l <= start && end <= r) {
//         tree[index] += (end - start + 1) * val;

//         if (start != end) {
//             lazy[2 * index + 1] += val;
//             lazy[2 * index + 2] += val;
//         }
//         return;
//     }

//     // Partial overlap
//     int mid = start + (end - start) / 2;

//     update(2 * index + 1, start, mid, l, r, val, tree, lazy);
//     update(2 * index + 2, mid + 1, end, l, r, val, tree, lazy);

//     tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
// }

// long long query(int index, int left, int right, int k, vector<long long> &tree, vector<long long> &lazy){
//     // Push pending lazy update
//     if (lazy[index] != 0) {
//         tree[index] += (right - left + 1) * lazy[index];

//         if (left != right) {
//             lazy[2 * index + 1] += lazy[index];
//             lazy[2 * index + 2] += lazy[index];
//         }

//         lazy[index] = 0;
//     }
//     // No overlap
//     if(k < left || k > right){
//         return 0;
//     }

//     // complete overlap
//     if(left == right){
//         return tree[index];
//     }

//     // partial overlap
//     int mid = left + (right - left) / 2;
//     return query(2 * index + 1, left, mid, k, tree, lazy) + query(2 * index + 2, mid + 1, right, k, tree, lazy);
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<long long> segmentTree(4 * n);
//     buildTree(0, 0, n - 1, a, segmentTree);
//     vector<long long> lazy(4 * n, 0);
//     for(int i = 0; i < q; i++){
//         int type;
//         cin >> type;
//         if(type == 1){
//             int l, r, val;
//             cin >> l >> r >> val;
//             l--; r--;
//             update(0, 0, n - 1, l, r, val, segmentTree, lazy);
//         } else {
//             int k;
//             cin >> k;
//             k--;
//             long long ans = query(0, 0, n - 1, k, segmentTree, lazy);
//             cout << ans << "\n";
//         }
//     }
// }

// // Prefix Sum queries
// struct Node{
//     long long sum, prefixSum;
// };

// Node merge(Node a, Node b){
//     Node res;
//     res.sum = a.sum + b.sum;
//     res.prefixSum = max(a.prefixSum, a.sum + b.prefixSum);
//     return res;
// }

// void buildTree(int index, int left, int right, vector<long long> &a, vector<Node> &segmentTree){
//     if(left == right){
//         segmentTree[index].sum = a[left];
//         segmentTree[index].prefixSum = max(0LL, a[left]);
//         return;
//     }

//     int mid = left + (right - left) / 2;
//     buildTree(2 * index + 1, left, mid, a, segmentTree);
//     buildTree(2 * index + 2, mid + 1, right, a, segmentTree);

//     segmentTree[index] = merge(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
// }

// void update(int index, int left, int right, int pos, long long val, vector<Node>&segmentTree){
//     if(left == right){
//         segmentTree[index].sum = val;
//         segmentTree[index].prefixSum = max(0LL, val);
//         return;
//     }
//     int mid = left + (right - left) / 2;
//     if(pos <= mid){
//         update(2 * index + 1, left, mid, pos, val, segmentTree);
//     } else {
//         update(2 * index + 2, mid + 1, right, pos, val, segmentTree);
//     }
//     segmentTree[index] = merge(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
// }

// Node query(int index, int left, int right, int l, int r, vector<Node>& segmentTree){
//     // No overlap
//     if(r < left || l > right){
//         return {0, 0};
//     }

//     // complete overlap
//     if(l <= left and r >= right){
//         return segmentTree[index];
//     }

//     // partial overlap
//     int mid = left + (right - left) / 2;
//     Node leftQuery = query(2 * index + 1, left, mid, l, r, segmentTree);
//     Node rightQuery = query(2 * index + 2, mid + 1, right, l, r, segmentTree);
//     return merge(leftQuery, rightQuery);
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<Node> segmentTree(4 * n);
//     buildTree(0, 0, n - 1, a, segmentTree);

//     for(int i = 0; i < q; i++){
//         int type;
//         cin >> type;
//         if(type == 1){
//             int k, u;
//             cin >> k >> u;
//             update(0, 0, n - 1, k - 1, u, segmentTree);
//         } else {
//             int l, r;
//             cin >> l >> r;
//             Node ans = query(0, 0, n - 1, l - 1, r - 1, segmentTree);
//             cout << ans.prefixSum << "\n";
//         }
//     }
// }

// Pizzeria Queries


int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        // solve();
    }
    return 0;
}