#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long fp(long long a, long long x) {
    long long ret = 1;
    while (x) {
        if (x & 1) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        x >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        vector<long long> p(n + 1), q(n + 1);
        for (int i = 0; i <= n; i++) {
            cin >> a[i];
        }
        p[0] = a[0]; q[0] = 1;
        p[1] = (a[0] * a[1] + 1) % mod;
        q[1] = a[1];
        for (int i = 2; i <= n; i++) {
            p[i] = (a[i] * p[i - 1] + p[i - 2]) % mod;
            q[i] = (a[i] * q[i - 1] + q[i - 2]) % mod;
        }
        cout << p[n] * fp(q[n], mod - 2) % mod << '\n';
    }
    return 0;
}