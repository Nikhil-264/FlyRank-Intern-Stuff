#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n--;  // We want to sum numbers less than n
        long long sum = 0;

        auto sumDivisibleBy = [&](int divisor) {
            int terms = n / divisor;
            return (long long)divisor * terms * (terms + 1) / 2;
        };

        sum = sumDivisibleBy(3) + sumDivisibleBy(5) - sumDivisibleBy(15);
        cout << sum << endl;
    }
    return 0;
}
