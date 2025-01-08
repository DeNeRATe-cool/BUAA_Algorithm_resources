#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 2003
#define MAXM 6003
#define MAX 1000000000

int n, m; 
struct edge{
    int from, to, val;
}e[MAXM * 2];
int dis[MAXN];

bool Bellman_Ford(int s) {
    fill(dis, dis + n + 1, 2 * MAX);
    dis[s] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
                dis[e[j].to] = min(dis[e[j].to], dis[e[j].from] + e[j].val);
    
    for(int i = 1; i <= m; i++)
            if(dis[e[i].to] > dis[e[i].from] + e[i].val)
                return true;
    return false;
}

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt;
    while(tt--) {
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
            cin >> e[i].from >> e[i].to >> e[i].val;
        bool res = Bellman_Ford(1);
        if(res) cout << "boo how\n";
        else {
            for(int i = 1; i <= n; i++)
                cout << (dis[i] >= MAX ? MAX : dis[i]) << " \n"[i == n];
        }
    }
    return 0;
}