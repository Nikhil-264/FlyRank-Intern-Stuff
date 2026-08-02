//prioroty queue
// stl 
// like stack but keeps the higest element on the top
#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int> > pq;
    for (int i = 0; i < n - 1; i++){
        pq.push({arr[i + 1] - arr[i], i});
    }
    for(int gasStation = 1; gasStation <= k; gasStation++){
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSection = iniDiff / (long double)(howMany[secInd] + 1);
        pq.push({newSection, secInd});
    }
    return pq.top().first;
}

class PriorityQueue {
    public:
        priority_queue<int, vector<int>, greater<int>> pq;
        
        void push(int val)
        {
            pq.push(val);
        }
        
        int pop()
        {
            if (empty()) return -1;
            
            int res = pq.top();
            pq.pop();
            return res;
        }
        
        bool empty() const
        {
            return pq.empty();
        }
};
int main()
{   
    
    return 0;
}