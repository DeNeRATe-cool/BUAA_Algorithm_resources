#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define eps 1e-14
#define maxn 1000005
#define ls (tot << 1)
#define rs (tot << 1 | 1)
#define PII pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const double pi = acosl(-1.0L);
const int mod = 998244353;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int ans[maxn], a[maxn];

void solve(){
	int n = read(), c = -read();
	for(int i = 0; i < n; i++) a[i] = read();
	ans[n - 2] = a[n - 1];
	for(int i = n - 3; i >= 0; i--){
		ans[i] = 1ll * ans[i + 1] * c + a[i + 1];
	}
	int r = a[0] + 1ll * ans[0] * c;
	for(int i = 0; i < n - 1; i++) printf("%d ", ans[i]);
	printf("%d\n", r);
}

int main(){
	int t = 1;
	while(t--){
		solve();
	}
	
   return 0;
}
