#include <cstdio>
#include <algorithm>

using namespace std;

int n;

void solve()
{
	scanf("%d", &n);
	printf("%lld\n", 1ll * (n + 1) * (n + 2));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}