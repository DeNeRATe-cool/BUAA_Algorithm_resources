#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4005;

char s[N];
int a[N], la;
int b[N], lb;
int c[N], lc;

void solve()
{
	scanf("%s", s);
	la = strlen(s);
	for (int i = 0; i < la; i++)
		a[i] = s[la - i - 1] - '0';
	scanf("%s", s);
	lb = strlen(s);
	for (int i = 0; i < lb; i++)
		b[i] = s[lb - i - 1] - '0';
	for (int i = 0; i < N; i++)
		c[i] = 0;
	lc = la + lb;
	for (int i = 0; i < la; i++)
		for (int j = 0; j < lb; j++)
			c[i + j] += a[i] * b[j];
	for (int i = 0; i < lc; i++)
	{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while (c[lc] >= 10)
	{
		c[lc + 1] += c[lc] / 10;
		c[lc] %= 10;
		lc++;
	}
	while (lc && c[lc] == 0)
		lc--;
	for (int i = lc; i >= 0; i--)
		printf("%d", c[i]);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}