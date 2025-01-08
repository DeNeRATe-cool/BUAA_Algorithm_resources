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
int app[30][30];
int cnt;
char s[5];

void solve(){
    n = read();
    for(int i = 1; i <= n; i++){
        scanf("%s", s + 1);
        app[s[1] - 'a'][s[2] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(app[i][j]) p[++cnt] = app[i][j];
        }
    }
    n = cnt;
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i];
    for(int i = 1; i <= n; i++) dp[i][i] = p[i];
    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            dp[l][r] = 1e18;
            for(int k = l; k <= r; k++){
                dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    printf("%lld\n", dp[1][n]);
}


int main() {
	// freopen("4.in", "r", stdin);
	// freopen("4.out", "w", stdout);
    int t;
    t = 1;
    while(t--){
        solve();
        // puts(solve() ? "Yes" : "No");
    }
    return 0;
}