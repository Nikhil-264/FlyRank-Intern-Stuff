// Generate ;peranthesis using advanced recurrtion and backtracking
// Given n number of parenthesis write a function ot generate all the combinations of well formed parenthesis
// advanced recurtion and backtracking
#include <bits/stdc++.h>
using namespace std;

vector <string> valid;

// use of pop_back is because // as string is being passed by refernce so all the recursive function will have same string // its like undo process not to pass the the changed string into the same function call and that pop_back is call back tracking

void generate(string &s, int open, int close)
{
    if(open == 0 && close == 0)
    {
        valid.push_back(s);
        return;
    }

    if(open > 0){
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();   
    }

    if(close > 0){
        if(open < close){
            s.push_back(')');
            generate(s, open , close-1);
            s.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    generate(s, n, n);
    for (auto i : valid)
    {
        cout << i << endl;
    }
    return 0;
}