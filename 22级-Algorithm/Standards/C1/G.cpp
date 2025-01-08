#include <cstdio>
#include <algorithm>

using namespace std;

const int oo = 1e9;

int n, t;
int s, d, k;
int v, r;

int main()
{
	scanf("%d%d", &n, &t);
	v = oo;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &s, &d);
		k = t - s;
		if (k < 0)
			k = 0;
		k = (k + d - 1) / d * d + s;
		if (k < v)
		{
			v = k;
			r = i;
		}
	}
	printf("%d %d\n", v, r);
	return 0;
}