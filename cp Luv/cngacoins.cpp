// Coding ninjas
// greedy algorithms fro ninjas and The coins
#include <bits/stdc++.h>
using namespace std;
int minimumCoins(int v)
{
    // Write your code here.
    int final_coins = 0;
    while (v >= 1000)
    {
        v -= 1000;
        final_coins++;
    }
    while (v >= 500)
    {
        v -= 500;
        final_coins++;
    }
    while (v >= 100)
    {
        v -= 100;
        final_coins++;
    }
    while (v >= 50)
    {
        v -= 50;
        final_coins++;
    }
    while (v >= 20)
    {
        v -= 20;
        final_coins++;
    }
    while (v >= 10)
    {
        v -= 10;
        final_coins++;
    }
    while (v >= 5)
    {
        v -= 5;
        final_coins++;
    }
    while (v >= 2)
    {
        v -= 2;
        final_coins++;
    }
    while (v >= 1)
    {
        v -= 1;
        final_coins++;
    }
    return final_coins;
}

int main()
{
    int V;
    cin >> V;
    cout << "Minimum number of coins required is: " << minimumCoins(V) << endl;
    return 0;
}