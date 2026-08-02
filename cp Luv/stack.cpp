#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    s.push(3);
    s.push(54);
    s.push(4);
    s.push(7);
    s.push(0);
    // while(!s.empty()){
    //     cout << s.top() << endl;
    //     s.pop();
    // }//you know what stack is!
    cout << s.size() << endl;
    return 0;
}