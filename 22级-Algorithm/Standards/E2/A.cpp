#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 5;

int n;
char s[N];

void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int chk = 1;
	for (int i = 1; i < n; i++)
	{
		chk &= (s[i] == '9');
		s[i] = '9';
	}
	if (!chk)
		s[n] = 0;
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