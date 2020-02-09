#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxN = 1100;
int n,m,k,md,ds;
int graph[maxN][maxN];
struct Gas{
    int id;
    double minDis,avgDis;
    explicit Gas(int id,double minDis,double avgDis){this->id = id;this->minDis = minDis;this->avgDis = avgDis;}
};
vector<Gas> candidate;
auto cmp = [](Gas a,Gas b){return a.minDis == b.minDis ? (a.avgDis == b.avgDis ? a.id < b.id : a.avgDis < b.avgDis) : a.minDis > b.minDis;};
void dijkstra(int c){
    int marked[maxN]{0},dist[maxN]{0};
    for(int i = 1;i <= n+m;i++) dist[i] = graph[c][i];
    marked[c] = 1;
    for(int i = 1;i <= n+m;i++){
        int ks = -1,minV = INF;
        for(int j = 1;j <= n+m;j++){
            if(!marked[j] && dist[j] < minV) ks = j,minV = dist[j];
        }
        if(ks == -1) break;
        marked[ks] = 1;
        for(int j = 1;j <= n+m;j++){
            if(!marked[j] && dist[ks] + graph[ks][j] < dist[j]){
                dist[j] = dist[ks] + graph[ks][j];
            }
        }
    }
    int sum{0},flag{0},minDis = INF;
    for(int i = 1;i <= n;i++){
        sum += dist[i];
        if(dist[i] > md) {flag = 1;break;}
        if(dist[i] < minDis) minDis = dist[i];
    }
    if(!flag){
        Gas gas(c-n,double(minDis),sum * 1.0 / n);
        candidate.push_back(gas);
    }
}
int main() {
    scanf("%d %d %d %d",&n,&m,&k,&md);
    memset(graph,0x3f,sizeof(graph));
    char v[5],w[5];
    while(k--){
        scanf("%s %s %d",v,w,&ds);
        int a = v[0] == 'G' ? n + atoi(v+1) : atoi(v);
        int b = w[0] == 'G' ? n + atoi(w+1) : atoi(w);
        graph[a][b] = graph[b][a] = ds;
    }
    for(int i = 1;i <= m;i++) dijkstra(n + i);
    if(candidate.empty()) printf("No Solution\n");
    else{
        sort(candidate.begin(),candidate.end(),cmp);
        Gas ans= candidate.front();
        printf("G%d\n%.1f %.1f\n",ans.id,ans.minDis,ans.avgDis);
    }
    return 0;
}
