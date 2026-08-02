#include <bits/stdc++.h>
using namespace std;
char upper(char c)
{
    c = 'A' + c - 'a';
    return c;
}
int main()
{
    while(true){
        string s;
        cin>>s;
        if (s.size()==0) break;
        for (int i = 0; i < s.size(); i++)
            s[i] = upper(s[i]);
        cout << s << endl;
    }

    return 0;
}