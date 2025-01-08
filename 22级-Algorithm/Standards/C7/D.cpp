#include "bits/stdc++.h"
typedef long long ll;
using namespace std;
int T;

bool check(int n, ll x, ll y, ll a, ll b){
    a -= n * x, b -= n * x;
    if(a < 0 || b < 0) return false;
    if(x == y) return true;
    n -= a / (y - x);
    n -= b / (y - x);
    return n <= 0;
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if(x > y) swap(x, y);
        int l = 0, r = 2000000000, mid, ans;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(check(mid, x, y, a, b)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        printf("%d\n", ans);
    }
    return 0;
}

/*
70000
*/