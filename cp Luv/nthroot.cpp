#include <bits/stdc++.h>
using namespace std;

double power(double n, int nth){
    double res = 1.0;
    while(nth > 0){
        if(nth & 1){
            res *= n;
        }
        n *= n;
        nth >>= 1;
    }
    return res;
}

double nthRoot(double input, int nth){
    if(input == 0 or input == 1){
        return input;
    }

    double low = 1, high = input;
    double diff = 1e-7;
    // double ans = -1.0;

    while((high - low) > diff){
        double mid = low + (high - low) / 2.0;

        double midPower = power(mid, nth);
        if(midPower == input){
            return mid;
        } else if(midPower < input){
            // ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main()
{
    int n;
    double x;
    cout << "Enter the number : ";
    cin >> x;
    cout << "Enter the nth root : ";
    cin >> n;
    double ans = nthRoot(x, n);
    cout << n << "th root of " << x << " is : " << fixed << setprecision(6) << ans << "\n";
    return 0;
}