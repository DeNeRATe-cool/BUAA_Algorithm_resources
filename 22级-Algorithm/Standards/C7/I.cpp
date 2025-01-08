#include "bits/stdc++.h"
typedef long long ll;
using namespace std;
#define maxn 10005
int T;

int sgn(ll x){
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}

struct node{
    int x, y;
}p[maxn];

node operator - (node a, node b){
    return {a.x - b.x, a.y - b.y};
}

ll operator * (node a, node b){
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

bool intersect(node a, node b, node x, node y){
    if(sgn((b - a) * (x - a)) * sgn((b - a) * (y - a)) > 0) return false;
    if(sgn((x - y) * (a - y)) * sgn((x - y) * (b - y)) > 0) return false;
    return true;
}


int main () {
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
    p[n + 1] = p[1];
    while(q--){
        node x, y;
        scanf("%d%d", &x.x, &x.y);
        scanf("%d%d", &y.x, &y.y);
        bool f = 0;
        for(int i = 1; i <= n; i++){
            if(intersect(x, y, p[i], p[i + 1])) f = 1;
        }
        puts(f ? "owo" : "qaq");
    }
    return 0;
}

/*
70000
*/