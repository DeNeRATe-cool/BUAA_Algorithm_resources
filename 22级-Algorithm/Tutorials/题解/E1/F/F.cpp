#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct datatag {
	int num, id;
	bool operator<(const datatag& b)const {
		return num < b.num;
	}
}datas, * pdata;
datas inn[100001];
int t, n;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int h = 1; h <= t; ++h) {
		int sum = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> inn[i].num;
			inn[i].id = i;
		}
		sort(inn + 1, inn + n + 1);
		for (int i = 1; i <= n; ++i) {
			while (inn[i].id != i) {
				sum++;
				datas exchange = inn[i];
				inn[i] = inn[inn[i].id];
				inn[exchange.id] = exchange;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}