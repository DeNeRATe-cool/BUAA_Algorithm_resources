#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int M = 1e5 + 5;

int p[3][M], t[3][3];
int nxt[3][M], path[M];
long long dp[3][M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int m;
        cin >> m;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < m; j++) {
                cin >> p[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> t[i][j];
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < 3; i++) {
                dp[i][j] = inf;
                for (int k = 0; k < 3; k++) {
                    long long a = (j + 1 < m ? dp[k][j + 1] + t[i][k] : 0LL) +
                                    p[i][j];
                    if (a < dp[i][j]) {
                        dp[i][j] = a;
                        nxt[i][j] = k;
                    }
                }
            }
        }
        long long ans = inf;
        int cur = 0;
        for (int i = 0; i < 3; i++) {
            if (dp[i][0] < ans) {
                ans = dp[i][0];
                cur = i;
            }
        }
        for (int i = 0; i < m; i++) {
            path[i] = cur;
            cur = nxt[cur][i];
        }
        cout << ans << '\n';
        for (int i = 0; i < m; i++) {
            cout << "Station" << i + 1 << ": Line" << path[i] + 1 << '\n';
        }
    }
    return 0;
}