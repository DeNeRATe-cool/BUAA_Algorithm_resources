#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const long long inf = 1e18;

int n, m, k;
int s[N], t[N];

long long sol(int x) {
    vector<long long> dp(N, inf);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = s[i]; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - s[i]] + t[i]);
        }
    }
    return (dp[x] == inf ? -1 : dp[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            cin >> s[i] >> t[i];
        }
        long long t1 = sol(n);
        long long t2 = sol(m);
        if (t1 == -1 || t2 == -1) {
            cout << -1 << '\n';
        } else {
            cout << t1 + t2 << '\n';
        }
    }
    return 0;
}