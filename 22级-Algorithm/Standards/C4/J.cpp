#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2.5e4 + 5;
const int E = 5e4 + 5;

int n, m;
int h[N], to[E], nx[E], et;
int indeg[N], outdeg[N];
int u[E], v[E], p[E];
int q[E], cnt;

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
	indeg[v]++;
	outdeg[u]++;
}

bool cmp(int a, int b)
{
	return v[a] > v[b];
}

void dfs(int u)
{
	for (int i = h[u]; i; i = h[u])
	{
		h[u] = nx[i];
		dfs(to[i]);
	}
	q[++cnt] = u;
}

void solve()
{
	scanf("%d%d", &n, &m);
	et = 0;
	for (int i = 1; i <= n; i++)
		h[i] = indeg[i] = outdeg[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		p[i] = i;
	}
	sort(p + 1, p + m + 1, cmp);
	for (int i = 1; i <= m; i++)
		ae(u[p[i]], v[p[i]]);
	int s = 1, i0 = 0, o0 = 0;
	while (s < n && outdeg[s] == 0)
		s++;
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == outdeg[i])
			continue;
		if (indeg[i] < outdeg[i])
		{
			i0 += outdeg[i] - indeg[i];
			s = i;
		}
		if (indeg[i] > outdeg[i])
			o0 += indeg[i] - outdeg[i];
	}
	if (i0 > 1 || o0 > 1)
	{
		printf("mission impossible\n");
		return;
	}
	cnt = 0;
	dfs(s);
	if (cnt != m + 1)
	{
		printf("mission impossible\n");
		return;
	}
	for (int i = cnt; i; i--)
		printf("%d%c", q[i], " \n"[i == 1]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}