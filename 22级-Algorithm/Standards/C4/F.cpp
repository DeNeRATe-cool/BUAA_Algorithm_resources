#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2005;

int n1, n2;
char s1[N], s2[N];
int f[N][N], g[N][N];
int maxf, maxg;

void solve()
{
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	n1 = strlen(s1 + 1);
	n2 = strlen(s2 + 1);
	maxf = maxg = 0;
	for (int i = 1; i <= n1; i++)
		for (int j = 1; j <= n2; j++)
		{
			f[i][j] = s1[i] == s2[j] ? f[i - 1][j - 1] + 1 : 0;
			g[i][j] = max({g[i - 1][j - 1] + (s1[i] == s2[j]), g[i - 1][j], g[i][j - 1]});
			maxf = max(maxf, f[i][j]);
			maxg = max(maxg, g[i][j]);
		}
	printf("%d %d\n", maxf, maxg);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}