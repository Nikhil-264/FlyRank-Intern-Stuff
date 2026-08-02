#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
            s.pop();
    }
    if (s.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}