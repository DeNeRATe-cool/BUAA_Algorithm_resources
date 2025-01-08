#include <bits/stdc++.h>

using namespace std;

vector<int> pi(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int n = (int) s.length();
        vector<int> p = pi(s);
        int j = 0;
        bool ok = true;
        for (int i = 0; i < (int) t.length(); i++) {
            if (s[j] == t[i]) {
                j = (j + 1) % n;
                continue;
            }
            while (j > 0 && s[j] != t[i]) j = p[j - 1];
            if (s[j] != t[i]) {
                ok = false;
                break;
            }
            j = (j + 1) % n;
        }
        cout << (ok ? "owo" : "ono") << '\n';
    }
    return 0;
}