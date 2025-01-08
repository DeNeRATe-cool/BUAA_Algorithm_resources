#include <bits/stdc++.h>
#define maxn 205
typedef long long ll;
const int p = 1e9 + 7;
using namespace std;
int n;
ll k;
struct Martix
{
	ll a[maxn][maxn];
};
inline Martix multiply(Martix x, Martix y)
{
	Martix z;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			z.a[i][j] = 0;
			for (int k = 1; k <= n; k++)
			{
				z.a[i][j] += x.a[i][k] * y.a[k][j];
				z.a[i][j] %= p;
			}
		}
	}
	return z;
}
inline Martix fpow(Martix x, ll k)
{
	Martix y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				y.a[i][j] = 1;
			else
				y.a[i][j] = 0;
		}
	}
	while (k)
	{
		if (k & 1)
			y = multiply(y, x);
		x = multiply(x, x);
		k >>= 1;
	}
	return y;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%", &n);
		k = n;
		Martix x;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%lld", &x.a[i][j]);
			}
		}
		x = fpow(x, k);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%lld ", x.a[i][j]);
			}
			printf("\n");
		}
	}
}
