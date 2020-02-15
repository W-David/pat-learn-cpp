#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> edge;
const int max_n = 10000;
vector<edge> net[max_n];
int vis[max_n],dist[max_n],pre[max_n],line[max_n],pathSize[max_n];
void dijkstra(int start){
    fill(vis,vis+max_n,0);
    fill(line,line+max_n,0);
    fill(pathSize,pathSize+max_n,0);
    fill(pre,pre+max_n,-1);
    fill(dist,dist+max_n,INF);
    for(edge &it: net[start]) {
        int ns = it.first;
        dist[ns] = 1;
        line[ns] = it.second;
        pre[ns] = start;
        pathSize[ns] = net[ns].size() + net[start].size();
    }
    vis[start] = true;
    for(int i = 0;i < max_n;i++){
        int k = -1,m = INF;
        for(int j = 0;j < max_n;j++){
            if(!vis[j] && dist[j] < m) k = j,m = dist[j];
        }
        if(k == -1) break;
        vis[k] = true;
        for(auto &it: net[k]){
            int nk = it.first;
            if(vis[nk]) continue;
            if(dist[k] + 1 <= dist[nk]){
                if(dist[k] + 1 < dist[nk]){
                    pre[nk] = k;
                    pathSize[nk] = pathSize[k] + net[nk].size();
                    line[nk] = it.second;
                    dist[nk] = dist[k] + 1;
                }else if(pathSize[k] + net[nk].size() < pathSize[nk]){
                    pre[nk] = k;
                    pathSize[nk] = pathSize[k] + net[nk].size();
                    line[nk] = it.second;
                }
            }
        }
    }
}
int main(){
    int n,c,m,start,end;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&c);
        int lis[c];
        for(int j = 0;j < c;j++) scanf("%d",&lis[j]);
        for(int j = 0;j < c - 1;j++){
            int v = lis[j],w = lis[j+1];
            net[v].push_back(edge(w,i));
            net[w].push_back(edge(v,i));
        }
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&start,&end);
        dijkstra(start);
        printf("%d\n",dist[end]);
        vector<int> path;
        for(int i = end;i != -1;i = pre[i]) path.push_back(i);
        int sz = path.size();
        for(int i = sz-1;i > 0;i--){
            int s = (i == sz - 1) ? i : i+1;
            while(i > 0 && (i == sz - 1 || line[path[i]] == line[path[i-1]])) i--;
            printf("Take Line#%d from %04d to %04d\n",line[path[s == sz - 1 ? s-1 : s]],path[s],path[i]);
        }
    }
    return 0;
}