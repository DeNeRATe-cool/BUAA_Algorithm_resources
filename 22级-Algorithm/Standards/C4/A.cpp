#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 1003
typedef long long LL;

struct node {
    int w, v;
    bool operator < (const node &rhs) const {
        return (LL)v * rhs.w > (LL)rhs.v * w;
    }
}nd[MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;   scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d%d", &nd[i].v, &nd[i].w);
    sort(nd + 1, nd + 1 + n);
    double res = 0;
    for(int i = 1; i <= n; i++) {
        if(k >= nd[i].w) {
            res += nd[i].v;
            k -= nd[i].w;
        }
        else {
            res += 1.0 * k * nd[i].v / nd[i].w;
            break;
        }
    }
    printf("%.3f\n", res);
    return 0;
}