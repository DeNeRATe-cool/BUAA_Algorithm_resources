#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2005;

int n;
int x[N], y[N], t[N];
int p[N], f[N];
int ans;

bool cmp(int a, int b)
{
	return t[a] < t[b];
}

int dist(int i, int j)
{
	return abs(x[p[i]] - x[p[j]]) + abs(y[p[i]] - y[p[j]]);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &t[i]);
		p[i] = i;
		f[i] = -n;
	}
	sort(p + 1, p + n + 1, cmp);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
			if (dist(i, j) <= t[p[i]] - t[p[j]])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
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