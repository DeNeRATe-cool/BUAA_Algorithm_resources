#include <iostream>
#include <string>
#include<cstring>
using namespace std;
#define maxn (int)4e5+10
int sum[maxn];
int len;
inline bool check(const string& x, int a, int b, int c, int d) {
	int lenx = abs(a - b);
	if (sum[c + lenx] - sum[c - 1] != sum[a + lenx] - sum[a - 1]) {
		return false;
	}
	for (int i = 0; i <= lenx; ++i) {
		if (x[a + i] != x[c + i]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string x;
	int t;
	cin >> x;
	x.append(x);
	len = x.length();
	sum[0] = x[0] - 'a';
	for (int i = 1; i < len; ++i) {
		sum[i] = sum[i - 1] + x[i] - 'a';
	}
	int a, b, c, d;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		if (check(x, a-1, b-1, c-1, d-1)) {
			cout << "owo\n";
		}
		else {
			cout << "qwq\n";
		}
	}
}