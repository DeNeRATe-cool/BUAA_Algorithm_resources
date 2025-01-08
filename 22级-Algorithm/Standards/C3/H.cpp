#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<deque>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#define maxn 505
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

int n, m, p[maxn], root;
ll dp[maxn][maxn], sum[maxn];
int rt[maxn][maxn];
int ch[maxn][2];

int dfs(int l, int r){
    if(l > r) return -1;
    int mid = rt[l][r];
    ch[mid][0] = dfs(l, mid - 1);
    ch[mid][1] = dfs(mid + 1, r);
    return mid;
}

void solve(){
    n = read();
    for(int i = 1; i <= n; i++) p[i] = read(), sum[i] = sum[i - 1] + p[i];
    for(int i = 1; i <= n; i++) dp[i][i] = p[i], ch[i][0] = ch[i][1] = -1, rt[i][i] = i;
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            dp[l][r] = 1e18;
            for(int k = l; k <= r; k++){
                dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }
            for(int k = l; k <= r; k++){
                if(dp[l][r] == dp[l][k - 1] + dp[k + 1][r] + sum[r] - sum[l - 1]) rt[l][r] = k;
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    dfs(1, n);
    for(int i = 1; i <= n; i++){
        printf("%d %d\n", ch[i][0], ch[i][1]);
    }
}


int main() {
	// freopen("5.in", "r", stdin);
	// freopen("5.out", "w", stdout);
    int t;
    t = 1;
    while(t--){
        solve();
        // puts(solve() ? "Yes" : "No");
    }
    return 0;
}