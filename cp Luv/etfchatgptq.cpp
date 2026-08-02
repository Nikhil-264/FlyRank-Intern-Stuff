// take input from user and return the sum of etf coefficint from 1 to n
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

set<int> primeFactorization(int n) {
    set<int> factors;

    while (n % 2 == 0) {
        factors.insert(2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            factors.insert(i);
            n = n / i;
        }
    }

    if (n > 2) {
        factors.insert(n);
    }

    return factors;
}

int totientSum(int n){
    for (int i = 1; i <= n; i++)
    {
        set<int> factors = primeFactorization(i);
        
    }
    
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> ans = primeFactorization(n);

    }
    return 0;
}