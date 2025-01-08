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
int lens, lent;
int len;
complex a[N], b[N];
complex v[N];
int rev[N];
int ans[N];

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
	scanf("%s", s);
	scanf("%s", t);
	lens = strlen(s);
	lent = strlen(t);
	len = 1;
	while (len <= lens + lent)
		len <<= 1;
	for (int i = 0; i < len; i++)
	{
		a[i] = b[i] = complex(0, 0);
		ans[i] = 0;
	}
	for (int i = 0; i < lens; i++)
		a[i] = complex(s[lens - 1 - i] - '0', 0);
	for (int i = 0; i < lent; i++)
		b[i] = complex(t[lent - 1 - i] - '0', 0);
	for (int i = 0; i < len; i++)
	{
		rev[i] = 0;
		for (int j = 1, t = i; j < len; j <<= 1, t >>= 1)
			rev[i] <<= 1, rev[i] += t & 1;
	}
	dft(a);
	dft(b);
	for (int i = 0; i < len; i++)
		b[i] = a[i] * b[i];
	dft(b, 1);
	for (int i = 0; i < len; i++)
	{
		ans[i] += round(b[i].r);
		ans[i + 1] += ans[i] / 8;
		ans[i] %= 8;
	}
	while (len > 1 && ans[len - 1] == 0)
		len--;
	for (int i = len - 1; i >= 0; i--)
		printf("%d", ans[i]);
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}