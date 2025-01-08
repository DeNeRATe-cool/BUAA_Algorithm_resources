#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<deque>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#define maxn 100005
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

const int p = 31;

int pw[maxn], h[maxn];

int calc(int l, int r){
    return (h[r] + mod - 1ll * h[l - 1] * pw[r - l + 1] % mod) % mod;
}

char s[maxn];
char T[maxn];

int l1, l2, m;

void solve(){
    pw[0] = 1;
    for(int i = 1; i < maxn; i++) pw[i] = 1ll * pw[i - 1] * p % mod;
    scanf("%s", s + 1);
    l1 = strlen(s + 1);
    for(int i = 1; i <= l1; i++){
        h[i] = (1ll * h[i - 1] * p + s[i] - 'a' + 1) % mod;
    }
    m = read();
    int ans = 0;
    for(int i = 1; i <= m; i++){
        scanf("%s", T + 1);
        l2 = strlen(T + 1);
        int w = 0;
        for(int j = 1; j <= l2; j++){
            w = (1ll * w * p + T[j] - 'a' + 1) % mod;
        }
        int now = 0;
        for(int j = 1; j + l2 - 1 <= l1; j++){
            if(w == calc(j, j + l2 - 1)) now++;
        }
        ans = max(ans, now);
    }
    printf("%d\n", ans);
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