#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/* template begin */

struct Vec
{
	long long x, y;
	Vec() {}
	Vec(long long x, long long y) { this->x = x; this->y = y; }
	long long len2() const { return x * x + y * y; }
	void read() { scanf("%lld%lld", &x, &y); }
	void print() { printf("%lld %lld\n", x, y); }
};
typedef Vec Point;

Vec operator + (const Vec &a, const Vec &b) { return Vec(a.x + b.x, a.y + b.y); }
Vec operator - (const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y); }
Vec operator * (long long a, const Vec &b) { return Vec(a * b.x, a * b.y); }
// cross product
long long operator * (const Vec &a, const Vec &b) { return a.x * b.y - b.x * a.y; }
// inner product
long long operator ^ (const Vec &a, const Vec &b) { return a.x * b.x + a.y * b.y; }

typedef vector <Point> Polygon;
typedef Polygon Points;

bool onleft(const Vec &a, const Vec &b) { return a * b < 0; }
bool onright(const Vec &a, const Vec &b) { return a * b > 0; }

// c0 - c1 - ... - ck (- c0), counter-clockwise
Polygon convex(Points p)
{
	int sz = p.size();
	sort(p.begin(), p.end(), [&](const Point &a, const Point &b) { return a.x != b.x ? a.x < b.x : a.y < b.y; });
	Polygon c(p.size() + 1);
	int n = 0;
	for (int i = 0; i < sz; i++)
	{
		while (n > 1 && !onleft(p[i] - c[n - 2], c[n - 1] - c[n - 2])) n--;
		c[n++] = p[i];
	}
	int t = n;
	for (int i = sz - 1; i >= 0; i--)
	{
		while (n > t && !onleft(p[i] - c[n - 2], c[n - 1] - c[n - 2])) n--;
		c[n++] = p[i];
	}
	c.resize(--n);
	return c;
}

long long areadb(Polygon &p)
{
	long long r = 0;
	int n = p.size();
	for (int i = 0; i < n; i++)
		r += (p[i] - p[0]) * (p[(i + 1) % n] - p[i]);
	return r;
}

long long diameter2(Polygon &p)
{
	long long r = 0;
	int n = p.size();
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		Vec e = p[(i + 1) % n] - p[i];
		while (onleft(p[(a + 1) % n] - p[a % n], e) || a == i)
		{
			r = max({r, (p[i] - p[a]).len2(), (p[(i + 1) % n] - p[a]).len2()});
			a = (a + 1) % n;
		}
		r = max({r, (p[i] - p[a]).len2(), (p[(i + 1) % n] - p[a]).len2()});
	}
	return r;
}

/* template end */

int n;
Points p;

void solve()
{
	scanf("%d", &n);
	p.resize(n);
	for (int i = 0; i < n; i++)
		p[i].read();
	p = convex(p);
	long long r = areadb(p);
	printf("%lld.%lld\n", r / 2, (r & 1) * 5);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}