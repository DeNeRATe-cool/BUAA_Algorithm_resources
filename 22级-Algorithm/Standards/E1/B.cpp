#include <bits/stdc++.h>

using namespace std;
//#define abyss

int Ackmann(int m, int n) {
    if(m == 0) return n + 1;
    if(n == 0) return Ackmann(m - 1, 1);
    return Ackmann(m - 1, Ackmann(m, n - 1));
}

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt;
    while(tt--) {
        int m, n; cin >> m >> n;
        cout << Ackmann(m, n) << "\n";
    }
    return 0;
}