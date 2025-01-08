#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<complex>
#include<cstring>
using namespace std;
#define maxn (int)1<<22
#define com complex<double>
const double pi = 3.141592653589797;
int k;
com a[maxn], tmp[maxn];
void fft(com* F, int n, int inv) {
	if (n == 1) {
		return;
	}
	memcpy(tmp, F, n * sizeof(com));
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 1) {
			*(F + n / 2 + i / 2) = tmp[i];
		}
		else {
			*(F + i / 2) = tmp[i];
		}
	}
	fft(F, n / 2, inv);
	fft(F + n / 2, n / 2, inv);
	com* G = F;
	com* H = F + n / 2;
	com w0(1, 0), wn(cos(pi * 2 / n), inv * sin(pi * 2 / n));
	for (int i = 0; i < n / 2; ++i, w0 *= wn) {
		tmp[i] = G[i] + w0 * H[i];
		tmp[i + n / 2] = G[i] - w0 * H[i];
	}
	memcpy(F, tmp, n * sizeof(com));
}
int main() {
	scanf("%d", &k);
	int n = 1 << k;
	for (int i = 0; i < n; ++i) {
		double x;
		scanf("%lf", &x);
		a[i].real(x);
	}
	fft(a, n, -1);
	for (int i = 0; i < n; ++i) {
		printf("%.2lf %.2lf\n", ((int)round(a[i].real() / n * 100)) / 100.0, ((int)round(a[i].imag() / n * 100)) / 100.0);
	}
	return 0;
}