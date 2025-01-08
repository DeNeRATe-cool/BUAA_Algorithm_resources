#include <bits/stdc++.h>

using namespace std;

int win(char l, char r) {
    return (l == 'R' && r == 'S' ||
            l == 'S' && r == 'P' ||
            l == 'P' && r == 'R');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ls = (int) s.length(), lt = (int) t.length();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            a += win(s[i % ls], t[i % lt]);
            b += win(t[i % lt], s[i % ls]);
        }
        cout << a << ' ' << b << '\n';
    }
    return 0;
}