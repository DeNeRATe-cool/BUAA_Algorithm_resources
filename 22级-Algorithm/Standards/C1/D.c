#include <stdio.h>

//#define abyss
#define MAXN 100005

long long a[MAXN], b[MAXN], A[MAXN], B[MAXN];
long long c[2 * MAXN], C[2 * MAXN];

int main()
{
#ifdef abyss
    freopen("in.txt", "r", stdin);
#endif

    int tt;  scanf("%d", &tt);
    while(tt--) {
        int n, m;   scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) scanf("%lld", &b[i]);
        for(int i = 1; i <= m; i++) scanf("%lld", &B[i]);

        int topA = 1, topB = 1, cnt = 0;
        while(topA <= n && topB <= m) {
            if(A[topA] == B[topB]) {
                long long tmp = a[topA] + b[topB];
                if(tmp) {c[++cnt] = tmp; C[cnt] = A[topA];}
                topA++; topB++;
            }
            else if(A[topA] < B[topB]) 
                c[++cnt] = a[topA], C[cnt] = A[topA++];
            else 
                c[++cnt] = b[topB], C[cnt] = B[topB++];
        }
        while(topA <= n) {c[++cnt] = a[topA]; C[cnt] = A[topA++];}
        while(topB <= m) {c[++cnt] = b[topB]; C[cnt] = B[topB++];}
        printf("%d\n", cnt);
        for(int i = 1; i <= cnt; i++)   printf("%lld%c", c[i], " \n"[i == cnt]);
        for(int i = 1; i <= cnt; i++)   printf("%lld%c", C[i], " \n"[i == cnt]);
    }
    return 0;
}