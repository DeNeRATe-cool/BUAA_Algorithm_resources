#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
priority_queue<ll, vector<ll>, greater<ll> > q;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	ll ans = 0;
	for(int i = 1;i < n;i++){
		ll x = q.top();q.pop();
		x += q.top();q.pop();
		ans += x * 2;
		q.push(x);
	}
	printf("%lld", ans);
} 