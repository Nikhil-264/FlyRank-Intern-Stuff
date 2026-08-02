#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> v = {1, 3, 5, 6, 3, 2, 56};
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // } // without using iteratior
    // cout << endl;
    // vector<int>::iterator it = v.begin();
    // cout << (*it) << endl;
    // cout << (*(it + 1)) << endl;
    // cout << (*(it + 3)) << endl;//works as a pointer in C

    // iterating using iterator
    // for (it = v.begin(); it != v.end(); ++it)
    // {
    //     cout << *it << " ";
    // } // with using iterator
    // cout << endl;
    // it++ --> next iterator
    // it = it + 1 --> next location
    vector<pair<int, int>> v_p = {{2, 3}, {45, 7}, {34, 98}};
    vector<pair<int ,int>> :: iterator it;
    for(it = v_p.begin(); it != v_p.end(); it++)
    {
        cout << (*it).first << " " <<  (*it).second << endl;
    }
    for(it = v_p.begin(); it != v_p.end(); it++)
    {
        cout << (it->first) << " " <<  (it->second) << endl;// just different syntax sam ework
    }
    return 0;
}
// cd "c:\Users\HP\Documents\Coding journeys\cp Luv\" ; if ($?) { g++ iterator.cpp -o iterator } ; if ($?) { .\iterator }
// (*it).first <==> it->first     same methods