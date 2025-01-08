#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

class Dijstra {
   public:
    int n;
    vector<vector<pair<int, long long>>> g;
    vector<long long> dis;
    Dijstra(int _n) : n(_n) {
        g.resize(n);
        dis.resize(n, inf);
    }

    void add(int u, int v, long long w) { g[u].emplace_back(v, w); }

    void solve(int s) {
        vector<bool> vis(n);
        priority_queue<pair<long long, int>> q;
        for (int i = 0; i < n; i++)
            dis[i] = inf;
        dis[s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto e : g[u]) {
                int v = e.first;
                long long w = e.second;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({-dis[v], v});
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> mid(k);
        for (int i = 0; i < k; i++) {
            int u;
            cin >> u;
            mid[i] = --u;
        }
        Dijstra d(n);
        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            --x; --y;
            d.add(x, y, w);
            d.add(y, x, w);
        }
        d.solve(0);
        vector<long long> d1(n);
        for (int i = 0; i < n; i++) {
            d1[i] = d.dis[i];
        }
        d.solve(n - 1);
        long long ans = inf;
        for (int i = 0; i < k; i++) {
            ans = min(ans, d1[mid[i]] + d.dis[mid[i]]);
        }
        cout << (ans < inf ? ans : -1) << '\n';
    }
    return 0;
}