#include <cstdio>
#include <cmath>

using namespace std;
using ld = double;

const int N = 1 << 16;
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

int n, len;
complex c[N], v[N];
int rev[N];
complex z;

void dft()
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
}

int main()
{
	scanf("%d", &n);
	len = 1 << n;
	for (int i = 0; i < (1 << n); i++)
	{
		ld v;
		scanf("%lf", &v);
		c[i] = complex(v, 0);
	}
	for (int i = 0; i < len; i++)
		for (int j = 1, t = i; j < len; j <<= 1, t >>= 1)
			rev[i] <<= 1, rev[i] += t & 1;
	dft();
	z = complex(0, 0);
	for (int i = 0; i< len; i++)
		z = z + cosl(i) * v[i];
	printf("%.2lf %.2lf\n", z.r, z.i);
	return 0;
}