#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-4;

vector<complex<double>> y;
int n;

void rev() {
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = pos[i >> 1] >> 1;
        if (i & 1) {
            pos[i] |= n >> 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < pos[i]) {
            swap(y[i], y[pos[i]]);
        }
    }
}
void fft(int on) {
    rev();
    for (int h = 2; h <= n; h <<= 1) {
        complex<double> wn(cos(2 * pi / h), sin(on * 2 * pi / h));
        for (int j = 0; j < n; j += h) {
            complex<double> w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                complex<double> u = y[k];
                complex<double> t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w *= wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < n; i++) {
            y[i].real(real(y[i]) / n);
            y[i].imag(imag(y[i]) / n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    n = (1 << k);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        y[i] = complex<double>(c, 0);
    }
    fft(-1);
    for (int i = 0; i < n; i++) {
        double r = real(y[i]);
        if (-0.005 < r && r < 0) r = 0;
        double v = imag(y[i]);
        if (-0.005 < v && v < 0) v = 0;
        cout << fixed << setprecision(2) << r << ' ' << v << '\n';
    }
    return 0;
}