#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
    Point() {}
    Point(long long _x, long long _y) : x(_x), y(_y) {}

    bool operator<(const Point &r) const {
        if (x == r.x) return y < r.y;
        return x < r.x;
    }
    Point operator-(const Point &r) { return Point(x - r.x, y - r.y); }
    long long operator*(const Point &r) { return x * r.y - y * r.x; }
    int quadrant() {
        if (x > 0 && y >= 0) return 1;
        if (x <= 0 && y > 0) return 2;
        if (x < 0 && y <= 0) return 3;
        if (x >= 0 && y < 0) return 4;
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<array<long long, 3>> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i][0] >> p[i][1] >> p[i][2];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            vector<Point> es(n - 1);
            vector<bool> cs(n - 1);
            int pos = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                es[pos] = Point(p[j][0] - p[i][0], p[j][1] - p[i][1]);
                cs[pos] = p[j][2];
                pos++;
            }
            vector<int> order(n - 1);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int u, int v) {
                if (es[u].quadrant() == es[v].quadrant()) {
                    return es[u] * es[v] > 0;
                }
                return es[u].quadrant() < es[v].quadrant();
            });
            vector<vector<int>> color(2, vector<int>(n - 1));
            for (int od = 0; od < n - 1; od++) {
                color[0][od] = od - 1 >= 0 ? color[0][od - 1] : 0;
                color[1][od] = od - 1 >= 0 ? color[1][od - 1] : 0;
                color[cs[order[od]]][od]++;
            }
            vector<int> cnt(n - 1);
            int p1 = 0, p2 = 0;
            while (p1 < n - 1) {
                while (es[order[p1]] * es[order[p2]] >= 0) {
                    p2 = (p2 + 1) % (n - 1);
                    if (p2 == p1) {
                        break;
                    }
                }
                cnt[p1] = p2 > p1 ? p2 - p1 : (n - 1 - (p1 - p2));
                p1++;
            }
            for (int od = 0; od < n - 1; od++) {
                int c = cs[order[od]];
                long long up1 = 0, up2 = 0;

                if (od + cnt[od] - 1 < n - 1) {
                    up1 = color[c][od + cnt[od] - 1] - color[c][od];
                    up2 = color[c ^ 1][od + cnt[od] - 1] - color[c ^ 1][od];
                } else {
                    up1 = color[c][n - 2] - (color[c][od] - (od + cnt[od] - 1 < 0 ? 0 : color[c][(od + cnt[od] - 1) % (n - 1)]));
                    up2 = color[c ^ 1][n - 2] - (color[c ^ 1][od] - (od + cnt[od] - 1 < 0 ? 0 : color[c ^ 1][(od + cnt[od] - 1) % (n - 1)]));
                }
                long long dw1 = color[c][n - 2] - up1 - 1;
                long long dw2 = color[c ^ 1][n - 2] - up2;

                if (p[i][2] == cs[order[od]]) {
                    ans += 2 * up2 * dw2;
                } else {
                    ans += up1 * dw2 + up2 * dw1;
                }
            }
        }
        cout << ans / 4 << '\n';
    }
    return 0;
}