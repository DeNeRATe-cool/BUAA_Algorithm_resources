#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 505;

char a[N], b[N];
int n, mid;

int leq()
{
	for (int i = 1; i <= n; i++)
	{
		if (b[i] < a[i])
			return 1;
		if (b[i] > a[i])
			return 0;
	}
	return 1;
}

void solve()
{
	scanf("%s", a + 1);
	n = strlen(a + 1);
	mid = 1;
	for (int i = 1, j = n; i <= j; i++, j--)
	{
		b[i] = b[j] = a[i];
		mid = i;
	}
	b[n + 1] = 0;
	if (leq())
	{
		printf("%s\n", b + 1);
		return;
	}
	b[mid]--;
	for (int i = mid; i && b[i] < '0'; i--)
	{
		b[i] += 10;
		b[i - 1]--;
	}
	for (int i = 1; i <= mid; i++)
		b[n - i + 1] = b[i];
	if (b[1] != '0' && leq())
	{
		printf("%s\n", b + 1);
		return;
	}
	for (int i = 1; i < n; i++)
		b[i] = '9';
	b[n] = 0;
	printf("%s\n", b + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}