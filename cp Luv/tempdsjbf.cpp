#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int to_find){
    int lo = 0;
    int hi = v.size() - 1;
    while(lo <= hi){
        int mid = (hi + lo) / 2;
        if(v[mid] < to_find){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--){
        vector<int> a = {1, 2, 2, 2, 5};
        cout << binarySearch(a, 5) - binarySearch(a, 2);
        for(auto it : a){
            cout << it << " ";
        }
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
    }
    return 0;
}