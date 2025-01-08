#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 50, M = (int) 15;

char a[N], b[M];

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%s%s", a, b);
        int n = strlen(a), m = strlen(b);
        int pos = 0;
        while (pos < n) {
            char *nxt = strstr(a + pos, b);
            if (!nxt) break;
            pos = nxt - a;
            printf("%d ", pos + 1);
            pos += m;
        }
        if (pos == 0)
            printf("-1");
        putchar('\n');
    }
    return 0;
}