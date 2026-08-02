#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// SEIVE ALGORRITH FOR FINDING RIME OR NOT
//https://www.youtube.com/watch?v=T8PaMnb0GPo
vector<bool> isPrime(N, 1);


int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if(isPrime[i] == true){
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;
        if(isPrime[num]){
            cout << "Prime" << endl;
        }
        else{
            cout << "Not Prime" << endl;
        }
    }
    
    return 0;
}