#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;

int n;
long long a[N], b[N];
long long ans;

void solve()
{
	ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
		if (i & 1)
			b[i] = a[i] - a[i + 1] + 1;
		else
			b[i] = a[i + 1] - a[i] + 1;
	for (int i = 1; i < n; i++)
		b[i] = max(b[i], 0LL);
	for (int i = 1; i < n; i++)
	{
		ans += b[i];
		b[i + 1] -= min(b[i], b[i + 1]);
		b[i] -= b[i];
	}
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}