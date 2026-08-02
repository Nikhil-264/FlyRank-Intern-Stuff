#include <bits/stdc++.h>
using namespace std;

void upperBound(vector<int> &arr, int val){
    int l = 0;
    int r = arr.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid] <= val){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
}

void lowerBound(vector<int> &arr, int val){
    int l = 0;
    int r = arr.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid] < val){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
}


int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(5);
    a.push_back(7);
    a.push_back(10);
    a.push_back(11);
    int val = 5;
    upperBound(a, val);
    lowerBound(a, val);
    return 0;
}