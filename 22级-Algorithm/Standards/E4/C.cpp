#include <cstdio>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

const int N = 105;
const int E = 1e4 + 5;
const long long oo = 1e18;

int n, m, s, t;
int h[N], nx[E], to[E], et;
long long cap[E];
long long ans;
int d[N], q[N], ql, qr;

void ae(int u, int v, long long w)
{
	et++;
	to[et] = v;
	cap[et] = w;
	nx[et] = h[u];
	h[u] = et;
}

bool bfs(int s, int t)
{
	for (int i = 1; i <= n; i++)
		d[i] = n + 1;
	d[s] = 1;
	q[1] = s;
	ql = qr = 1;
	while (ql <= qr)
	{
		for (int i = h[q[ql]]; i; i = nx[i])
			if (cap[i] && d[to[i]] == n + 1)
			{
				d[to[i]] = d[q[ql]] + 1;
				q[++qr] = to[i];
			}
		ql++;
	}
	return d[t] <= n;
}

long long dfs(int u, int t, long long c)
{
	if (!c)
		return 0;
	if (u == t)
		return c;
	long long r = 0;
	for (int i = h[u]; i; i = nx[i])
		if (d[to[i]] == d[u] + 1)
		{
			long long v = dfs(to[i], t, min(c - r, cap[i]));
			if (v)
			{
				r += v;
				cap[i] -= v;
				cap[i ^ 1] += v;
				if (r == c)
					return r;
			}
		}
	if (r == 0)
		d[u] = n + 1;
	return r;
}

void solve()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= n; i++)
		h[i] = 0;
	et = 1;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		ae(u, v, w);
		ae(v, u, 0);
	}
	ans = 0;
	while (bfs(s, t))
		ans += dfs(s, t, oo);
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
