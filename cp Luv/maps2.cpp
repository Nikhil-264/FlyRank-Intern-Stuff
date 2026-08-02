// difference between oredered and unorederd maps
// 1 . inbuilt implementation
// 2. time complecxity
// .3 valid key data type
// declaration
#include <bits/stdc++.h>
using namespace std;

void printMap(unordered_map<int, string> &m)
{
    cout <<  "SIZE : " << m.size() << endl;
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main()
{
    unordered_map<int, string> m;
    m[3] = "Amu";   
    m[5] = "I";   // insertion time complexity ==> O(1) different from maps
    m[7] = "Love";   
    m[34] = "you";   
    m[1] = "Miss you";
    // differnec is it will work as a stack it wont store as stored
    // u can not use all the data typs in unordered_map like u cant use pairs
    printMap(m);   
    return 0;
}