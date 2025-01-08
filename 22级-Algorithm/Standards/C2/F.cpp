#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, k;
int a[N];
int tcnt[N], vcnt[N], cnt;
int ans;

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
		tcnt[i] = vcnt[i] = 0;
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (!tcnt[a[i]])
			cnt++;
		tcnt[a[i]]++;
	}
	if (cnt != k)
	{
		printf("-1\n");
		return;
	}
	ans = cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vcnt[a[i]])
			cnt++;
		vcnt[a[i]]++;
		if (i > k)
		{
			vcnt[a[i - k]]--;
			if (!vcnt[a[i - k]])
				cnt--;
		}
		if (cnt > ans)
			ans = cnt;
	}
	ans = k - ans;
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