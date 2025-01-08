#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 200005
#define PII pair<int, int>
#define MK(a, b) make_pair(a, b) 

vector<PII> G[MAXN];
int ans[MAXN];

void Dijkstra() {
    memset(ans, 0x3f, sizeof(ans));
    ans[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push(MK(0, 1));
    while(!pq.empty()) {
        int val = pq.top().first, u = pq.top().second;
        pq.pop();
        if(val != ans[u]) continue;
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first, w = G[u][i].second;
            int res = max(val, w);
            if(res < ans[v]) {
                ans[v] = res;
                pq.push(MK(ans[v], v));
            }
        }
    }
}

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v , w; cin >> u >> v >> w;
        G[u].emplace_back(MK(v, w));
        G[v].emplace_back(MK(u, w));    
    }
    Dijkstra();
    for(int i = 2; i <= n; i++)
        cout << (ans[i] == ans[0] ? -1 : ans[i]) << "\n";
    return 0;
}