// @FileName  :C6F_ii_c.cpp
// @Time      :2023/12/4 20:24
// @Author    :YKW
//try:把头文件改成<bits/stdc++.h>交到c++入口
#include <stdio.h>
#include <string.h>
char s[400009], t[200009];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", s, t);
        sprintf(s, "%s%s", s, s);s[strlen(t)*2-1]='\0';
        printf(strstr(s+1, t) ? "Yes\n" : "No\n");
    }
}