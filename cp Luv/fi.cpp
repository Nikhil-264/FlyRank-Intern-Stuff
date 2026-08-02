#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int limit;
        cout << "Enter the limit: ";
        cin >> limit;

        int prev = 1;
        int current = 2;
        int sum = 0;

        while (current <= limit)
        {
            if (current % 2 == 0)
            {
                sum += current;
            }

            int next = prev + current;
            prev = current;
            current = next;
        }

        cout << sum << endl;
    }

    return 0;
}
