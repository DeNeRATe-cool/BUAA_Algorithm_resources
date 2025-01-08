#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 5;

char s[maxn];
int trans[maxn][15];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    trans[0][s[0] - 'a'] = 1;
    int X = 0;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < 10; i++) {
            if (s[j] - 'a' == i) {
                trans[j][i] = j + 1;
            } else {
                trans[j][i] = trans[X][i];
            }
        }
        X = trans[X][s[j] - 'a'];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 10; j++)
            printf("%d%c", trans[i][j], j == 9 ? '\n' : ' ');
	return 0;
}