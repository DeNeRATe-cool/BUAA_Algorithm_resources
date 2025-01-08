#include <cstdio>
#include <algorithm>

using namespace std;

const int P = 100;
const int N = 61670;

int p[P], pcnt;
int n, cnt;
int a[N];

void pre()
{
	for (int i = 2; i <= P; i++)
	{
		int dcnt = 0;
		for (int j = 2; j < i; j++)
			if (i % j == 0)
				dcnt++;
		if (!dcnt)
			p[++pcnt] = i;
	}
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	cnt = 0;
	for (int i = 1; i <= pcnt; i++)
	{
		int pv = p[i];
		int cur = 0;
		for (int j = 1; j <= n; j++)
			if (a[j] % pv == 0)
				cur++;
		if (cur > cnt)
			cnt = cur;
	}
	printf("%d\n", cnt);
}

int main()
{
	pre();
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}