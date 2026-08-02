#include <bits/stdc++.h>
using namespace std;

struct Element {
    int l, r, u, v;
};

// Check if a valid subsequence of EXACT length m exists
bool check(int m, int n, const vector<Element>& a) {
    // dp[j] = minimum original index i to form a valid prefix of length j for total length m
    vector<int> dp(m + 1, n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, m); j >= 1; j--) {
            // Left rank condition
            if (j >= a[i].l && j <= a[i].r) continue;
            
            // Right rank condition for total length m
            int r_rank = m - j + 1;
            if (r_rank >= a[i].u && r_rank <= a[i].v) continue;

            if (dp[j - 1] < i) {
                dp[j] = min(dp[j], i);
            }
        }
    }

    return dp[m] <= n;
}

void solve() {
    int n;
    cin >> n;
    vector<Element> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].u >> a[i].v;
    }

    // Binary Search / Check from max length down to 0
    int ans = 0;
    for (int m = n; m >= 1; m--) {
        if (check(m, n, a)) {
            ans = m;
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}