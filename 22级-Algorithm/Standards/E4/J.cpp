#include <cstdio>

using namespace std;

const int N = 305;
const int C = 45005;

int n, m, t;
int d[N][N];
int vf[N][C], vg[N][C];
int *f[N][N], *g[N][N];
int deg[N], p[N], pre[N];
int q[N], ql, qr;
int a, b, w;
int u, v, s, last;
int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
		pre[i] = n - i;
	for (int i = 1; i <= n; i++)
		pre[i] += pre[i - 1];
	for (int i = 0; i <= n + 1; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = &vf[i][pre[j - 1]] - j;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = &vg[i][pre[j - 1]] - j;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &s);
		if (d[a][b] == 0 || s < d[a][b])
			d[a][b] = s;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (d[i][j])
				deg[j]++;
	ql = 1;
	qr = 0;
	for (int i = 1; i <= n; i++)
		if (!deg[i])
			q[++qr] = i;
	while (ql <= qr)
	{
		int cur = q[ql];
		p[cur] = ql;
		for (int i = 1; i <= n; i++)
			if (d[cur][i])
			{
				deg[i]--;
				if (!deg[i])
					q[++qr] = i;
			}
		ql++;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (d[q[i]][q[j]])
			{
				f[0][i][j] = d[q[i]][q[j]];
				g[n + 1][i][j] = d[q[i]][q[j]];
			}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				f[k][i][j] = f[k - 1][i][j];
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (i < k && k < j)
				if (f[k][i][k] && f[k][k][j])
				if (f[k][i][j] == 0 || 
					f[k][i][k] + f[k][k][j] < f[k][i][j])
					f[k][i][j] = f[k][i][k] + f[k][k][j];
	}
	for (int k = n; k; k--)
	{
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				g[k][i][j] = g[k + 1][i][j];
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (i < k && k < j)
				if (g[k][i][k] && g[k][k][j])
				if (g[k][i][j] == 0 || 
					g[k][i][k] + g[k][k][j] < g[k][i][j])
					g[k][i][j] = g[k][i][k] + g[k][k][j];
	}
	while (t--)
	{
		scanf("%d%d%d", &u, &v, &s);
		u = (u + last) % n + 1;
		v = (v + last) % n + 1;
		s = (s + last) % n + 1;
		if (p[u] >= p[v] || u == s || v == s)
		{
			last = 0;
			printf("%d\n", last);
			continue;
		}
		last = d[u][v];
		for (int i = 1; i <= n; i++)
			if (p[u] < i && i < p[v] && q[i] != s)
				if (f[p[s] - 1][p[u]][i] && g[p[s] + 1][i][p[v]])
				if (last == 0 || f[p[s] - 1][p[u]][i] + g[p[s] + 1][i][p[v]] < last)
					last = f[p[s] - 1][p[u]][i] + g[p[s] + 1][i][p[v]];
		printf("%d\n", last);
	}
	return 0;
}