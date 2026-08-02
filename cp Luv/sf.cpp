#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, int> m;

    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(1, 30));
    m.insert(make_pair(3, 40));
    m.insert(make_pair(1, 50));

    int target = 1; // Target value to search for

    auto range = m.equal_range(target);
    auto it = range.first;
    cout << it->first << " " << it->second << endl;
    // ++it;
    // ++it;
    // ++it;
    it = range.second;
    --it;
    cout << it->first << " " << it->second << endl;
    // for (auto it = range.first; it != range.second; ++it) {
    //     cout << "Key: " << it->first << ", Value: " << it->second << endl;
    // }

    return 0;
}
