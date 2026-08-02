#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    long long sqrt(long long x)
    {
        if (x == 0 || x == 1)
            return x;
        else
        {
            long long low = 0, mid, high = x;
            while (low <= high)
            {
                mid = low + (high - low) / 2;
                if (mid * mid == x)
                    return mid;
                else if (mid * mid > x)
                {
                    high = mid;
                }
                else if (mid * mid < x && (long long)(mid + 1) * (mid + 1) > x)
                {
                    return mid;
                }
                else if (mid * mid < x)
                {
                    low = mid;
                }
            }
            return -1;
        }
    }
};

int main()
{
    long long n;
    cout << "Enter a number : ";
    cin >> n;
    solution obj;
    cout << "SquareRoot of the number is : " << obj.sqrt(n) << endl;

    return 0;
}