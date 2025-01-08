#include <cstdio>
#include <algorithm>

using namespace std;

const int N = (1 << 18) + 5;
int n;
int p[N], ans[N];

int solve(int l, int r)
{
	if (l == r)
		return l;
	int mid = (l + r) >> 1;
	int lc = solve(l, mid), rc = solve(mid + 1, r);
	ans[lc] = max(ans[lc], p[rc]);
	ans[rc] = max(ans[rc], p[lc]);
	if (p[lc] > p[rc])
		return lc;
	return rc;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= (1 << n); i++)
	{
		scanf("%d", &p[i]);
		ans[i] = 0;
	}
	solve(1, 1 << n);
	for (int i = 1; i <= (1 << n); i++)
		printf("%d%c", ans[i], " \n"[i == (1 << n)]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}