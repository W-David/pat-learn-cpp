#include <bits/stdc++.h>
using namespace std;
const int max_n = 1005;
vector<int> hobbyCluster[max_n];
int pre[max_n],rk[max_n],cnt[max_n];
int find(int x){
    if(x == pre[x]) return x;
    else return pre[x] = find(pre[x]);
}
void unite(int p,int q){
    p = find(p),q = find(q);
    if(p == q) return;
    if(rk[p] < rk[q]) pre[p] = q;
    else {
        pre[q] = p;
        if(rk[p] == rk[q]) rk[p]++;
    }
}
int main() {
    int n,c,h;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) pre[i] = i;
    for(int i = 1;i <= n;i++){
        scanf("%d:",&c);
        for(int j = 0;j < c;j++){
            scanf("%d",&h);
            hobbyCluster[h].push_back(i);
        }
    }
    for(int i = 1;i < max_n;i++){
        auto vc = hobbyCluster[i];
        if(vc.empty()) continue;
        int sz = vc.size();
        for(int j = 1;j < sz;j++) unite(vc[0],vc[j]);
    }
    vector<int> vc;
    for(int i = 1;i <= n;i++) cnt[pre[i]]++;
    for(int i = 1;i <= n;i++) if(cnt[i]) vc.push_back(cnt[i]);
    sort(vc.begin(),vc.end(),greater<int>());
    int s = vc.size();
    printf("%d\n%d",s,vc.front());
    for(int i = 1;i < s;i++) printf(" %d",vc[i]);
    return 0;
}
