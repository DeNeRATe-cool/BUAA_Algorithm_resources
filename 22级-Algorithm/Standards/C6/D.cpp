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

char s[300005];

void solve(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int now = 1;
        for(int j = 1; j < i && i + j <= n; j++){
            if(s[i - j] != s[i + j]) break;
            now += 2;
        }
        ans = max(ans, now);
    }
    for(int i = 1; i < n; i++){
        int now = 0;
        for(int j = 0; j < i && i + j + 1 <= n; j++){
            if(s[i - j] != s[i + j + 1]) break;
            now += 2;
        }
        ans = max(ans, now);
    }
    printf("%d\n", ans);
}


int main() {
    int t;
    t = read();
    while(t--){
        solve();
    }
    return 0;
}