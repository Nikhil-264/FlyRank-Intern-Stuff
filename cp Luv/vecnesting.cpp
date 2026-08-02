#include <bits/stdc++.h>
using namespace std;

void printVec(vector<pair<int, int>> &v)
{
    cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl; // v[i] here is pair
    }
}
int main()
{
    vector<pair<int, int>> v = {{1, 2}, {45, 7}};
    printVec(v);
    v.push_back({34,67});
    printVec(v);
    v.pop_back();
    v.pop_back();
    printVec(v);

    return 0;
}