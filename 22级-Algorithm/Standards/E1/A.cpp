#include <bits/stdc++.h>

using namespace std;
//#define abyss
#define MAXN 800

int nums[MAXN];

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
        for(int i = 1; i <= a; i++)
            for(int j = 1; j <= b; j++)
                for(int k = 1; k <= c; k++)
                    nums[i + j + k]++;
        int MAX = 0, res = 0;
        for(int i = 3; i <= a + b + c; i++) if(MAX < nums[i])
            MAX = nums[i], res = i;
        cout << res << "\n";
        memset(nums, 0, sizeof(nums));
    }
    return 0;
}