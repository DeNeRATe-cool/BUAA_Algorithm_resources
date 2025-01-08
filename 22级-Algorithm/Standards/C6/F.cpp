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

Hash hs, ht;
string s, t;

int main() {
#ifdef abyss
	freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	int T;
	for (cin >> T; T --; ) {
		cin >> s >> t;
        s = s + s;
		hs.init(131, 1000000007, s);
        ht.init(131, 1000000007, t);
		int len = t.size();
        bool got = false;
		for(int i = 1; i < len; i++)
            if(hs.query(i, i + len - 1) == ht.query(0, len - 1))
                {got = true;    break;}
        if(got) cout << "Yes\n";
        else cout << "No\n";
	}

	return 0;
}