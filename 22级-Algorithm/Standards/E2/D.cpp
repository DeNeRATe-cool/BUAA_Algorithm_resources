#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;

int n;
ll pw[10];
ll cnt[10], bit[10];
ll ans;

int check(ll s)
{
	for (int i = 0; i < 10; i++)
		bit[i] = 0;
	while (s)
	{
		bit[s % 10]++;
		s /= 10;
	}
	for (int i = 0; i < 10; i++)
		if (cnt[i] != bit[i])
			return 0;
	return 1;
}

void dfs(int c, ll s = 0, ll mn = 0, ll b = 1)
{
	if (mn > s || c < 0)
		return;
	ans += check(s) * s;
	for (int i = 0; i <= c; i++)
	{
		cnt[i]++;
		dfs(i, s + pw[i], mn + max(b / 10, b * i), b * 10);
		cnt[i]--;
	}
}

void solve()
{
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < 10; i++)
	{
		pw[i] = 1;
		for (int j = 1; j <= n; j++)
			pw[i] *= i;
	}
	dfs(9);
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