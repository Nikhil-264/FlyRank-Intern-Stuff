#include <bits/stdc++.h>
using namespace std;

int main()
{
    //     auto sum = [](int x, int y){return x + y;}; // declaeration of lamnda finction
    //     cout << sum(43, 7) << endl;
    vector<int> v = {2, -3, 5};
    cout << all_of(v.begin(), v.end(), [](int x)
                   { return x > 0; });
    // its saying all the element are positive
    // all_of function will check all the elemnnts in hr range anf thr gic=ven condition is true for "ALL ELEMENTs" will retun true
    // any_of // will function as same as the all_of but if any one of the elements valids the condition it will return true otherwise flase
    // none_of // will return true if none of the elements follow thr condition
    return 0;
}