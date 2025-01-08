#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;
const long long oo = 1e18;

int n;
char s[N];
long long p, q;
long long dx[N], dy[N];
long long ans;

long long calc(long long dx, long long dy, long long rx, long long ry)
{
	if (dx == 0 && dy == 0)
		return 0;
	long long r;
	if (rx != 0)
		r = dx / rx;
	if (ry != 0)
		r = dy / ry;
	if (dx == rx * r && dy == ry * r)
		return r;
	return -1;
}

void solve()
{
	scanf("%d", &n);
	scanf("%lld%lld", &p, &q);
	scanf("%s", s + 1);
	dx[0] = dy[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dx[i] = dx[i - 1] + (s[i] == 'R') - (s[i] == 'L');
		dy[i] = dy[i - 1] + (s[i] == 'U') - (s[i] == 'D');
	}
	ans = oo;
	for (int i = 0; i < n; i++)
	{
		long long r = calc(p - dx[i], q - dy[i], dx[n], dy[n]);
		if (r >= 0)
			ans = min(ans, r * n + i);
	}
	if (ans >= oo)
		ans = -1;
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