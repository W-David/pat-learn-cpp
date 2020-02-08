#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
vector<int> userMap[maxN];
int n,maxLevel,k;
int solve(int v){
    int num = 0,level[maxN]{0};
    bool marked[maxN]{false};
    queue<int> q;
    q.push(v);
    marked[v] = true;
    while(!q.empty()){
        v = q.front(),q.pop();
        for(int i: userMap[v]){
            if(!marked[i] && level[v] < maxLevel){
                num++;
                marked[i] = true;
                level[i] = level[v] + 1;
                q.push(i);
            }
        }
    }
    return num;
}
int main() {
    int cnt,cur;
    scanf("%d %d",&n,&maxLevel);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&cnt);
        while(cnt--) {
            scanf("%d",&cur);
            if(cur != i) userMap[cur].push_back(i);
        }
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d",&cur);
        printf("%d\n",solve(cur));
    }
    return 0;
}
