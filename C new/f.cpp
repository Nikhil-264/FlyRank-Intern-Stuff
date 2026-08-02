#include <iostream>
using namespace std;

int dominantpair()
{
    int n, count = 0;
start:
    cout << "Enter the even number of elements in array: ";
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "Try again\nYou may have entered wrong input\n";
        goto start;
    }
    int array[n];
    cout << "Enter the elements of array\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << " : ";
        cin >> array[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = n / 2; j < n; j++)
        {
            if (array[i] >= 5 * array[j])
            {
                count++;
            }
        }
    }
    cout << "The number of dominant pairs in array: " << count << endl;
    return 0;
}

int main()
{
    dominantpair();
    return 0;
}
