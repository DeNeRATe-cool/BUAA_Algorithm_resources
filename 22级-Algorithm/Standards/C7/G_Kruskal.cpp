#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200005;
const int MAXM = 500005;
struct Edge{
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
}edge[MAXM];

int fa[MAXN], ans[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];

int getF(int u) {
    if(fa[u] != u) fa[u] = getF(fa[u]);
    return fa[u];
}

void BFS(int s, int w) {
    queue<int> q;   q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = true;  ans[u] = w;
        for(auto v : G[u]) if(!vis[v]) q.push(v);
    }
}

#define abyss
int main()
{
#ifdef abyss
    freopen("in6.txt", "r", stdin);
    freopen("out6.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, end = 0;   cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
    sort(edge + 1, edge + 1 + m);
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        int uf = getF(u), vf = getF(v);
        if(uf == vf) continue;
        if(uf == 1) {BFS(v, w); fa[vf] = 1;}
        else if(vf == 1) {BFS(u, w); fa[uf] = 1;}
        else {fa[uf] = vf; G[u].emplace_back(v); G[v].emplace_back(u);}
        if(++end == n - 1) break;
    }
    for(int i = 2; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}