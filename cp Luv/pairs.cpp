#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, string> p;
    // inserting value in pair
    // Method 1
    p = make_pair(2, "abc");
    // Method 2
    p = {2, "abcd"};
    pair<int, string> &p1 = p;
    p1.first = 3;
    cout << p.first << " " << p.second << endl;

    int a[] = {1, 56, 3};
    int b[] = {2, 3, 4};
    pair<int, int> p_array[3];//array of pairs
    for (int i = 0; i < 3; i++)
        p_array[i] = {a[i], b[i]};
    swap(p_array[0], p_array[2]);
    for (int i = 0; i < 3; i++)
    {
        cout << p_array[i].first << " " << p_array[i].second << endl;
    }
    
    
    return 0;
}