#include <stdio.h>
#include <stdlib.h>
#define ArraySize 100
long long P[ArraySize] = {0, 1, 1, 2};

int main()
{
    int n, k, x;
    scanf("%d", &x); //  x is between [1, 36]

    for (n=4; n<=x; n++)
    {
        for(k=1; k<n; k++)
        {
            P[n] += P[k]*P[n-k];
        }
    }

    printf("%-3s: %-20s\n", "n", "P(n)");
    for (n=1; n<=x; n++)
    {
        printf("%-3d: %-20lld\n", n, P[n]);
    }

    return 0;
}
