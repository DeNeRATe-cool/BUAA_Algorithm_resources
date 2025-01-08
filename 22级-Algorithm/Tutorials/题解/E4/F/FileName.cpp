#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
#define maxn (int)1e5+100
#define maxm (int)2e5+100
#define inf 1e8
using pr = pair<int, int>;
int n, m;
vector<int>edge[maxn];
vector<pr>ans1;
vector<pr>ans2;
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			edge[i].clear();
		}
		ans1.clear();
		ans2.clear();
		int u, v;
		for (int i = 1; i <= m; ++i) {
			cin >> u >> v;
			edge[u].push_back(v);
		}
		for (int i = 1; i <= n; ++i) {
			sort(edge[i].begin(), edge[i].end());
		}
		for (int i = 1; i <= n; ++i) {
			for (int j : edge[i]) {
				if (i < j) {
					ans1.push_back(make_pair(i, j));
				}
				else if (i > j) {
					ans2.push_back(make_pair(i, j));
				}
			}
		}
		if (ans1.size() >= m / 2) {
			cout << ans1.size() << '\n';
			for (pr tmp : ans1) {
				cout << tmp.first << " " << tmp.second << "\n";
			}
		}
		else {
			cout << ans2.size() << '\n';
			for (pr tmp : ans2) {
				cout << tmp.first << " " << tmp.second << "\n";
			}
		}
	}
}