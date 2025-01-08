// @FileName  :C6F_ii_cpp.cpp
// @Time      :2023/12/4 20:24
// @Author    :YKW
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;int T;cin>>T;
    while(T--) {
        cin >> s >> t;
        s=s.append(s.substr(0,s.length()-1)).substr(1);
        cout << (s.find(t) < t.length() ? "Yes\n" : "No\n");
    }
}