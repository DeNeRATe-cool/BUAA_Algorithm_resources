#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
#define conceal ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define inf 1e12
#define maxn 10001
int n, m, k, t;
ll r[maxn],s[maxn],dp1[maxn],dp2[maxn];
int main() {
	conceal;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= k; ++i) {
			cin >> s[i] >> r[i];
		}
		memset(dp1, inf, sizeof(dp1[1]) * (n + 1));
		memset(dp2, inf, sizeof(dp2));
		for (int i = 1; i<=n; ++i) {
			cout << dp1[i];
		}
		dp1[0] = 0, dp2[0] = 0;
		for (int i = 1; i <= max(n,m); ++i) {
			for (int j = 1; j <= k; ++j) {
				if (s[j] <= i && i <= n) {
					dp1[i] = min(dp1[i - s[j]] + r[j], dp1[i]);
				}
				if (s[j] <= i && i <= m) {
					dp2[i] = min(dp2[i - s[j]] + r[j], dp2[i]);
				}
			}
		}
		if (dp1[n] >= inf || dp2[m] >= inf)		cout << "-1\n";
		else	cout << dp1[n] + dp2[m] << "\n";
	}
	return 0;
}