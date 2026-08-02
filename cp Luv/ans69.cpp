#include <bits/stdc++.h>
using namespace std;

bool yes(int n)
{
    int sq = n * n;
    int cu = n * n * n;
    set<int> vec;
    while (sq > 0){
        vec.insert(sq % 10);
        sq /= 10;
    }
    while (cu > 0) {
        vec.insert(cu % 10);
        cu /= 10;
    }
    if (vec.size() == 10 and accumulate(vec.begin(), vec.end(), 0) == 45){
        // for(auto i : vec){
        //     cout << i << " ";
        // }
        // cout << endl;
        return true;
    }
    return false;
}

int main()
{
    for (int i = 12; i < 100; i++)
        if (yes(i))
            cout << i << endl;
    return 0;
}