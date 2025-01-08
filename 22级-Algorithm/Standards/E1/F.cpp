#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<bool> vis(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                continue;
            }
            int cur = i;
            int cnt = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                cnt++;
                cur = a[cur];
            }
            ans += cnt - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}