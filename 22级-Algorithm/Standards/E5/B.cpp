#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/* template begin */

using _t = double;

const _t pi = acosl(-1.0);

struct Vec
{
	_t x, y;
	Vec() {}
	Vec(_t x, _t y) { this->x = x; this->y = y; }
	_t len() const { return sqrtl(x * x + y * y); }
	_t len2() const { return x * x + y * y; }
	Vec norm() const { _t l = len(); return Vec(x / l, y / l); }
	Vec rot(_t d) const { _t s = sinl(d), c = cosl(d); return Vec(c * x - s * y, c * y + s * x); }
	void read() { scanf("%lf%lf", &x, &y); }
	void print() const { printf("%lf %lf\n", x, y); }
	int quadrant() const
	{
		if (x > 0 && y >= 0) return 1;
		if (x <= 0 && y > 0) return 2;
		if (x < 0 && y <= 0) return 3;
		if (x >= 0 && y < 0) return 4;
		return 0;
	}
};
using Point = Vec;

Vec operator + (const Vec &a, const Vec &b) { return Vec(a.x + b.x, a.y + b.y); }
Vec operator - (const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y); }
Vec operator * (_t a, const Vec &b) { return Vec(a * b.x, a * b.y); }
// cross product
_t operator * (const Vec &a, const Vec &b) { return a.x * b.y - b.x * a.y; }
// inner product
_t operator ^ (const Vec &a, const Vec &b) { return a.x * b.x + a.y * b.y; }

using Polygon = vector <Point>;
using Points = vector <Point>;

bool onleft(const Vec &a, const Vec &b) { return a * b < 0; }
bool onright(const Vec &a, const Vec &b) { return a * b > 0; }
bool parallel(const Vec &a, const Vec &b) { return !onleft(a, b) && !onright(a, b); }

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

_t areadb(Polygon &p)
{
	_t r = 0;
	int n = p.size();
	for (int i = 0; i < n; i++)
		r += (p[i] - p[0]) * (p[(i + 1) % n] - p[i]);
	return r;
}
_t area(Polygon &p) { return areadb(p) / 2; }

_t diameter2(Polygon &p)
{
	_t r = 0;
	int n = p.size(), a = 0;
	if (n <= 1) return 0;
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
_t diameter(Polygon &p) { return sqrtl(diameter2(p)); }

struct Seg
{
	Point a, b;
	Seg() {}
	Seg(const Point &a, const Point &b) { this->a = a; this->b = b; }
};

_t dist(Point p, Seg s)
{
	if (((p - s.a) ^ (s.b - s.a)) < 0) return (p - s.a).len();
	if (((p - s.b) ^ (s.a - s.b)) < 0) return (p - s.b).len();
	Point o = s.a + ((p - s.a) ^ (s.b - s.a).norm()) * (s.b - s.a).norm();
	return (p - o).len();
}

struct Line
{
	Point o;
	Vec v;
	Line() {}
	Line(const Point &o, const Vec &v) { this->o = o; this->v = v.norm(); }
	Line(const Seg &s) { this->o = s.a; this->v = (s.b - s.a).norm(); }
	Line rot(_t d) const { return Line(o, v.rot(d)); }
};

_t dist(Point p, Line l)
{
	Point o = l.o + ((p - l.o) ^ l.v) * l.v;
	return (p - o).len();
}

Point itsc(Line a, Line b)
{
	_t da = (a.o - b.o) ^ a.v, db = (a.o - b.o) ^ b.v, d = a.v ^ b.v;
	_t mu = (da * d - db) / (d * d - 1);
	return b.o + mu * b.v;
}

using Lines = vector <Line>;

Polygon hpitsc(Lines p)
{
	sort(p.begin(), p.end(), [&](const Line &a, const Line &b)
	{
		if (a.v.quadrant() != b.v.quadrant()) return a.v.quadrant() < b.v.quadrant();
		if (!parallel(a.v, b.v)) return onright(a.v, b.v);
		return onleft(a.o - b.o, a.v);
	});
	int n = p.size(), l = 0, r = 0;
	Lines q(n);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && parallel(p[i - 1].v, p[i].v)) continue;
		while (r - l > 1 && onright(itsc(q[r - 1], q[r - 2]) - p[i].o, p[i].v)) r--;
		while (r - l > 1 && onright(itsc(q[l], q[l + 1]) - p[i].o, p[i].v)) l++;
		q[r++] = p[i];
	}
	while (r - l > 1 && onright(itsc(q[r - 1], q[r - 2]) - q[l].o, q[l].v)) r--;
	Polygon c;
	if (r - l > 2)
		for (int i = 0; i < r - l; i++)
			c.emplace_back(itsc(q[i + l], q[(i + 1) % (r - l) + l]));
	return c;
}

/* template end */

const int N = 5;
const _t oo = 1e18;

Point p[N];
_t ans;

_t calc()
{
	Line mAB = Line(Seg((_t)0.5 * (p[0] + p[1]), p[0])).rot(pi / 2);
	Line mAC = Line(Seg((_t)0.5 * (p[0] + p[2]), p[0])).rot(pi / 2);
	Point O = itsc(mAB, mAC);
	_t r = (O - p[0]).len();
	_t d = dist(O, Line(Seg(p[3], p[4])));
	return max((_t)0.0, d - r);
}

void chk(int c = 0)
{
	if (c >= N) { ans = min(ans, calc()); return; }
	for (int i = c; i < N; i++)
	{
		swap(p[i], p[c]);
		chk(c + 1);
		swap(p[i], p[c]);
	}
}

void solve()
{
	for (int i = 0; i < N; i++) p[i].read();
	ans = oo;
	chk();
	printf("%.3lf\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}