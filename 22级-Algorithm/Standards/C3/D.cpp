#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<deque>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#define maxn 200005
typedef long long ll;
const double eps = 1e-9;
const int mod = 998244353;

using namespace std;

ll read(){
	ll x = 0, f = 1;char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
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

int n, p[maxn];
ll f[maxn];
vector<int> ans;

void solve(){
	n = read();
	for(int i = 1; i <= n; i++) p[i] = read();
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			f[i] = max(f[i], f[j] + p[i - j]);
		}
	}
	ll mx = f[n];
	for(int i = 1; i <= n; i++) f[i] = 1e18;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			f[i] = min(f[i], f[j] + p[i - j]);
		}
	}
	printf("%lld\n", mx - f[n]);
}


int main() {
	// freopen("5.in", "r", stdin);
	// freopen("5.ans", "w", stdout);
    int t;
    t = 1;
    while(t--){
        solve();
        // puts(solve() ? "Yes" : "No");
    }
    return 0;
}