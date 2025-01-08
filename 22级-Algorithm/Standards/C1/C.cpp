#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 30004
#define MOD 10007
typedef long long LL;

int a_sum, b_sum;
LL A[MAXN], B[MAXN];

LL cal(LL base, LL *arr, int len) {
    LL res = 0;
    for(int i = len; i >= 0; i--)   res = (res * base + arr[i]) % MOD;
    return res; 
}

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> a_sum;
    for(int i = 0; i <= a_sum; i++) cin >> A[i];
    cin >> b_sum;
    for(int i = 0; i <= b_sum; i++) cin >> B[i];
    int Q; cin >> Q;
    while(Q--) {
        LL x, y;   cin >> x >> y;
        LL ansX = cal(x, A, a_sum), ansY = cal(y, B, b_sum);
        cout << (ansX * ansY) % MOD << "\n";
    }
    return 0;
}