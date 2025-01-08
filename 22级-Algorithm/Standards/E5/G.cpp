#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long p2[63];

long long fp(long long a, long long x) {
    long long ret = 1;
    while (x) {
        if (x & 1) ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}

long long f(long long x) {
    if (x <= 1)
        return x;
    if (x == 2)
        return 0;
    int d = 0;
    while ((x >> d) > 0) d++;
    d--;
    if ((x >> (d - 1)) & 1) {
        return (fp(2, p2[d - 1] + max(d - 3, -1) + (x - p2[d] - p2[d - 1])) + f(x - p2[d - 1])) % mod;
    }
    return f(x - p2[d - 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    p2[0] = 1;
    for (int i = 1; i < 63; i++)
        p2[i] = p2[i - 1] * 2;
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        cout << f(n) << '\n';
    }
    return 0;
}