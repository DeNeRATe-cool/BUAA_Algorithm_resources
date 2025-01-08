#include <cstdio>

using namespace std;

const int N = 1e3 + 5;

int n, m;
int h[N], to[N], nx[N], et;
double wt[N], dis[N];
bool vis[N];

void ae(int u, int v, double w)
{
	et++;
	to[et] = v;
	wt[et] = w;
	nx[et] = h[u];
	h[u] = et;
}

bool dfs(int u, double v)
{
	if (vis[u])
		return 1;
	vis[u] = 1;
	for (int i = h[u]; i; i = nx[i])
		if (dis[u] + wt[i] - v < dis[to[i]])
		{
			dis[to[i]] = dis[u] + wt[i] - v;
			if (dfs(to[i], v)) {
				vis[u] = 0;
				return 1;
			}
		}
	vis[u] = 0;
	return 0;
}

bool check(double v)
{
	for (int i = 1; i <= n; i++)
		dis[i] = 0;
	for (int i = 1; i <= n; i++)
		if (dfs(i, v))
			return 1;
	return 0;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		h[i] = 0;
	et = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		double w;
		scanf("%d%d%lf", &u, &v, &w);
		ae(u, v, w);
	}
	double l = 0, r = 1e7;
	for (int i = 1; i <= 50; i++)
	{
		double mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	if (l > 5e6)
		l = 0;
	printf("%.4lf\n", l);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}