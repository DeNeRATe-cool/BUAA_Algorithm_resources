#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
const int mod = 998244353;

char s[N];
int n;
int f[N], g[N];

void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f[0] = 0;
	g[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int v = s[i] - '0';
		f[i] = (1ll * f[i - 1] * (10 + v) + 1ll * g[i - 1] * v) % mod;
		g[i] = (1ll * f[i - 1] + g[i - 1]) % mod;
	}
	printf("%d\n", f[n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}