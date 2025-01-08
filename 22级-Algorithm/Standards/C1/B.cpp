#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 1005
#define MOD 998244353
typedef long long LL;

LL H[MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    H[1] = H[0] = 1;
    for(int i = 2; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) 
            H[i] = (H[i] + (H[j - 1] * H[i - j] % MOD)) % MOD;
    }
    int Q;  cin >> Q;
    while(Q--) {
        int num; cin >> num;
        cout << H[num] % MOD << "\n";
    }
    return 0;
}