#include <cstdio>
#include <algorithm>

using namespace std;

const int oo = 2e9;
const int N = 2e5 + 5;

int n;
int x[N], t[N];
int p[N], f[N];
int mx;

bool cmp(int a, int b)
{
	if (x[a] != x[b])
		return x[a] < x[b];
	return t[a] < t[b];
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &t[i]);
		t[i] -= x[i];
		p[i] = i;
		f[i] = oo;
	}
	sort(p + 1, p + n + 1, cmp);
	mx = 0;
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = mx;
		int v = t[p[i]];
		if (v < 0)
			continue;
		while (l < r)
		{
			int mid = (l + r) / 2 + 1;
			if (v < f[mid])
				r = mid - 1;
			else
				l = mid;
		}
		mx = max(mx, r + 1);
		f[r + 1] = v;
	}
	printf("%d\n", mx);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}