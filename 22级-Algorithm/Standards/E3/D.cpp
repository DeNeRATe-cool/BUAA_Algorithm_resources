#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<deque>
#include<stack>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

const int Maxn = 1000086;
int a[Maxn], b[Maxn];
int n, m;

bool check(int k){
    for (int i = 1; i <= k; i++)
        if (a[i] >= b[n - k + i])
            return false;
    return true;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--){
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(b + 1, b + n + 1);
        sort(a + 1, a + n + 1);
        int lft = 0, rgt = n, ans = 0;
        while (lft <= rgt){
            int mid = (lft + rgt) >> 1;
            if (check(mid))
                lft = mid + 1, ans = mid;
            else rgt = mid - 1;
        }
        cout << n - ans << '\n';
    }
    return 0;
}