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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int j = i;
            int cnt = 1;
            while (j - 1 >= 0 && a[j] > a[j - 1]) {
                swap(a[j - 1], a[j]);
                j--;
                cnt++;
            }
            cout << cnt << ' ';
        }
        cout << '\n';
    }
    return 0;
}