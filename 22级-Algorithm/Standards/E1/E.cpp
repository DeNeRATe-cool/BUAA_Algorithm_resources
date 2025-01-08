#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e4 + 5;

int n, d;
int a[N];
int ans;

void solve()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	ans = 0;
	a[0] = -d - 1;
	for (int i = 1; i <= n; i++)
		if (a[i - 1] + d < a[i])
			ans++;
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