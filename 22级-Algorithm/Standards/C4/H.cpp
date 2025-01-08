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
        vector<vector<int>> g(n);
        vector<int> in(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].emplace_back(v);
            in[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        bool ok = true;
        while (!q.empty()) {
            if (q.size() != 1) {
                ok = false;
                break;
            }
            int s = q.front();
            q.pop();
            for (auto t : g[s]) {
                if (--in[t] == 0) {
                    q.push(t);
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}