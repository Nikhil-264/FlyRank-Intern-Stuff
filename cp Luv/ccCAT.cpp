#include <bits/stdc++.h>
using namespace std;

// Function to check if a triangle of height h can be formed with n gold coins
bool canFormTriangle(int n, int h) {
    // Calculate the total number of coins required for a triangle of height h
    int totalCoins = (h * (h + 1)) / 2;

    return n >= totalCoins;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Initialize binary search parameters
        int left = 1;         // Minimum possible height
        int right = n;        // Maximum possible height
        int maxHeight = 0;    // Maximum height found so far

        // Perform binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFormTriangle(n, mid)) {
                maxHeight = mid;
                left = mid + 1; // Try a higher height
            } else {
                right = mid - 1; // Try a lower height
            }
        }

        cout << maxHeight << endl;
    }
    return 0;
}
