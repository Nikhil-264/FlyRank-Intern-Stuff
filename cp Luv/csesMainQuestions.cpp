#include <bits/stdc++.h>
using namespace std;

// Trailing zeroes in factorial of a number
// void solve(){
//     int n;
//     cin >> n;
//     int count = 0;
//     for(int i = 5; n / i >= 1; i *= 5){
//         count += n / i;
//     }
//     cout << count << "\n";
// }

// Coin piles
// void solve(){
//     int x, y;
//     cin >> x >> y;
//     if((x + y) % 3 != 0){
//         cout << "NO\n";
//         return;
//     }
//     if(min(x, y) * 2 < max(x, y)){
//         cout << "NO\n";
//         return;
//     }
//     cout << "YES\n";
// }


// Palindrome reorder
// void solve(){
//     string s;
//     cin >> s;
//     unordered_map<char, int> freq;
//     for(char c : s){
//         freq[c]++;
//     }
//     int odd = 0;
//     for(auto it : freq){
//         if(it.second % 2 != 0){
//             odd++;
//             if(odd > 1){
//                 cout << "NO SOLUTION\n";
//                 return;
//             }
//         }
//     }
//     string firstHalf = "", middle = "";
//     for(auto it : freq){
//         if(it.second % 2 == 0){
//             firstHalf += string(it.second / 2, it.first);
//         }
//         else{
//             firstHalf += string(it.second / 2, it.first);
//             middle += it.first;
//         }
//     }
//     string secondHalf = firstHalf;
//     reverse(secondHalf.begin(), secondHalf.end());
//     cout << firstHalf + middle + secondHalf + "\n";
// }

// The gray code
// void solve(){
//     int n;
//     cin >> n;
//     vector<string> prev = {"0", "1"};
//     vector<string> curr;
//     for(int i = 1; i < n; i++){
//         curr.clear();
//         for(int j = 0; j < prev.size(); j++){
//             curr.push_back("0" + prev[j]);
//         }
//         for(int j = prev.size() - 1; j >= 0; j--){
//             curr.push_back("1" + prev[j]);
//         }
//         prev = curr;
//     }
//     for(auto it : prev){
//         cout << it << "\n";
//     }
// }

// Tower of Hanoi
// void hanoi(int n, int from, int to, int through){
//     if(n == 0) return;
//     hanoi(n - 1, from, through, to);
//     cout << from << " " << to << "\n";
//     hanoi(n - 1, through, to, from);
// }
// void solve(){
//     int n;
//     cin >> n;
//     cout << (1LL << n) - 1 << "\n";
//     hanoi(n, 1, 3, 2); 
// }

// creating string cses problem
// void changeCharacters(string s, int index, int iterator, map<string, bool> & used){
//     if(iterator == s.size() - 1){
//         used[s] = true;
//         return;
//     }
//     for(int i = 0; i <= s.size() - 1; i++){
//         swap(s[iterator], s[i]);
//         changeCharacters(s, 0, iterator + 1, used);
//         swap(s[iterator], s[i]);
//     }
// }

// void solve(){
//     string s;
//     cin >> s;
//     int n = s.size();
//     sort(s.begin(), s.end());
//     map<string, bool> used;
//     int index = 0;
//     int iterator = 0;
//     changeCharacters(s, 0, 0, used);
//     cout << used.size() << "\n";
//     for(auto it : used){
//         cout << it.first << "\n";
//     }
//     return;
// }

// Minimum subset sum difference
// void solve(){
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     long long sum = 0;
//     for(int i = 0; i < n; i++){
//         sum += a[i];
//     }
//     long long min_diff = LLONG_MAX;
//     for(int mask = 0; mask < (1 << n); mask++){
//         long long subset_sum = 0;
//         for(int j = 0; j < n; j++){
//             if(mask & (1 << j)){
//                 subset_sum += a[j];
//             }
//         }
//         long long other_subset_sum = sum - subset_sum;
//         long long diff = abs(subset_sum - other_subset_sum);
//         min_diff = min(min_diff, diff);
//     }
//     cout << min_diff << "\n";
// }

