#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1005;

int n;
int coord[N][3];
int out[3];

int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int check()
{
	for (int d = 0; d < 3; d++)
		if (out[d] < 1 || out[d] > n)
			return -1;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int d = 0; d < 3; d++)
			if (out[d] == coord[i][d])
				cnt++;
		if (cnt == 3)
			return -1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int px = coord[j][0] - coord[i][0];
			int py = coord[j][1] - coord[i][1];
			int pz = coord[j][2] - coord[i][2];
			int qx = out[0] - coord[i][0];
			int qy = out[1] - coord[i][1];
			int qz = out[2] - coord[i][2];
			int gp = gcd(gcd(abs(px), abs(py)), abs(pz));
			int gq = gcd(gcd(abs(qx), abs(qy)), abs(qz));
			px /= gp, py /= gp, pz /= gp;
			qx /= gq, qy /= gq, qz /= gq;
			if (px == qx && py == qy && pz == qz)
				return -1;
			if (px == -qx && py == -qy && pz == -qz)
				return -1;
		}
	return 0;
}

int rand(int l, int r)
{
	return rand() % (r - l + 1) + l;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int d = 0; d < 3; d++)
			scanf("%d", &coord[i][d]);
	for (int i = 1; i <= 100; i++)
	{
		for (int d = 0; d < 3; d++)
			out[d] = rand(1, n);
		if (check())
			continue;
		printf("%d %d %d\n", out[0], out[1], out[2]);
		return;
	}
	printf("-1\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}