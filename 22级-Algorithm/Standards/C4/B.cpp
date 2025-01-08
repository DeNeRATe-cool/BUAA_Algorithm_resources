#include <cstdio>

using namespace std;

int n, m;

void solve()
{
	scanf("%d%d", &n, &m);
	int first = 0, last = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &last);
			if (i == 1 && j == 1)
				first = last;
		}
	printf("%d\n", first > last ? first - last : last - first);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}