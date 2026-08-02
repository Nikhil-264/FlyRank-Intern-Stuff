#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
// recursive method
int binExpRecurr(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binExpRecurr(a, b / 2);
    if (b & 1)
        return (a * ((res * 1LL * res) % M)) % M;
    else
        return (res * 1LL * res) % M;
}

int binExpItr(int a, int b){
    long long ans = 1;
    while (b)
    {
        if(b & 1) ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;// used LL because value usd for calculations are in long long because values can exceed the integer range but the main ans is stord in integer so declared as integer
        b = (b >> 1);
    }
    return ans;    
}

int main()
{
    // cout << pow(3, 2.5) << endl;// returnjs double which is not reliable for cp so we use binary exponentiation
    // double d = 1e20;
    // cout << fixed << setprecision(30) << d;
    // and normal loop will give time complexity of O(n) which is too much for this frequently used arithmetic/
    cout << binExpRecurr(2, 10) << endl;
    cout << binExpItr(2, 10) << endl;
    return 0;
}