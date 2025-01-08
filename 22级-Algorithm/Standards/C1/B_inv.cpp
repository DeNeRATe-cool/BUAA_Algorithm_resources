#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 1005
#define MOD 998244353

typedef long long LL;

LL inv(int x) {
    LL b = MOD - 2, base = x, res = 1;
    while(b) {
        if(b&1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

LL H[MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    H[0] = H[1] = 1;
    for(int i = 2; i <= 1000; i++)
        H[i] = (4 * i - 2) * H[i - 1] % MOD * inv(i + 1) % MOD;
    
    int Q; cin >> Q;
    while(Q--) {
        int x; cin >> x;
        cout << H[x] % MOD << "\n";
    }
    return 0;
}