#include <bits/stdc++.h>

using namespace std;

long long calc(long long x, long long l, long long n, int neg) {
    if (n == 1) {
        return x;
    }
    if (neg) {
        long long a = (x - l % (2 * n - 2) + (n - 2) + (2 * n - 2)) % (2 * n - 2);
        if (a >= n - 2) {
            return a - (n - 2);
        }
        return (n - 2) - a;
    } else {
        long long a = (x + l % (2 * n - 2)) % (2 * n - 2);
        if (a >= n) {
            return 2 * n - 2 - a;
        }
        return a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        queue<array<long long, 3>> q;
        vis[0][0] = true;
        q.push({0, 0, 0});
        long long ans = -1;
        while (!q.empty()) {
            long long r = q.front()[0];
            long long c = q.front()[1];
            long long w = q.front()[2];
            q.pop();
            if (r == n - 1 && c == m - 1) {
                ans = w;
                break;
            }
            int l = a[r][c];
            long long nr, nc;
            nr = calc(r, l, n, 0); nc = c;
            if (!vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc, w + 1});
            }
            nr = calc(r, l, n, 1); nc = c;
            if (!vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc, w + 1});
            }
            nr = r; nc = calc(c, l, m, 0);
            if (!vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc, w + 1});
            }
            nr = r; nc = calc(c, l, m, 1);
            if (!vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push({nr, nc, w + 1});
            }
        }
        cout << ans << '\n';
    }
    return 0;
}