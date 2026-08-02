#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int *ptr = upper_bound(a, a + n, 5);  // upper bound function will return the the pointer with the element structly greta er than th element we passed in as third argument
    int *ptr2 = lower_bound(a, a + n, 5); // it will return pointer to the greter than or equal to the guven argument if not then it will return the ointer to the next to last element
    if (ptr == a + n)
    {
        cout << " skdjche" << endl;
    }
    cout << *ptr << endl; // will give 7 as output
    if (ptr2 == a + n)
    {
        cout << " skdjche" << endl;
    }
    cout << *ptr2 << endl; // will gve 5
    // if (ptr == a + n)
    // {
    //     cout << " skdjche" << endl;
    // }
    // cout << *ptr << endl;

    return 0;
}