// swapping 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Some xor properties 
    // a ^ a = 0
    // a ^ 0 = a
    // a ^ b ^ c = a ^ c ^ b
    // int a = 4, b = 5;
    // a = a ^ b; 
    // b = a ^ b; // we changed a in previous step b = (a ^ b) ^ b so b ^ b = 0 and a ^ 0 = a so b == a at the end
    // a = a ^ b; // as same (a ^ b) ^ a // represented in updated values of each so a ^ a gets cancelled so we get a = b;
    // cout << a << " " << b << endl;

    // FIND THE INTEGER WITH ODD COUNT USING XOR
    // time complexity = O(N);
    // space complexity = O(1); // if we use stl it will take O(N) space complexity and will take more space we can use xor like this 
    int n;
    cin >> n;
    vector<int> a(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        k = k ^ a[i];// as the number that is appearing even times will get cancelled due xor operator so only number which will left if the number that appeared odd number of times
    }
    cout << k << endl;
    
    
    return 0;
}