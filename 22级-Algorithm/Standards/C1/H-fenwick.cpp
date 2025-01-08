#include <bits/stdc++.h>

using namespace std;

class fenwick {
  public:
    int n;
    vector<int> arr;
    fenwick(int _n) : n(_n) { arr.resize(n); }
    void modify(int x, int val) {
        while (x < n) {
            arr[x] += val;
            x |= (x + 1);
        }
    }
    int get(int x) {
        int ret = 0;
        while (x >= 0) {
            ret += arr[x];
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
        int n;
        cin >> n;
        fenwick tr(n + 1);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            ans += i - tr.get(a);
            tr.modify(a, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}