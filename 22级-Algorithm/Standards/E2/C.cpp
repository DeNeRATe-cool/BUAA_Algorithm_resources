#include<bits/stdc++.h>
using namespace std;

//#define abyss
typedef long long LL;
#define MAXN 200005
#define PII pair<int, int>

LL x[MAXN], y[MAXN];
bool vis[MAXN];
vector<PII> G[MAXN];
struct nd {
    int p1, p2, _X, _Y;
} node[MAXN];

void DFS(int root) {
    for(auto u : G[root]) {
        int v = u.first, id = u.second;
        if(vis[v]) continue;
        x[v] = x[root] + node[id]._X * (v == node[id].p2 ? 1 : -1);
        y[v] = y[root] + node[id]._Y * (v == node[id].p2 ? 1 : -1);
        vis[v] = true;  DFS(v);
    }
}

int main()
{
#ifdef abyss
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int N, M; cin >> N >> M;
    vis[1] = true;
    for(int k = 1; k <= M; k++) {
        cin >> node[k].p1 >> node[k].p2 >> node[k]._X >> node[k]._Y;
        G[node[k].p1].push_back({node[k].p2, k});
        G[node[k].p2].push_back({node[k].p1, k});
    }
    DFS(1);
    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {cout << "undecidable\n"; continue;}
        cout << x[i] << " " << y[i] << "\n";
    }
    return 0;
}
