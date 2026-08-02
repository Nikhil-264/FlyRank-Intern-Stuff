// // this example for vector
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
//     cout << endl;
//     auto it = upper_bound(a.begin(), a.end(), 5);
//     if (it == a.end())
//     {
//         cout << "Not Found" << endl;
//         return 0;
//     }
//     cout << (*it) << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set < int> s;
    map<int,int> m;// inly will lowerbound the key i fmultiple will return the iterator first the first appearance
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    auto it = lower_bound(s.begin(), s.end(), rand());// like this it will work as O(n) umlike in case of array and vector which is O(log(n))
    // so u can do loke this
    it = s.lower_bound(rand()); // now this will run as O(log(n))
    cout << (*it) << endl;
    
    return 0;
}