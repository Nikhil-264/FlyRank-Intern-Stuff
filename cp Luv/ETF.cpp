#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

// this is for value of (b > 10 ^ 18)
// ETF method is ised for above cases for very big b

int binExp(int a, int b,int m){
    int ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * 1LL * a) % m;
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}

// a, b such that gcd(a, b) = 1
// ETF = Euler Totient Function
// ETF of N is number of count k such that 1 <= k <= N k and N are coprime
// eg. ETF(6) = 2(only 1 and 5 are coprimes)
// eg. ETF(5) = 4(only 1, 2, 3, 4 are coprimes)

// There is formula for calculating the etf of the number
// ETF(N) = N * PI(1 - 1 / p) whwere p is prime factor of N
// ETF(6) = 6 * (1 - 1 / 2) * (1 - 1 / 3) = 2 if 12 take (1 - 1 / 2) only once as we have to take distinct prime factors

// EULER'S THEOREM
// (a ^ b) % n = (a ^ (b % ETF(n))) % n, n is any number
// if the n if prime then ===> (a ^ b) % n = (a ^(b % (n - 1))) % n
// for question likr a ^ b ^ c we can use the like
// binExp(a,binExp(b, c, M - 1), M) for calculating using Eler thm

int main()
{
    int a = 50, b = 64, c = 32;
    cout << binExp(a,binExp(b, c, M - 1), M) << endl; // only if M is prime
    return 0;
}