#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, st;
bool cmp(vector<int> &b, vector<int> &a) {
    int st = N - 1;
    while (st > 0 && b[st] == 0)
        st--;
    if (st + 1 != n)
        return (st + 1 > n);
    for (int i = st, j = 0; i >= 0; i--, j++) {
        if (b[i] != a[j])
            return (b[i] > a[j]);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        n = (int) s.length();
        vector<int> a(N);
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        vector<int> b(N);
        b[0] = 1;
        st = 0;
        int ans = 0;
        while (true) {
            if (cmp(b, a))
                break;
            for (int i = 0; i <= st; i++)
                b[i] *= 2;
            for (int i = 0; i <= st; i++) {
                b[i + 1] += b[i] / 10;
                b[i] %= 10;
            }
            if (b[st + 1])
                st++;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}