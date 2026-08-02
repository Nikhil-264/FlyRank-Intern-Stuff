#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{
    printBinary(9);
    int a = 9;
    int i = 3;
    if ((a & (1 << i)) != 0)
        cout << "Set bit" << endl;
    else
        cout << "Unset bit" << endl;
    i = 1;
    // If we want to mak the ith bit set we can use or "|";
    printBinary(a | (1 << i));
    // To unset the bit let we want to unset the 3rd bit of a = 9;
    // We will use the number which has i th number 0 and ither bits set and use or in the operation
    // we have to invert the number with ith bit set

    printBinary(~a);
    printBinary((~(1<<3)) & a);// we unset the third bit
    // Formula
    // // Making the i th bit unset in the number
    // printBinary(a & (~(1 << i)));
    // // Making the i th bit set in the number
    // printBinary(a | (1 << i));

    // Toggle bit if set make it unset and viceversa
    i = 2;
    printBinary(a ^ (1 << i));
    int ct = 0;
    // Bit count = count of set counts
    for (int i = 31; i >= 0; i--) {
        if((13 & (1 << i)) != 0)ct++;
    }
    cout << ct << endl;
    
    // inbuilt function for bit count
    cout << __builtin_popcount(a) << endl;// works only for integers
    // for long long we can use
    cout << __builtin_popcountll((1LL<<35) - 1) << endl;
    cout << (1LL<<35) - 1 << endl;

    return 0;
}
// Set bit means its 1 and unset bit means its 0;
// Above code will print binary representation of the number and tell the i th bit that thats set or not
