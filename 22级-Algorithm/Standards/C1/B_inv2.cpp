#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 2005
#define MOD 998244353
typedef long long LL;

LL fac[MAXN], ifac[MAXN];

LL fpm(LL a, LL b = MOD - 2) {
    LL ans = 1;
    for(; b; b >>= 1, a = a * a % MOD)
        if(b & 1) ans = ans * a % MOD;
    return ans;
}

void init(int n = 2002) {
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = (fac[i - 1] * i) % MOD;
    ifac[n] = fpm(fac[n]);
    for(int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i % MOD;
}

inline LL inv(int x) {return ifac[x] * fac[x - 1] % MOD;}
inline LL C(int n, int m) {return fac[m] * ifac[n] % MOD * ifac[m - n] % MOD;}

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init();
    int Q;  cin >> Q;
    while(Q--) {
        int x;  cin >> x;   
        cout << C(x, 2 * x) * inv(x + 1) % MOD << "\n";
    }
    return 0;
}