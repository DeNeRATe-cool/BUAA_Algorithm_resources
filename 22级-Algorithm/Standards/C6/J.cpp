#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
using ld = double;

const int N = (1 << 18) + 5;
const ld pi = acosl(-1.0);

struct complex
{
	ld r, i;
	complex() { r = 0; i = 0; }
	complex(ld re, ld im) { r = re; i = im; }
	ld len2() const { return r * r + i * i; }
	complex bar() const { return complex(r, -i); }
};
complex operator + (const complex &x, const complex &y) { return complex(x.r + y.r, x.i + y.i); }
complex operator - (const complex &x, const complex &y) { return complex(x.r - y.r, x.i - y.i); }
complex operator * (ld x, const complex &y) { return complex(x * y.r, x * y.i); }
complex operator * (const complex &x, ld y) { return complex(x.r * y, x.i * y); }
complex operator * (const complex &x, const complex &y) { return complex(x.r * y.r - x.i * y.i, x.r * y.i + x.i * y.r); }
complex operator / (const complex &x, ld y) { return complex(x.r / y, x.i / y); }
complex operator / (const complex &x, const complex &y) { return x * y.bar() / y.len2(); }

char s[N], t[N];
int vs[N], vt[N];
int lens, lent;
int len;
complex a[N], b[N], c[N];
complex v[N];
int rev[N];
ld s2;
int ans;

void dft(complex c[], int inv = 0)
{
	for (int i = 0; i < len; i++)
		v[rev[i]] = c[i];
	for (int i = 2; i <= len; i <<= 1)
	{
		complex wn(cosl(2 * pi / i), sinl(2 * pi / i));
		for (int j = 0; j < len; j += i)
		{
			complex w(1, 0);
			for (int k = 0; k < (i >> 1); k++)
			{
				complex x = v[j + k], y = v[j + k + (i >> 1)] * w;
				v[j + k] = x + y;
				v[j + k + (i >> 1)] = x -y;
				w = w * wn;
			}
		}
	}
	if (inv)
	{
		for (int i = 0; i < len; i++)
			v[i] = v[i] / len;
		for (int i = 1, j = len - 1; i < j; i++, j--)
			swap(v[i], v[j]);
	}
	for (int i = 0; i < len; i++)
		c[i] = v[i];
}

void solve()
{
	scanf("%s", t);
	scanf("%s", s);
	lens = strlen(s);
	lent = strlen(t);
	len = 1;
	while (len <= lens + lent)
		len <<= 1;
	for (int i = 0; i < len; i++)
		c[i] = complex(0, 0);
	s2 = 0;
	for (int i = 0; i < lens; i++)
	{
		vs[i] = s[i] - 'a' + 1;
		if (s[i] == '?')
			vs[i] = 0;
		s2 += vs[i] * vs[i];
	}
	for (int i = 0; i < lent; i++)
		vt[i] = t[i] - 'a' + 1;

	for (int i = 0; i < len; i++)
	{
		rev[i] = 0;
		for (int j = 1, t = i; j < len; j <<= 1, t >>= 1)
			rev[i] <<= 1, rev[i] += t & 1;
	}

	for (int i = 0; i < len; i++)
		a[i] = b[i] = complex(0, 0);
	for (int i = 0; i < lens; i++)
		a[i] = complex(vs[lens - 1 - i] > 0 ? 1 : 0, 0);
	for (int i = 0; i < lent; i++)
		b[i] = complex(vt[i] * vt[i], 0);
	dft(a);
	dft(b);
	for (int i = 0; i < len; i++)
		c[i] = c[i] + a[i] * b[i];

	for (int i = 0; i < len; i++)
		a[i] = b[i] = complex(0, 0);
	for (int i = 0; i < lens; i++)
		a[i] = complex(vs[lens - 1 - i], 0);
	for (int i = 0; i < lent; i++)
		b[i] = complex(vt[i], 0);
	dft(a);
	dft(b);
	for (int i = 0; i < len; i++)
		c[i] = c[i] - 2.0 * a[i] * b[i];

	dft(c, 1);
	ans = 0;
	for (int i = lens - 1; i < lent; i++)
		if (abs(c[i].r + s2) < 0.5)
			ans++;
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}