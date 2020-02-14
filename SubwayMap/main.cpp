#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
const int max_n = 10000;
using namespace std;
struct station{int status{INF},line{0};};
station net[max_n][max_n];
int dist[max_n],pre[max_n],marked[max_n];
void dijkstra(int start){
    fill(pre,pre+max_n,start);
    fill(marked,marked+max_n,0);
    for(int i = 0;i < max_n;i++) dist[i] = net[start][i].status;
    marked[start]  = 1;
    for(int c = 0;c < max_n;c++){
        int k = -1,m = INF;
        for(int i = 0;i < max_n;i++){
            if(!marked[i] && dist[i] < m) k = i,m = dist[i];
        }
        marked[k] = 1;
        for(int i = 0;i < max_n;i++){
            if(!marked[i]) {
                pre[i] = k;
                dist[i] = min(dist[i],dist[k] + net[k][i].status);
            }
        }
    }
}
int main() {
    int n, m, c, start, end;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        int cur[c];
        for (int j = 0; j < c; j++) scanf("%d", &cur[i]);
        for (int j = 0; j < c - 1; j++) {
            net[cur[j]][cur[j + 1]].status = net[cur[j + 1]][cur[j]].status = 1;
            net[cur[j]][cur[j + 1]].line = net[cur[j + 1]][cur[j]].line = i;
        }
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d",&start,&end);
        dijkstra(start);
        vector<int> vc;
        for(int i = end;i != start;i = pre[i]) vc.push_back(i);
        int sz = vc.size();
        printf("%d\n",sz);
        vc.push_back(start);
//        for(int i = sz;i > 0;i--) printf("%04d ",vc[i]);
        int i = sz;
        while(i > 0){
            int sl = i,curLine = net[vc[sl]][vc[sl-1]].line;
            while(i > 0 && net[vc[i]][vc[i-1]].line == curLine) i--;
            printf("Take Line#%d from %04d to %04d\n",sl,i);
        }
    }
    return 0;
}
