#include<bits/stdc++.h> 
#define eps 1e-9
#define maxn 100005
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

int n, m, in[maxn];
vector<int> e[maxn];
priority_queue<int> q;

void solve(){
	n = read(), m = read();
	for(int i = 1; i <= m; i++){
		int u = read(), v = read();
		e[u].push_back(v);
		in[v]++;
	}
	for(int i = 1; i <= n; i++) if(!in[i]) q.push(i);
	while(!q.empty()){
		int x = q.top();q.pop();
		printf("%d ", x);
		for(auto u: e[x]){
			in[u]--;
			if(!in[u]) q.push(u);
		}
	}
}


int main(){
	solve();
    return 0;
}
