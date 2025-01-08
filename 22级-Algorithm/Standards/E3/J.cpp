#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 85;

int n;
char s[N];
int ans;

namespace EQ2
{
	int f[N][N];

	void solve()
	{
		for (int p = 1; p <= n; p++)
		{
			for (int i = 1; i < p; i++)
				for (int j = p; j <= n; j++)
				{
					f[i][j] = (s[i] == s[j]);
					if (i > 1 && j > p)
						f[i][j] += f[i - 1][j - 1];
					if (i > 1)
						f[i][j] = max(f[i][j], f[i - 1][j]);
					if (j > p)
						f[i][j] = max(f[i][j], f[i][j - 1]);
					ans = max(ans, f[i][j] * 2);
				}
		}
	}
}

namespace EQ3
{
	int f[N][N][N];

	void solve()
	{
		for (int p = 1; p <= n; p++)
			for (int q = p; q <= n; q++)
			{
				for (int i = 1; i < p; i++)
					for (int j = p; j < q; j++)
						for (int k = q; k <= n; k++)
						{
							f[i][j][k] = (s[i] == s[j] && s[j] == s[k]);
							if (i > 1 && j > p && k > q)
								f[i][j][k] += f[i - 1][j - 1][k - 1];
							if (i > 1)
								f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
							if (j > p)
								f[i][j][k] = max(f[i][j][k], f[i][j - 1][k]);
							if (k > q)
								f[i][j][k] = max(f[i][j][k], f[i][j][k - 1]);
							ans = max(ans, f[i][j][k] * 3);
						}
			}
	}
}

namespace GEQ5
{
	char t[N];
	int c;

	void solve()
	{
		int len = (n + 4) / 5;
		for (int l = 1, r = len; l <= n; l += len, r += len)
		{
			r = min(r, n);
			int v = r - l + 1;
			for (int i = 1; i < (1 << v); i++)
			{
				c = 0;
				for (int j = 0; j < v; j++)
					if (i & (1 << j))
						t[++c] = s[l + j];
				t[c + 1] = 0;
				for (int j = 1, k = 0; j <= n; j++)
				{
					if (s[j] == t[k % c + 1])
						k++;
					if (k / c > 1)
						ans = max(ans, k / c * c);
				}
			}
		}
	}
}

void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	ans = 0;
	EQ2::solve();
	EQ3::solve();
	GEQ5::solve();
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