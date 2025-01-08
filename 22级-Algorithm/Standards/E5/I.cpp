#include <cstdio> 
#include <algorithm>
#include <cassert>

using namespace std;

const int N = 55;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y)
	{
		this -> x = x;
		this -> y = y;
	}
};

bool operator < (Point a, Point b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

Point operator - (Point a, Point b)
{
	return Point(a.x - b.x, a.y - b.y);
}

int n;
Point p[N];
int f[N][N][N], g[N][N][N];
int pw[N], pinv[N];
int t[N][N][N];
int ans;

long long cross(Point a, Point b)
{
	return 1ll * a.x * b.y - 1ll * b.x * a.y;
}

bool in(int o, int i, int j, int k)
{
	return cross(p[o] - p[j], p[i] - p[j]) > 0
		&& cross(p[k] - p[j], p[o] - p[j]) > 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = 2 * pw[i - 1] % mod;
	pinv[0] = 1;
	for (int i = 1; i <= n; i++)
		pinv[i] = 1ll * inv2 * pinv[i - 1] % mod;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
				assert(cross(p[j] - p[i], p[k] - p[i]) != 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
			{
				for (int o = 1; o <= n; o++)
					if (in(o, i, j, k) && in(o, j, k, i) && in(o, k, i, j))
						t[i][j][k]++;
				t[i][j][k] = pw[t[i][j][k]];
			}
	for (int i = 1; i <= n; i++)
		g[i][0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = j; k <= n; k++)
				if (g[i][j][k])
					for (int o = 1; o <= n; o++)
						if ((j == 0 && o > i) || cross(p[k] - p[j], p[o] - p[j]) > 0)
						{
							f[i][k][o] = (f[i][k][o] + 1ll * f[i][j][k]
								* t[i][k][o] % mod + 1ll * cross(p[k] - p[i], p[o] - p[i]) % mod
								* inv2 % mod * g[i][j][k] % mod * t[i][k][o] % mod) % mod;
							g[i][k][o] = (g[i][k][o] + 1ll * g[i][j][k]
								* t[i][k][o] % mod) % mod;
						}
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--)
			for (int k = j; k >= 1; k--)
				if (g[i][j][k])
					for (int o = 1; o <= k; o++)
						if (cross(p[k] - p[j], p[o] - p[j]) > 0)
						{
							f[i][k][o] = (f[i][k][o]
								+ 1ll * f[i][j][k] * t[i][k][o] % mod
								+ 1ll * cross(p[k] - p[i], p[o] - p[i]) % mod * inv2 % mod * g[i][j][k] % mod * t[i][k][o] % mod) % mod;
							g[i][k][o] = (g[i][k][o] + 1ll * g[i][j][k] * t[i][k][o] % mod) % mod;
						}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ans = (ans + f[i][j][i]) % mod;
	ans = 1ll * ans * pinv[n] % mod;
	printf("%d\n", ans);
	return 0;
}