#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 4e5 + 5;

vector<long long> seg1(N), tag1(N);
vector<long long> seg2(N), tag2(N);

void pushdown(int l, int r, int id, vector<long long> &seg,
              vector<long long> &tag) {
    int m = l + (r - l) / 2;
    if (l != r && tag[id]) {
        tag[2 * id] = max(tag[2 * id], tag[id]);
        tag[2 * id + 1] = max(tag[2 * id + 1], tag[id]);
        seg[2 * id] = max(seg[2 * id], tag[id]);
        seg[2 * id + 1] = max(seg[2 * id + 1], tag[id]);
        tag[id] = -inf;
    }
}

void modify(int ll, int rr, int l, int r, int id, long long val,
            vector<long long> &seg, vector<long long> &tag) {
    if (ll <= l && r <= rr) {
        tag[id] = max(tag[id], val);
        seg[id] = max(tag[id], val);
        return;
    }
    int m = l + (r - l) / 2;
    pushdown(l, r, id, seg, tag);
    if (ll <= m) modify(ll, rr, l, m, 2 * id, val, seg, tag);
    if (m < rr) modify(ll, rr, m + 1, r, 2 * id + 1, val, seg, tag);
    seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}

long long get(int ll, int rr, int l, int r, int id, vector<long long> &seg,
              vector<long long> &tag) {
    if (ll <= l && r <= rr) return seg[id];
    int m = l + (r - l) / 2;
    long long ret = -inf;
    pushdown(l, r, id, seg, tag);
    if (ll <= m) ret = max(ret, get(ll, rr, l, m, 2 * id, seg, tag));
    if (m < rr) ret = max(ret, get(ll, rr, m + 1, r, 2 * id + 1, seg, tag));
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
        for (int i = 0; i <= 4 * n + 1; i++) {
            seg1[i] = tag1[i] = -inf;
            seg2[i] = tag2[i] = -inf;
        }
        vector<pair<int, int>> p(n);
        vector<int> py(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
            py[i] = p[i].second;
        }
        sort(py.begin(), py.end());
        map<int, int> id;
        for (int i = 0; i < n; i++) {
            id[py[i]] = i + 1;
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int u, int v) {
            return p[u] < p[v];
        });
        long long ans = inf;
        for (int i : order) {
            long long x = p[i].first, y = p[i].second;
            int od = id[y];
            long long d = get(1, od, 1, n, 1, seg1, tag1);
            ans = min(ans, x + y - d);
            d = od + 1 <= n ? get(od + 1, n, 1, n, 1, seg2, tag2) : -inf;
            ans = min(ans, x - y - d);
            modify(od, od, 1, n, 1, x + y, seg1, tag1);
            modify(od, od, 1, n, 1, x - y, seg2, tag2);
        }
        cout << ans << '\n';
    }
    return 0;
}