

const long long inf = 1e18;
const int M = 1e5 + 5;

int p[3][M], t[3][3];
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
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < 3; i++) {
                dp[i][j] = inf;
                for (int k = 0; k < 3; k++) {
                    dp[i][j] = min(
                        dp[i][j],
                        (j - 1 >= 0 ? dp[k][j - 1] + t[k][i] : 0LL) + p[i][j]
                    );
                }
            }
        }
        long long ans = inf;
        for (int i = 0; i < 3; i++) {
            ans = min(ans, dp[i][m - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}