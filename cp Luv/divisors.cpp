// finding the divisors in sqrt(n) approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // MY CODE
    // unordered_set<int> s;
    // for (int i = 1; i <= sqrt(n); ++i) {
    //     if (n % i == 0) {
    //         s.insert(i);
    //         s.insert(n / i);
    //     }
    // }
    // int sum  = 0;
    // for (auto i = s.begin(); i != s.end(); i++)
    // {
    //     cout << *i << " ";
    //     sum += *i;
    // }
    // cout << endl << sum << " " << s.size() << endl;
    // LUV SIR CODE sqrt(N) approach
    // int ct = 0; 
    // int sum = 0;
    // for (int i = 1; i * i <= n; i++)
    // {
    //     if(n % i == 0){
    //         cout << i << " " << n / i << endl;
    //         ct += 1;
    //         sum += i;
    //         if(n / i != i){
    //             sum += n / i;
    //             ct += 1;
    //         }
    //     }
    // }
    // cout << ct << " " << sum << endl;

    // prime factorization
    vector<int> prime_factors;
    for (int i = 2; i * i <= n; i++)
    {
        while(n % i == 0){
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1){
        prime_factors.push_back(n);
    }
    for (auto &&prime : prime_factors)
    {
        cout << prime << " ";
    }
    
     


    

    return 0;
}