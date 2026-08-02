// Bit manipulation
// we can take and of number with 1 to identify that the number is even of odd
#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << endl;
}

int main()
{
    // for (int i = 0; i < 8; i++)
    // {
    //     printBinary(i);
    //     if(i & 1) cout << "EVEN" << endl;
    //     else cout << "ODD" << endl;
    // }
    // // modulo and division are slower than bit manipulation so we can use bit
    // // to divide the number by 2 we can do
    // // works for operation on integers 
    // int n = 5;
    // cout << (n >> 1) << endl;// divides by 2
    // cout << (n << 1) << endl;// multiplies by 2

    // Changing the upper to lower case of characters
    for (char c = 'A'; c <= 'E'; c++)
    {
        cout << c << endl;
        printBinary(int(c));
    }
    for (char c = 'a'; c <= 'e'; c++)
    {
        cout << c << endl;
        printBinary(int(c));
    }
    // we can se that the 5th bit is set for lowr case and unset for upper case we can use this property

    char A = 'A';
    char a = A | (1 << 5); // for upper to lower 5 bit id made set 
    cout << a << endl;
    cout << char((a & ~(1 << 5))) << endl; // for lower to upper 5 th bit is made unset
    
    cout << char(1 << 5) << endl; // (1 << 5) is ascii value for space character
    // UPPER TO LOWER
    cout << char('C' | ' ') << endl; // we can use or operator to make upper to lower with space
    // as we want to make lower to upper so we need to set the 5th bit we will be needing the number like 00001011111 which is ascii code for '_'.
    // LOWER TO UPPER
    cout << char('c' & '_') << endl;

    
    return 0;
}