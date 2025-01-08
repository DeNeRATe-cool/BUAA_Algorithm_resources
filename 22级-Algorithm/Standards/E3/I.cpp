#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n * m + 2 * (n + m));
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                int id = i * m + j;
                int r = n * m + 2 * i + a[i][j];
                g[id].emplace_back(r);
                g[r].emplace_back(id);
            }
        }
        for (int j = 0; j < m; j++) {
            int c = n * m + 2 * n + 2 * j;
            for (int i = 0; i < n; i++) {
                int id = i * m + j;
                g[id].emplace_back(c + (a[i][j] ^ 1));
                g[c + a[i][j]].emplace_back(id);
            }
        }
        vector<int> vis(n * m + 2 * (n + m));
        queue<pair<int, int>> q;
        vector<int> lst(n * m + 2 * (n + m));
        q.push({0, 0});
        vis[0] = true;
        lst[0] = -1;
        int cur;
        int ans = -1;
        while (!q.empty()) {
            auto hd = q.front(); q.pop();
            int s = hd.first, w = hd.second;
            if (s == n * m - 1) {
                ans = w;
                cur = s;
                break;
            }
            for (auto t : g[s]) {
                if (!vis[t]) {
                    q.push({t, w + 1});
                    vis[t] = true;
                    lst[t] = s;
                }
            }
        }
        while (cur != -1) {
            if (cur < n * m) {
                cout << cur / m << ' ' << cur % m << '\n';
            }
            cur = lst[cur];
        }
        cout << (ans < 0 ? ans : ans / 2) << '\n';
    }
    return 0;
}