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
        vector<int> s(n), t(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i] >> t[i];
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int u, int v) {
            return s[u] + t[u] < s[v] + t[v] ||
                   (s[u] + t[u] == s[v] + t[v] && s[u] < s[v]);
        });
        int lst = -1;
        int ans = 0;
        for (auto i : p) {
            if (s[i] >= lst) {
                ans++;
                lst = s[i] + t[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}