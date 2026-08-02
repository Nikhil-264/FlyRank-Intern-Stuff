#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int min = *min_element(v.begin(), v.end());   // finds minimum element in vector
    cout << min << endl;
    int max = *max_element(v.begin(), v.end());   // finds maximum elemenmt in vector
    cout << max << endl;
    int sum = accumulate(v.begin(), v.end(), 0);  // third argument provided is initial sum and it will add vector ar array sum in initial sum
    cout << sum << endl;
    int ct = count(v.begin(), v.end(), 6);        // will give the count of the element we prvided as thord argument
    cout << ct << endl;
    int element = *find(v.begin(), v.end(), 2);   // will return pointer to the elment
    reverse(v.begin(), v.end());                  // will reverse string, array, vector
    return 0;
}