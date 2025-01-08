#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105;

int n;
char s[N];

void solve()
{
	scanf("%s", s + 1);
	sort(s + 1, s + strlen(s + 1) + 1, [&](char x, char y) { return x > y; });
	printf("%s\n", s + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}