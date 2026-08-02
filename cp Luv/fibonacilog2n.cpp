//Fibonacci series getting nth member 
// time complexity O(logn)

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> result(2, vector<int>(2));

    result[0][0] = (int)(((long long)a[0][0] * b[0][0] + (long long)a[0][1] * b[1][0]) % MOD);
    result[0][1] = (int)(((long long)a[0][0] * b[0][1] + (long long)a[0][1] * b[1][1]) % MOD);
    result[1][0] = (int)(((long long)a[1][0] * b[0][0] + (long long)a[1][1] * b[1][0]) % MOD);
    result[1][1] = (int)(((long long)a[1][0] * b[0][1] + (long long)a[1][1] * b[1][1]) % MOD);

    return result;
}

int fibonacciNumber(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;

    vector<vector<int>> base = {{1, 1}, {1, 0}};
    vector<vector<int>> result = {{1, 0}, {0, 1}};

    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        n /= 2;
    }

    return result[0][1];
}

int main()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cout << fibonacciNumber(i) << endl;
    }
       
    return 0;
}