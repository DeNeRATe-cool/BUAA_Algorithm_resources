#include <cstdio>
using namespace std;
const int N=300005;
int n,cur,l,r,c;
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int cur=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='(')
			cur++;
		else
			if (s[i]==')')
				cur--;
			else
				c++;
	r=(c+cur)/2;
	l=(c-cur)/2;
	for (int i=1;i<=n;i++)
		if (s[i]=='?')
			if (l>0)
			{
				l--;
				s[i]='(';
			}
			else
				if (r>0)
				{
					r--;
					s[i]=')';
				}
	cur=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='(')
			cur++;
		else
			if (s[i]==')')
				cur--;
			else
			{
				printf(":(\n");
				return 0;
			}
		if (cur<=0&&i!=n)
		{
			printf(":(\n");
			return 0;
		}
	}
	if (cur!=0)
	{
		printf(":(\n");
		return 0;
	}
	printf("%s\n",s+1);
	return 0;
}