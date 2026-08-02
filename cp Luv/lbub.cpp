// Lower bound and Upper bound using binary search
//  lecture 51 luv sir
#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &v, int element)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (v[mid] < element)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid; // we are not removing the mid from search space
        }
    }
    if (v[lo] >= element)
        return lo;
    if (v[hi] >= element)
        return hi;
    return -1;
}

int upper_bound(vector<int> &v, int element)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (v[mid] <= element) // the only change from lower bound we r using here <= and in lower bound uses <
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid; // we are not removing the mid from search space
        }
    }
    if (v[lo] > element)
        return lo;
    if (v[hi] > element) // here as well we did > instead of >= unlike lower_bound
        return hi;
    return -1;
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
    int element;
    cin >> element;
    int lb = lower_bound(v, element);
    cout << lb << " " << (lb != -1 ? v[lb] : -1) << endl;
    int ub = upper_bound(v, element);
    cout << ub << " " << (ub != -1 ? v[ub] : -1) << endl;

    return 0;
}
// These are the implementations of the invuilt functions in cpp upperbound and lowerboiund using binary search