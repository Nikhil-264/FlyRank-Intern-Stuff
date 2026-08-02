#include <bits/stdc++.h>
using namespace std;

void increment(int &n, int n3) // forst integer passed by refernce second one passed by value sowe are not returning any value so n3 is not changed in main function
{
    n++;
    n3++;
}
// void swap(int &a, int &b)
// {
//     int temp = a;
//     a= b;
//     b = temp;//by reference
// }
int main()
{
    int n = 3;
    int n3 = 6;
    cout << n << " " << n3 << endl;
    swap(n, n3);// it is a inbuilt function
    cout << n << " " << n3 << endl;// while passing array in function array are always passed by refernec even without using &
}