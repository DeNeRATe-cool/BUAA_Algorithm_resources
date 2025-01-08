#include <bits/stdc++.h>

using namespace std;

class fenwick {
  public:
    int n;
    vector<int> a;
    fenwick(int _n) : n(_n) { a.resize(n); }
    void modify(int x, int val) {
        while (x < n) {
            a[x] += val;
            x |= (x + 1);
        }
    }
    int get(int x) {
        int ret = 0;
        while (x >= 0) {
            ret += a[x];
            x = (x & (x + 1)) - 1;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        set<pair<int, int>> st;
        int n;
        cin >> n;
        vector<int> x(n), y(n), sy(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            st.insert({x[i], y[i]});
            sy[i] = y[i];
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int u, int v) {
            return (x[u] > x[v]) || (x[u] == x[v] && y[u] < y[v]);
        });
        sort(sy.begin(), sy.end());
        map<int, int> sp;
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (sp.find(sy[i]) == sp.end()) {
                sp[sy[i]] = id++;
            }
        }
        fenwick tr = fenwick(n);
        vector<bool> vis(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int a = sp[y[p[i]]];
            if (!vis[a]) {
                tr.modify(a, 1);
                vis[a] = true;
            }
            if (i == n - 1 || x[p[i]] > x[p[i + 1]]) {
                ans += tr.get(a);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}