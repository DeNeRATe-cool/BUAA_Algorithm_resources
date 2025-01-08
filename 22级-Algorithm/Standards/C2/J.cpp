#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 1;
const int mod = 998244353;

long long f[N], s[N];

void init() {
    f[0] = 1;
    s[0] = 1;
    for (int n = 1; n < N; n++) {
        for (int i = 0; i <= n - 1; i++) {
            f[n] += f[i] * s[n - i - 1];
            f[n] %= mod;
        }
        for (int i = 0; i <= n; i++) {
            s[n] += f[i] * f[n - i];
            s[n] %= mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }
    return 0;
}