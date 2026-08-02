#include <bits/stdc++.h>
using namespace std;

void print(set<string> &s)
{
    // for (string value : s)
    // {
    //     cout << value << endl;
    // }
    // or
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }
}
int main()
{
    set<string> s;
    // it will store in sorted order
    s.insert("ok");
    s.insert("wtf"); // log(n) complexity
    s.insert("bkl");
    s.insert("bkl");
    s.insert("bkl"); // as it is a set it will not take duplicate value
    s.find("ok");
    auto it = s.find("ok");
    // print(s);
    // if(it != s.end())
    // {
    //     cout << (*it) << endl;
    // }
    s.erase("ok");
    print(s);
    return 0;
}
// same as maps we can use unordered sets to to reduce time complexity 