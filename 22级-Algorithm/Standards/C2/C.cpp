#include <bits/stdc++.h>

using namespace std;

const int N = 100003;

int nextRand() {
    static unsigned int rnd_num = 0x80000001;
    static int mod = 1e5 + 3;

    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    assert(rnd_num != 0);
    return rnd_num % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(N);
        for (int i = 0; i < n; i++) {
            a[nextRand()]++;
        }
        long long ans = 0;
        int ord = 1;
        for (int i = 0; i < N; i++) {
            ans += (long long) i * ord * a[i];
            ord += a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}