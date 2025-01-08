#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
long long x, y, a, b;

int checkTotal(long long num) {
    long long A = a;
    long long B = b;
    long long p = min(x, y);
    p *= num;
    A -= p;
    B -= p;
    if (A >= 0 && B >= 0) {
        if (x != y) {
            long long tmp = A / llabs(x - y) + B / llabs(x - y);
            if (tmp >= num)return 1;
            else return 0;
        } else return 1;
    } else return 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        long long max = (long long) ((a + b) / (x + y));
        long long l = 0, r = max;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            int k = checkTotal(mid);
            if (k == 1)l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", l - 1);
    }
    return 0;
}
