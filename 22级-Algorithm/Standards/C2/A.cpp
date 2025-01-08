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
        int fir = 0, sec = 0;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x > fir) {
                sec = fir;
                fir = x;
            } else if (x > sec) {
                sec = x;
            }
        }
        cout << fir + sec << '\n';
    }
    return 0;
}