#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

class Floyd {
  public:
    int n;
    vector<vector<long long>> g;
    Floyd(int _n) : n(_n) {
        g.resize(n);
        for (int i = 0; i < n; i++) g[i].resize(n, inf);
        for (int i = 0; i < n; i++) g[i][i] = 0;
    }
    void add(int u, int v, long long w) { g[u][v] = min(g[u][v], w); }
    void solve() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    Floyd f = Floyd(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        f.add(u, v, w);
    }
    f.solve();
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        long long ans = f.g[u][v];
        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}