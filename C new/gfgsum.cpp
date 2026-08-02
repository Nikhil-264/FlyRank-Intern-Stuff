#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    cout << "Enter the members of array: " << endl;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << " = ";
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[j] < i + 1)
            {
                sum += array[j];
            }
        }
        cout << sum << " ";
    }

    return 0;
}
