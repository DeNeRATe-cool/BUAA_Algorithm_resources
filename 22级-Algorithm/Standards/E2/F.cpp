#include<bits/stdc++.h>
using namespace std;

//#define abyss
typedef unsigned int UI;
typedef long long LL;
#define PLL pair<long long, long long>

#define MAXN 200005
priority_queue<PLL, vector<PLL>, greater<PLL> > line, out;
LL ans[MAXN];

int main()
{
#ifdef abyss
    freopen("in2.txt","r",stdin);
    freopen("out2.txt","w",stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) line.push({i, 0});
    while(m--) {
        LL T, W, S; cin >> T >> W >> S;
        while(!out.empty() && out.top().first <= T) {
            line.push({out.top().second, out.top().first});   
            out.pop();
        }
        if(!line.empty()) {
            auto top = line.top();    line.pop();
            ans[top.first] += W;
            out.push({T + S, top.first});
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}