#include <cstdio>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

const int N = 105;
const long long oo = 1e18;

int n, m, q;
long long f[N][N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				f[i][j][k] = oo;
	for (int x = 0; x <= n; x++)
		for (int i = 1; i <= n; i++)
			f[x][i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		f[1][u][v] = min(f[1][u][v], 1ll * w);
		f[1][v][u] = min(f[1][v][u], 1ll * w);
	}
	for (int t = 1; t < n; t++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				f[t + 1][i][j] = f[t][i][j];
				for (int k = 1; k <= n; k++)
					f[t + 1][i][j] = min(f[t + 1][i][j], f[t][i][k] + f[1][k][j]);
			}
	while (q--)
	{
		int s, t, k;
		scanf("%d%d%d", &s, &t, &k);
		k = min(k, n);
		long long ans = f[k][s][t];
		if (ans == oo)
			ans = -1;
		printf("%lld\n", ans);
	}
	return 0;
}
