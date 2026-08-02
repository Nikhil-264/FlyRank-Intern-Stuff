#include <bits/stdc++.h>
using namespace std;
void printMap(multimap<int, string> &m)
{
    cout <<  "SIZE : " << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main()
{
    multimap<int, string> m;
    m.insert(make_pair(1,"amu"));
    m.insert(make_pair(1,"nik"));
    m.insert(make_pair(56,"hello"));
    m.insert(make_pair(45,"beautiful"));
    // m[43] = "edr";// this type of input only for maps not multimaps
    // m[5] = "abcdf";//time complexity ==> O(log(n))
    // or u can insert like this
    // m.insert({7, "amu"});
    // map<int, string> :: iterator it;
    // for ( it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }
    // map  store the data in sorted order u can see a exapmle
    // using auto
    // m[78] = "I MISS YOU";//it will declare the empty string and it will consume the time of log(n)
    // m[5] = "see its changed";// will change the existing value and consume the same time as declaration
    // printMap(m);
    // auto it = m.find(43);// it will return iterator
    // if(it == m.end()){
    //     cout << "No value";
    // }
    // else cout << it->first << " " << it->second << endl;
    // m.erase(1);
    // m.erase(it);
    // printMap(m);
    // m.clear();
    printMap(m);
    return 0;
}
