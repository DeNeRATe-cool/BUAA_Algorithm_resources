#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<deque>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#define maxn 305
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

int n, a[maxn];
ll f[maxn][maxn];

void solve(){
	n = read();
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n + 1; i++) a[i] = read(), f[i][i] = 0;

    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            for(int k = l; k < r; k++){
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + 1ll * a[l] * a[k + 1] * a[r + 1]);
            }
        }
    }
    ll mx = f[1][n];
    memset(f, 0, sizeof(f));
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            for(int k = l; k < r; k++){
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + 1ll * a[l] * a[k + 1] * a[r + 1]);
            }
        }
    }
    printf("%.4f\n", 1.0 * f[1][n] / mx);
}


int main() {
	freopen("1.in", "r", stdin);
	freopen("1.ans", "w", stdout);
    int t;
    t = 1;
    while(t--){
        solve();
        // puts(solve() ? "Yes" : "No");
    }
    return 0;
}