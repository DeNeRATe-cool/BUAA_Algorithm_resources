#include<queue>
#include<iostream>
using namespace std;
#define maxn (int)1e6+10
#define inf 2e9
#define ll long long
#define pr pair<int,int>
priority_queue<pr, vector<pr>, greater<pr>>q;
class edgex {
public:
	int to;
	int next;
	int weight;
};
int head[maxn];
edgex edge[maxn * 2];
int cnt = 0;
void add(int u, int v, int w) {
	edge[++cnt].next = head[u];
	edge[cnt].to = v;
	edge[cnt].weight = w;
	head[u] = cnt;
}
int dis[maxn];
bool visit[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	int u, v, w;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 2; i <= n; ++i) {
		dis[i] = inf;
	}
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		auto it = q.top();
		q.pop();
		int num = it.second;
		if (visit[num]) {
			continue;
		}
		visit[num] = true;
		for (int i = head[num]; i; i = edge[i].next) {
			int to = edge[i].to;
			int weight = edge[i].weight;
			dis[to] = min(dis[to], max(weight, dis[num]));
			q.push(make_pair(dis[to], to));
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (dis[i] == inf) {
			cout << "-1\n";
		}
		else {
			cout << dis[i] << "\n";
		}
	}
}