#include<bits/stdc++.h> 
#define eps 1e-9
#define maxn 300005
#define ls (tot << 1)
#define rs (tot << 1 | 1)
#define PII pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double pi = acos(-1);
const ll mod = 998244353;
inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int qpow(int a, int b){
    int ans = 1, base = a;
    while(b){
        if(b & 1) ans = 1ll * ans * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return ans;
}

int qpow(int a, int b, int mod){
    int ans = 1, base = a;
    while(b){
        if(b & 1) ans = 1ll * ans * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return ans;
}
//

int n, m;

int sgn(ll x){
	if(x > 0) return 1;
	if(x < 0) return -1;
	return 0;
}

struct Point{
	int x, y;
	
	Point operator - (const Point &a)const{
		return {x - a.x, y - a.y};
	}
	
	ll cross(Point a){
		return 1ll * x * a.y - 1ll * y * a.x;		
	}
}a[maxn], b[maxn];

Point init(){
	int x = read(), y = read();
	return {x, y};
}

bool check_intersect(Point a, Point b, Point x, Point y){
	return sgn((a - b).cross(x - b)) * sgn((a - b).cross(y - b)) <= 0 && 
		   sgn((x - y).cross(a - y)) * sgn((x - y).cross(b - y)) <= 0;
}

bool check(int mid, Point x){
	return sgn((b[mid] - a[mid]).cross(x - a[mid])) >= 0;
}

void solve(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = {-1000000000, read()};
	for(int i = 1; i <= n; i++) b[i] = {1000000000, read()};
	for(int i = 1; i <= m; i++){
		Point x = init(), y = init();
		int l = 1, r = n, mid, ans;
		while(l <= r){
			mid = l + r >> 1;
			if(check(mid, x)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		if(check_intersect(x, y, a[ans], b[ans]) || check_intersect(x, y, a[ans + 1], b[ans + 1])) puts("-1");
		else printf("%d\n", ans);
	}
}


int main(){
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
