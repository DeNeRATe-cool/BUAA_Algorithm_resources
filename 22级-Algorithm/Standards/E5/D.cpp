#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cassert>

using namespace std;

const int N = 5e3 + 5, M = 1e6 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m, tot = 1, lnk[N], cur[N], ter[M], nxt[M];
long long cap[M], cost[M], dis[N], ret;
bool vis[N];

void add(int u, int v, long long w, long long c) {
  assert(0 < u && u < 5000);
  ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
}

void ae(int u, int v, long long w, long long c) { add(u, v, w, c), add(v, u, 0, -c); }

bool spfa(int s, int t) {
  memset(dis, 0x3f, sizeof(dis));
  memcpy(cur, lnk, sizeof(lnk));
  std::queue<int> q;
  q.push(s), dis[s] = 0, vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = lnk[u]; i; i = nxt[i]) {
      int v = ter[i];
      if (cap[i] && dis[v] > dis[u] + cost[i]) {
        dis[v] = dis[u] + cost[i];
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != INF;
}

long long dfs(int u, int t, long long flow) {
  if (u == t) return flow;
  vis[u] = 1;
  long long ans = 0;
  for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
    int v = ter[i];
    if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
      long long x = dfs(v, t, std::min(cap[i], flow - ans));
      if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
    }
  }
  vis[u] = 0;
  return ans;
}

long long mcmf(int s, int t) {
  long long ans = 0;
  while (spfa(s, t)) {
    long long x;
    while ((x = dfs(s, t, INF))) ans += x;
  }
  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        memset(lnk, 0, sizeof(lnk));
        memset(vis, 0, sizeof(vis));
        tot = 1;
        ret = 0;
        std::vector<std::pair<long long, long long>> p(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = n + 1; j <= 2 * n; j++) {
                ae(i, j, 1, abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second));
            }
        }
        for (int i = 1; i <= n; i++) {
            ae(2 * n + 1, i, 1, 0);
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            ae(i, 2 * n + 2, 1, 0);
        }
        mcmf(2 * n + 1, 2 * n + 2);
        cout << ret << '\n';
    }
  return 0;
}