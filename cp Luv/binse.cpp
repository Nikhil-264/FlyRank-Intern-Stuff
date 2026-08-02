// Nikhil Mahindrakar
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int to_find)
{
    int lo = 0, hi = v.size() - 1, mid;
    // this implemenetaion is from luv sir can be different for different case
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (v[mid] < to_find)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] == to_find)
        return lo;
    else if (v[hi] == to_find)
        return hi;
    else
        return -1;
    // Time complexity is O(log n);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int find;
    cin >> find;
    int ans = binarySearch(v, find);
    cout << ans << endl;

    return 0;
}