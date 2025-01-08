#include <bits/stdc++.h>

using namespace std;

class dsu {
   public:
    int n;
    vector<int> p;
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    inline int find(int x) { return (x == p[x] ? x : (p[x] = find(p[x]))); }
    inline bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> e(m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            e[i] = {u, v, w};
        }
        vector<int> p(m);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int u, int v) {
            return e[u][2] < e[v][2];
        });
        dsu d = dsu(n);
        long long ans = 0;
        for (int i : p) {
            int u = e[i][0], v = e[i][1];
            if (d.unite(u, v)) {
                ans += e[i][2];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}