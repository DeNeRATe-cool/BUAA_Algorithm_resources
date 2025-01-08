#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e18;

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
    int n, m, s;
    long long t;
    cin >> n >> m >> s >> t;
    --s;
    Dijstra d(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        d.add(x, y, w);
        d.add(y, x, w);
    }
    d.solve(s);
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (d.dis[i] > t) {
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt << '\n';
    for (auto i : ans) {
        cout << i + 1 << ' ' << (d.dis[i] == inf ? -1 : d.dis[i]) << '\n';
    }
    return 0;
}