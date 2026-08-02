// constarints :
// 1 <= l <= 10^9
// 1 <= b <= 10^9
// // find area of rectangle in given constraints
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,b;
    cin>>l>>b;
    cout<< l * 1LL * b << endl; //without type casting or choosing data type as long int or without using 1LL it wont give output greater than 10^9
    return 0;
}