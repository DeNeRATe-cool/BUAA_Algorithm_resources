// @FileName  :C6F_i.cpp
// @Time      :2023/12/4 20:24
// @Author    :YKW
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[N], t[N];
int nxt[N];
int kmp(int n, char *a, int m, char *b) {
    int i, j, ans = 0;
    for (nxt[0] = j = -1, i = 1; i < n; nxt[i++] = j) {
        while (~j && a[j + 1] != a[i]) j = nxt[j];
        if (a[j + 1] == a[i]) j++;
    }
    for (j = -1, i = 0; i < m; i++) {
        while (~j && a[j + 1] != b[i]) j = nxt[j];
        if (a[j + 1] == b[i])j++;
        if (j == n - 1) ans=i-n+1, j = nxt[j];
    }
    return ans;
}

int main() {
    int m;cin >> m;
    while (m--) {
        bool flag=true; int index;
        scanf("%s", s); scanf("%s", t);
        int len = strlen(t);
        if(len==1&&s[0]==t[0]){ cout<<"Yes"<<endl; continue; }
        if((index=kmp(len/2, t, len, s))){//s后缀与t前缀
            for(int i=0;i<index;i++)//遍历s前缀
                if(s[i]!=t[len-index+i])
                    flag=false;
            for(int i=0;i<len-index;i++)//遍历s后缀
                if(s[index+i]!=t[i])
                    flag= false;
        }else if((index=kmp(len/2,s,len,t))){//t后缀与s前缀
            for(int i=0;i<index;i++)
                if(t[i]!=s[len-index+i])//遍历t前缀
                    flag=false;
            for(int i=0;i<len-index;i++)//遍历t后缀
                if(t[index+i]!=s[i])
                    flag= false;
        }else//如果不存在
            flag= false;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}