#include <bits/stdc++.h>
#define get(l, r) ((l) <= (r) ? (dp[l][r]) : (0))

using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> dp(n, vector<int>(n, inf));
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                int j = i + l - 1;
                if (j >= n) {
                    break;
                }
                if (s[i] == s[j]) {
                    dp[i][j] = min(dp[i][j], get(i + 1, j - 1));
                } else {
                    dp[i][j] = min(dp[i][j], min(get(i + 1, j), get(i, j - 1)) + 1);
                }
            }
        }
        cout << dp[0][n - 1] + n << '\n';
    }
    return 0;
}