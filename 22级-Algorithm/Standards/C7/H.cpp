#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

int n, m;
vector<vector<pair<int, long long>>> g;

long long solve(int s, int t) {
    vector<vector<long long>> dis(n, vector<long long>(2, inf));
    vector<vector<bool>> vis(n, vector<bool>(2));
    priority_queue<pair<long long, pair<int, int>>> q;
    dis[s][0] = 0; dis[s][1] = 0;
    q.push({0, {s, 0}});
    q.push({0, {s, 1}});
    while (!q.empty()) {
        int u = q.top().second.first;
        int r = q.top().second.second;
        q.pop();
        if (vis[u][r]) continue;
        vis[u][r] = true;
        for (auto e : g[u]) {
            int v = e.first;
            long long w = e.second;
            if (dis[v][0] > dis[u][r] + w) {
                dis[v][0] = dis[u][r] + w;
                q.push({-dis[v][0], {v, 0}});
            }
            if (!r && dis[v][1] > dis[u][r] + w / 2) {
                dis[v][1] = dis[u][r] + w / 2;
                q.push({-dis[v][1], {v, 1}});
            }
        }
    }
    return min(dis[t][0], dis[t][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        g.clear();
        g.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        long long ans = solve(0, n - 1);
        if (ans == inf) {
            cout << "wow" << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}