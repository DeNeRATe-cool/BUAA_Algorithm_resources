#include <bits/stdc++.h>
#define maxn 1000086
 
using namespace std;
 
int t;
char s[maxn];
 
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		bool a[26] = {0};
		bool tag = false;
		for(int i = 1;i < n;i++){
			if(a[s[i] - 'a']) break;
			a[s[i] - 'a'] = true;
			bool flag = false;
			for(int j = 0;i + 1 + j < n - j;j++){
				if(s[i + 1 + j] != s[n - j]){
					flag = true;
					break;
				}
			}
			if(!flag){
				tag = true;
				break;
			}
		}
		puts(tag ? "HE" : "NaN");
	}
}
