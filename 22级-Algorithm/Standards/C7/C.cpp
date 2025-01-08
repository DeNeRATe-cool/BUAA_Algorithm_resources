#include <bits/stdc++.h>

using namespace std;
//#define abyss

string solve(string s, int x) {
    int idx = 0;
    if(s[0] == '-') {
        idx = 1;
        for(; idx < s.size() && s[idx] <= x + '0'; idx++);
    } 
    else
        for(; idx < s.size() && s[idx] >= x + '0'; idx++);
    s.insert(idx, 1, (char)(x + '0'));
    return s;
}

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
    //freopen("./data/out4.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt, n; cin >> tt;
    while(tt--) {
        string ss; cin >> ss >> n;
        cout << solve(ss, n) << "\n";
    }
    return 0;
}