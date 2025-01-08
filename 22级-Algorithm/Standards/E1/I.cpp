#include <bits/stdc++.h>

using namespace std;
//#define abyss

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt;
    while(tt--) {
        int a, b, c; cin >> a >> b >> c;
        int big = max(a, max(b, c));
        int small = min(a, min(b, c));
        int mid = a ^ b ^ c ^ big ^ small;
        if(mid <= big - small + 1)
            cout << 1 + mid + small << "\n";
        else cout << (a + b + c + 3) / 2 << "\n";
    }
    return 0;
}