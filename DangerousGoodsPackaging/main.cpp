#include <bits/stdc++.h>
using namespace std;
map<int,set<int>> mp;
int table[100000];
int main() {
    int n,m,x,y,cnt,ans;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d",&x,&y);
        mp[x].insert(y),mp[y].insert(x);
    }
    while(m--) {
        ans = 0;
        memset(table,0,sizeof(table));
        scanf("%d", &cnt);
        int curLis[cnt];
        for(int i = 0;i < cnt;i++)
            scanf("%d",&curLis[i]);
        for(int i = 0;i < cnt;i++){
            int cur = curLis[i];
            auto it = mp.find(cur);
            if (it == mp.end()) continue;
            if(!table[cur]) {
                for(auto itor: it->second) table[itor] = 1;
            }else{
                ans = 1;break;
            }
        }
        if(ans) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
