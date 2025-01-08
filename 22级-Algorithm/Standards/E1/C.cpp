#include<bits/stdc++.h> 
#define eps 1e-9
#define maxn 100005
#define ls (tot << 1)
#define rs (tot << 1 | 1)
#define PII pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double pi = acos(-1);
const ll mod = 998244353;
inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int qpow(int a, int b){
    int ans = 1, base = a;
    while(b){
        if(b & 1) ans = 1ll * ans * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return ans;
}

int qpow(int a, int b, int mod){
    int ans = 1, base = a;
    while(b){
        if(b & 1) ans = 1ll * ans * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return ans;
}
//

int n, T;
int tail[maxn], pre[maxn], nxt[maxn];

void solve(){
	n = read(), T = read();
	for(int i = 1; i <= n; i++) tail[i] = i, pre[i] = nxt[i] = 0;
	while(T--){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int x, y;
			scanf("%d%d", &x, &y);
			pre[y] = tail[x], nxt[tail[x]] = y;
			tail[x] = tail[y];
		}else if(op == 2){
			int x;
			scanf("%d", &x);
			printf("%d\n", pre[x]);
		}else{
			int x;
			scanf("%d", &x);
			printf("%d\n", nxt[x]);
		}
	}
}


int main(){
    int t = read();
    while(t--) {
        solve();
    }
    return 0;
}