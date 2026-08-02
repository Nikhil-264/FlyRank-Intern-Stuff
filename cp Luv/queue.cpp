#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> q;
    q.push("AMu");
    q.push("I");
    q.push("Love");
    q.push("You");
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}