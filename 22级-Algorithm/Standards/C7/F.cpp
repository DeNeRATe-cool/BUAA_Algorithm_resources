#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<long long>> dp(n, vector<long long>(m, -inf));
        dp[0][0] = h + a[0][0];
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - 1 >= 0 && dp[i - 1][j] > 0) {
                    if (dp[i - 1][j] - 1 > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1 + a[i][j]);
                    mx = max(mx, i);
                }
                if (j - 1 >= 0 && dp[i][j - 1] > 0) {
                    if (dp[i][j - 1] - 1 > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1 + a[i][j]);
                    mx = max(mx, i);
                }
            }
        }
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (dp[n - 1][j] > 0) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << '\n';
        } else {
            cout << mx + 1 << '\n';
        }
    }
    return 0;
}