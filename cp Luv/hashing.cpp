#include <bits/stdc++.h>
using namespace std;
const int  N = 1e7 + 10;//fibonacci series using N complexity
int a[N];
int main()
{
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i < N; i++)
        a[i] = a[i-1] + a[i-2];
    
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout << a[x] << endl;
    }// it has now the complexity of just O(n) not O(n*q)
    return 0;
}