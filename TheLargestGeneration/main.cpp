#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>> children;
int level[105]{};
void dfs(int nd,int lv){
    if(children.find(nd) == children.end()) {level[lv]++; return;}
    level[lv]++;
    for(int node: children[nd]) dfs(node,lv+1);
}
int main() {
    int n,m,node,k{};
    cin>>n>>m;
    while(m--){
       cin>>node>>k;
       int tp[k];
       for(int i = 0;i < k;i++)  cin>>tp[i];
       children[node] = vector<int>(tp,tp+k);
    }
    dfs(1,1);
    int maxLevel{},maxCount{};
    for(int i = 1;i < 105;i++) {
        if(level[i] > maxCount) maxLevel = i,maxCount = level[i];
    }
    cout<<maxCount<<" "<<maxLevel<<endl;
    return 0;
}
