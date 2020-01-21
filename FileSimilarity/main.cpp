#include <iostream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
set<string> s[105];
void input(int n) {
   for(int i = 1;i <= n;i++) {
       string str;
       while(true){
           char c = getchar();
           if(c == '#') break;
           if(isalpha(c)){
               if(c >= 'A' && c <= 'Z') c += 32;
               str += c;
           }
           else{
               if(str.size() >= 3){
                  if(str.size() > 10) str = str.substr(0,10);
                  s[i].insert(str);
               }
               str = "";
           }
       }
   }
}
void solve(int m){
   for(int i = 0;i < m;++i) {
      int a,b,same = 0; cin>>a>>b;
      for(const auto &it: s[a]){
          if(s[b].count(it) != 0) same++;
      }
      int sa = s[a].size(),sb = s[b].size();
      double sameRate =  (same * 1.0 / (sa + sb - same)) * 100;
      printf("%.1f%%\n",sameRate);
   }
}
int main(){
    int n;cin>>n; input(n);
    int m;cin>>m; solve(m);
    return 0;
}