// Distinct Numbers
// void solve(){
//     int n;
//     cin >> n;
//     set<int> distinct;
//     for(int i = 0; i < n; i++){
//         int x;
//         cin >> x;
//         distinct.insert(x);
//     }
//     cout << distinct.size() << "\n";
// }

// Apartments
// void solve(){
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> a(n), b(m);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < m; i++){
//         cin >> b[i];
//     }
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     int count = 0;

//     int i = 0, j = 0;
//     while(i < n && j < m){
//         if(abs(a[i] - b[j]) <= k){
//             count++;
//             i++;
//             j++;
//         }
//         else if(a[i] < b[j]){
//             i++;
//         }
//         else{
//             j++;
//         }
//     }

//     cout << count << "\n";
// }

// Ferris Wheel
// void solve(){
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     int ct = 0;
//     int i = 0, j = n - 1;
//     while(i <= j){
//         if(a[i] + a[j] <= x){
//             i++;
//             j--;
//         }
//         else{
//             j--;
//         }
//         ct++;
//     }
//     cout << ct << "\n";
// }

// Consert Tickets
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     multiset<int> tickets;
//     for(int i = 0; i < n; i++){
//         int price;
//         cin >> price;
//         tickets.insert(price);
//     }
//     for(int i = 0; i < m; i++){
//         int t;
//         cin >> t;
//         auto it = tickets.upper_bound(t);
//         if(it == tickets.begin()){
//             cout << -1 << "\n";
//         }
//         else{
//             cout << *(--it) << "\n";
//             tickets.erase(it);
//         }
//     }
// }

// Room Allocation
// void solve(){
//     int n;
//     cin >> n;
//     vector<pair<int, int>> intervals(n);
//     for(int i = 0; i < n; i++){
//         cin >> intervals[i].first >> intervals[i].second;
//     }
//     sort(intervals.begin(), intervals.end());
//     int ct = 0;
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for(int i = 0; i < n; i++){
//         while(!pq.empty() and pq.top() <= intervals[i].first){
//             pq.pop();
//         }
//         pq.push(intervals[i].second);
//         ct = max(ct, (int)pq.size());
//     }
//     cout << ct << "\n";
// }

// Movie Festival
// void solve(){
//     int n;
//     cin >> n;
//     vector<pair<int, int>> movies(n);
//     for(int i = 0; i < n; i++){
//         cin >> movies[i].first >> movies[i].second;
//     }
//     int ans = 1;
//     sort(movies.begin(), movies.end(), [](pair<int, int> &a, pair<int, int> &b){
//         return a.second < b.second;
//     });
//     int last_end = movies[0].second;
//     for(int i = 1; i < n; i++){
//         if(movies[i].first >= last_end){
//             ans++;
//             last_end = movies[i].second;
//         }
//     }
//     cout << ans << "\n";
// }

//  Sum of two values
// void solve(){
    // int n, x;
    // cin >> n >> x;
    // vector<pair<int, int>> a(n);
    // for(int i = 0; i < n; i++){
    //     cin >> a[i].first;
    //     a[i].second = i + 1;
    // }
    // sort(a.begin(), a.end());
    // int i = 0, j = n - 1;
    // while(i < j){
    //     if(a[i].first + a[j].first == x){
    //         cout << a[i].second << " " << a[j].second << "\n";
    //         return;
    //     }
    //     else if(a[i].first + a[j].first < x){
    //         i++;
    //     }
    //     else{
//             j--;
//         }
//     }
//     cout << "IMPOSSIBLE\n";
// }

// // Maximum Subarray Sum
// void solve(){
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     bool all_negative = true;
    
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         if(a[i] >= 0){
//             all_negative = false;
//         }
//     }
//     long long sum = 0;
//     long long ans = 0;
//     for(int i = 0; i < n; i++){
//         // we have to add minimum 1 element from the array to take the sum, if all negative, we have to return the maximum element
//         if(all_negative){
//             cout << *max_element(a.begin(), a.end()) << "\n";
//             return;
//         }
//         sum += a[i];
//         ans = max(ans, sum);
//         if(sum < 0){
//             sum = 0;
//         }
//     }
//     cout << ans << "\n";
// }

// stick lengths
// void solve(){
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     long long finalLength = a[n / 2];

//     long long count = 0;
//     for(int i = 0; i < n; i++){
//         count += abs(a[i] - finalLength);
//     }
//     cout << count << "\n";
// }

// missing coin sum

// void solve(){
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     long long res = 1;
//     for(int i = 0; i < n; i++){
//         if(a[i] > res){
//             break;
//         }
//         res += a[i];
//     }
//     cout << res << "\n";
// }

// collecting numbers
// void solve(){
//     int n;
//     cin >> n;
//     unordered_map<int, int> position;
//     for(int i = 0; i < n; i++){
//         int x;
//         cin >> x;
//         position[x] = i;
//     }
//     int ans = 1;
//     for(int i = 1; i < n; i++){
//         if(position[i] > position[i + 1]){
//             ans++;
//         }
//     }
//     cout << ans << "\n";
// }

// Playlists
// void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     map<int, int> lastPosition;
//     int l = 0;
//     int maxLength = 0;
//     for(int r = 0; r < n; r++){
//         if(lastPosition.find(a[r]) != lastPosition.end()){
//             l = max(l, lastPosition[a[r]] + 1);
//         }
//         lastPosition[a[r]] = r;
//         maxLength = max(maxLength, r - l + 1);
//     }
//     cout << maxLength << "\n";
// }

// Towers
// void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     vector<int> ans = {a[0]};
//     for(int i = 1; i < n; i++){
//         auto it = upper_bound(ans.begin(), ans.end(), a[i]);
//         if(it == ans.end()){
//             ans.push_back(a[i]);
//         }
//         else{
//             ans[it - ans.begin()] = a[i];
//         }
//     }
//     cout << ans.size() << "\n";
// }

// Traffic Lights
// void solve(){
//     int x, n;
//     cin >> x >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     set<pair<int, int>> segments;
//     segments.insert({0, x});
//     multiset<int> lengths;
//     lengths.insert(x);
//     for(int i = 0; i < n; i++){
//         int pos = a[i];
//         auto it = segments.lower_bound({pos + 1, 0});
//         it--;
//         int start = it->first;
//         int end = it->second;
//         segments.erase(it);
//         lengths.erase(lengths.find(end - start));
//         segments.insert({start, pos});
//         segments.insert({pos, end});
//         lengths.insert(pos - start);
//         lengths.insert(end - pos);
//         cout << *lengths.rbegin() << " ";
//     }   
// }

// Josephus Problem 1
// void solve(){
//     int n;
//     cin >> n;
//     queue<int> q;
//     for(int i = 1; i <= n; i++){
//         q.push(i);
//     }
//     while(q.size() > 1){
//         q.push(q.front());
//         q.pop();
//         cout << q.front() << " ";
//         q.pop();
//     }
//     cout << q.front() << "\n";
// }

// Room allocation
// void solve(){
//     int n;
//     cin >> n;
    
//     vector<vector<int>> intervals(n, vector<int>(3));
//     for(int i = 0; i < n; i++){
//         cin >> intervals[i][0] >> intervals[i][1];
//         intervals[i][2] = i; // original index
//     }
//     sort(intervals.begin(), intervals.end());
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <end time, room number>

//     vector<int> roomAssignment(n);
//     int roomCount = 0;
    
//     for(auto it : intervals){
//         int start  = it[0];
//         int end = it[1];
//         int index = it[2];

//         if(!pq.empty() and pq.top().first < start){
//             auto room = pq.top();
//             pq.pop();
//             roomAssignment[index] = room.second;
//             pq.push({end, room.second});
//         }else{
//             roomCount++;
//             roomAssignment[index] = roomCount;
//             pq.push({end, roomCount});
//         }
//     }
//     cout << roomCount << "\n";
//     for(auto it : roomAssignment){
//         cout << it << " ";
//     }
// }

// Digit Queries
// void solve(){
//     long long k;
//     cin >> k;
//     long long digits = 1;
//     long long num = 9;
//     while(num < k){
//         k -= num;
//         num = num / digits;
//         num *= 10;
//         digits++;
//         num = num * digits;
//         // cout << num << " " << digits << "\n";
//     }
//     long long index = (k - 1) / digits;
//     long long rem = (k - 1) % digits;
//     long long start = 1;
//     for(int i = 1; i < digits; i++){
//         start *= 10;
//     }
//     start += index;
//     string s = to_string(start);
//     cout << s[rem] << "\n";
// }

// Factory Machines
// void solve(){
//     long long n, t;
//     cin >> n >> t;
//     vector<long long> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     long long low = 1, high = LLONG_MAX, ans = -1;
//     while(low <= high){
//         long long mid = low + (high - low) / 2;
//         long long count = 0LL;
//         for(int i = 0; i < n; i++){
//             count += mid / a[i];
//             if(count >= t){
//                 break;
//             }
//         }
//         if(count >= t){
//             ans = mid;
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }
//     cout << ans << "\n";
// }

// Tasks and deadlines
// void solve(){
//     int n;
//     cin >> n;

//     vector<pair<int, int>> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i].first >> a[i].second; // duration, deadline
//     }

//     sort(a.begin(), a.end()); // sort by duration

//     long long current_time = 0;
//     long long reward = 0;

//     for(int i = 0; i < n; i++){
//         current_time += a[i].first;
//         reward += (long long)a[i].second - current_time;
//     }

//     cout << reward << "\n";
// }

// Reading books
// void solve(){
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     long long summation = 0;
//     long long maxElement = LONG_LONG_MIN;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         summation += (long long)a[i];
//         maxElement = max(maxElement, a[i]);
//     }
//     cout << max(2 * maxElement, summation) << "\n";
// }

// ThreeSome
// void solve(){
//     int n, k;
//     cin >> n >> k;
//     // vector<int> a(n);
//     vector<pair<int, int>> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i].first;
//         a[i].second = i + 1;
//     }
//     sort(a.begin(), a.end());
//     vector<vector<int>> ans;
//     for(int i = 0; i < n; i++){
//         int left = i + 1;
//         int right = n - 1;
//         while(left < right){
//             int currentSum = a[i].first + a[left].first + a[right].first;
//             if(currentSum == k){
//                 vector<int> temp = {};
//                 temp.push_back(a[i].second);
//                 temp.push_back(a[left].second);
//                 temp.push_back(a[right].second);
//                 sort(temp.begin(), temp.end());
//                 ans.push_back(temp);
//                 break;
//             }else if(currentSum < k){
//                 left++;
//             }else{
//                 right--;
//             }
//         }
//     }
//     sort(ans.begin(), ans.end());
//     if(ans.size() == 0){
//         cout << "IMPOSSIBLE\n";
//     }else{
//         for(auto it : ans[0]){
//             cout << it << " ";
//         }
//     }   
// }

// foursome
void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int left = j + 1;
            int right = n - 1;
            while(left < right){
                int currentSum = a[i].first + a[j].first + a[left].first + a[right].first;
                if(currentSum == k){
                    vector<int> temp = {};
                    temp.push_back(a[i].second);
                    temp.push_back(a[j].second);
                    temp.push_back(a[left].second);
                    temp.push_back(a[right].second);
                    sort(temp.begin(), temp.end());
                    ans.push_back(temp);
                    break;
                }else if(currentSum < k){
                    left++;
                }else{
                    right--;
                }
            }
        }
    }   
    sort(ans.begin(), ans.end());
    if(ans.size() == 0){
        cout << "IMPOSSIBLE\n";
    }else{
        for(auto it : ans[0]){
            cout << it << " ";
        }
    }   
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}