#include <bits/stdc++.h>
using namespace std;
void print(multiset<string> &s)
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
    multiset<string> s;
    s.insert("amunik");
    s.insert("amunik");
    s.insert("amunik");
    s.insert("amunik");
    s.insert("lol");
    s.insert("abcj");
    // s.erase("amunik");//it will remove all the duplicate elements
    //to remive only one of this we can do
    auto it = s.find("amunik");
    if(it != s.end()){
        s.erase(it);
    }// useing this ew can remove only one of the duplicate
    print(s);// it will accepot duplicate value// it will stored the sorted version

    return 0;
}