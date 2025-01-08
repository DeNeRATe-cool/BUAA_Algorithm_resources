#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 205;

int n;
int a[N][N], b[N][N];
long long c[N][N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &b[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			c[i][j] = 0;
			for (int k = 1; k <= n; k++)
				c[i][j] += 1ll * a[i][k] * b[k][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%lld%c", c[i][j], " \n"[j == n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}