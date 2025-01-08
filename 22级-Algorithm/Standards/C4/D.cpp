#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e3 + 5;

int n, k;
int f[N];

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= k; i++)
		f[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		int w, v;
		scanf("%d%d", &w, &v);
		for (int j = k; j >= v; j--)
			f[j] = max(f[j], f[j - v] + w);
	}
	printf("%d\n", f[k]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}