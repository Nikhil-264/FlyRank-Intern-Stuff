// binary multiplication
// when a <= 10 ^ 18

#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e18 + 7;
// this will help when a and M values are bigger
int binMultiply(long long a, long long b){
    // to calculate a * b to use in calculatin a*a in binary exponentiation
    int ans = 0;
    while (b > 0) {
        if (b & 1){
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

int binExpItr(int a, int b){
    int ans = 1;
    while (b > 0)
    {
        if(b & 1) ans = binMultiply(ans, a);
        a = binMultiply(a, a);
        b = (b >> 1);
    }
    return ans;    
}

int main()
{
    
    return 0;
}