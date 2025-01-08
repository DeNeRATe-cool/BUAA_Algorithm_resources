#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define maxn (int)1e6+1
int n;
ll num1[maxn];
ll num2[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> num1[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> num2[i];
	}
	sort(num1 + 1, num1 + 1 + n);
	sort(num2 + 1, num2 + 1 + n);
	int cnt = 0;
	for (int i = 1; i <= n - cnt; ++i) {
		while (num1[i] >= num2[i + cnt] && i <= n - cnt) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}