#include <bits/stdc++.h>
using namespace std;
int t;
char s[2010];
int dp[2010][2010];
int maxx;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		maxx = 0;
		for (int len = 1; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1;
				dp[i][j] = 0;
				if (i == j)
					dp[i][j] = 1;
				else if (s[i] == s[j] && dp[i + 1][j - 1] == (j - 1 - i))
					dp[i][j] = (j - i + 1);
				maxx = max(dp[i][j], maxx);
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}
