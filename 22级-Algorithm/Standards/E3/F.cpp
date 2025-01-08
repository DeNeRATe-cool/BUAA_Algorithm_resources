#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, h;
        cin >> n >> k >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> f(k + 1, h), g(k + 1);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0) {
                s += a[i];
                continue;
            }
            for (int j = 0; j <= k; j++) {
                if (f[j] > 0) {
                    f[j] += s;
                }
            }
            s = 0;
            for (int j = 0; j <= k; j++) {
                g[j] = max(f[j] > -a[i] ? f[j] : f[j] / 2,
                           j + 1 <= k ? f[j + 1] : 0);
            }
            swap(f, g);
        }
        long long ans = *max_element(f.begin(), f.end());
        if (ans <= 0) {
            cout << -1 << '\n';
        } else {
            cout << ans + s << '\n';
        }
    }
    return 0;
}