#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
const int E = 2e5 + 5;

int n, m;
int deg[N];
int h[N], to[E], nx[E], et;
int f[N];
int q[N], ql, qr;
int ans;

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
	deg[v]++;
}

void solve()
{
	scanf("%d%d", &n, &m);
	ans = 0;
	et = 0;
	for (int i = 1; i <= n; i++)
		h[i] = deg[i] = f[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ae(u, v);
	}
	ql = 1;
	qr = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0)
			q[++qr] = i;
	while (ql <= qr)
	{
		int cur = q[ql];
		f[cur]++;
		ans = max(ans, f[cur]);
		for (int i = h[cur]; i; i = nx[i])
		{
			f[to[i]] = max(f[to[i]], f[cur]);
			deg[to[i]]--;
			if (deg[to[i]] == 0)
				q[++qr] = to[i];
		}
		ql++;
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}