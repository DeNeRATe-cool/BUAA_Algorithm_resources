#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 22
#define MAXM 12
typedef long long LL;

LL a[MAXN][MAXM], t[MAXM][MAXM];
LL dp[MAXN][MAXM], from[MAXN][MAXM];

int main()
{
#ifdef abyss
    freopen("in1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int m, n;  cin >> m >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) cin >> a[j][i];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) cin >> t[i][j];
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1; i <= n; i++)
            dp[m][i] = a[m][i];
        for(int i = m - 1; i >= 1; i--) 
            for(int j = 1; j <= n; j++) 
                for(int k = 1; k <= n; k++)
                    if(dp[i][j] > dp[i+1][k] + t[j][k] + a[i][j]) {
                        dp[i][j] = dp[i+1][k] + t[j][k] + a[i][j];
                        from[i][j] = k;
                    }
                        
        LL tmp = dp[1][1], idx = 1;
        for(int i = 1; i <= n; i++)
            if(tmp > dp[1][i]) {tmp = dp[1][i]; idx = i;}
        cout << tmp << "\n";
        for(int i = 1; i <= m; i++) {
            cout << "Station" << i << ": Line" << idx << "\n";
            idx = from[i][idx];
        }
    }
    return 0;
}