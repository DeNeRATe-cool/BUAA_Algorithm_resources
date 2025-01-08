#include <bits/stdc++.h>

using namespace std;
//#define abyss
const int MAXN = 1e6 + 5;

struct Hash {
	int BASE, P, val[MAXN], pw[MAXN];

	void init(int base, int p, string s) {
		BASE = base, P = p;
		int n = s.size();
		val[0] = s[0];
		for (int i = 1; i < n; i ++)
			val[i] = ((long long)val[i - 1] * base + s[i]) % p;
		pw[0] = 1;
		for (int i = 1; i <= n; i ++) pw[i] = (long long)pw[i - 1] * base % p;
	}

	int query(int l, int r) {
		if (l) return (val[r] + P - (long long)val[l - 1] * pw[r - l + 1] % P) % P;
		return val[r];
	}
};

Hash hs;
string s;

int main() {
#ifdef abyss
	freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> s;
    int len = s.size();
    s = s + s;
    hs.init(233, 1000000007, s);
    int Q;  cin >> Q;
    while(Q--) {
        int a, b, x, y; 
        cin >> a >> b >> x >> y;
        if(b < a) b += len;
        if(y < x) y += len;
        if(hs.query(a - 1, b - 1) == hs.query(x - 1, y - 1))
            cout << "owo\n";
        else cout << "qwq\n";
    }
	return 0;
}