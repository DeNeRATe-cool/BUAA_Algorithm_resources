#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
bool vis[N];
int pre[N];
vector<int> primes;

void init() {
  for (int i = 2; i < N; i++) {
    if (!vis[i]) primes.push_back(i);
    for (auto p : primes) {
      if (1LL * i * p >= N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int pos = 1; // skip 2
    for (int i = 1; i < N; i++) {
        pre[i] = pre[i - 1];
        if (i == primes[pos]) {
            pre[i]++;
            pos++;
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // x + y = p1, x - y = p2
        // x = (p1 + p2) / 2, y = (p1 - p2) / 2
        // 2 * x1 <= p1 + p2 <= 2 * x2
        // 2 * y1 <= p1 - p2 <= 2 * y2
        // x1 + y1 <= p1 <= x2 + y2
        // max(2 * x1 - p1, p1 - 2 * y2) <= p2 <= min(2 * x2 - p1, p1 - 2 * y1)
        long long ans = 0;
        int at = 1;
        while (primes[at] < x1 + y1) {
            at++;
        }
        for ( ; primes[at] <= x2 + y2; at++) {
            int p1 = primes[at];
            int l = max(2 * x1 - p1, p1 - 2 * y2);
            int r = min(2 * x2 - p1, p1 - 2 * y1);
            if (l <= r && 0 <= r) {
                ans += pre[r] - (l - 1 >= 0 ? pre[l - 1] : 0);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}