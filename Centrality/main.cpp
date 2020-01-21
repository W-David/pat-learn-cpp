#include <bits/stdc++.h>
#define INF 10000
using namespace std;
int main() {
    int n,m;cin>>n>>m;
    int graph[n+1][n+1];
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            graph[i][j] = i == j ? 0 : INF;
        }
    }
    int v,w;
    for(int i = 1;i <= m;i++){
      cin>>v>>w;
      graph[v][w] = graph[w][v] = 1;
    }
    for(int k = 1;k <= n;++k){
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                if(i == j || k == i || k == j) continue;
                graph[i][j] = min(graph[i][k] + graph[k][j],graph[i][j]);
            }
        }
    }
    int k,c;cin>>k;
    while(k--){
       cin>>c;
       int sum = 0;
       for(int i = 1;i <= n;++i) sum += graph[c][i];
       printf("Cc(%d)=%.2f\n",c,(n-1)*1.0 / sum);
    }
    return 0;
}
