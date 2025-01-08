#include <bits/stdc++.h>

using namespace std;

const int N = 128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> mp1(N), mp2(N);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (mp1[s1[i]] && mp1[s1[i]] != s2[i]) ok = false;
            if (mp2[s2[i]] && mp2[s2[i]] != s1[i]) ok = false;
            mp1[s1[i]] = s2[i];
            mp2[s2[i]] = s1[i];
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}