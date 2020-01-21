#include <iostream>
#define INF 0x3f3f3f3f;
using namespace std;

struct Edge{
    int len,cost;
};
Edge edges[1000][1000];
bool marked[505];
int dist[505];
int costs[505];

void init(int n,int s){
    for(int i = 0;i < n;i++){
        marked[i] = false;
        dist[i] = edges[s][i].len;
        costs[i] = edges[s][i].cost;
    }
}

void dijkstra(int n,int s){
    marked[s] = true;
    for(int c = 0;c < n;c++){
        int k = -1,min = INF;
        for(int j = 0;j < n;j++){
            if(!marked[j] && dist[j] < min){
                k = j; min = dist[j];
            }
        }
        if(k == -1) break;
        marked[k] = true;
        for(int i = 0;i < n;i++){
            if(!marked[i] && dist[k] + edges[k][i].len <= dist[i]){
                if(dist[k] + edges[k][i].len < dist[i]){
                    dist[i] = dist[k] + edges[k][i].len;
                    costs[i] = costs[k] + edges[k][i].cost;
                } else if(costs[k] + edges[k][i].cost < costs[i]){
                    costs[i] = costs[k] + edges[k][i].cost;
                }
            }
        }
    }
}
int main() {
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            edges[i][j].len = edges[i][j].cost
            = i == j ? 0 : INF;
    for(int i = 0;i < m;i++){
        int v,w,len,cost;
        cin>>v>>w>>len>>cost;
        edges[v][w].len = edges[w][v].len = len;
        edges[v][w].cost = edges[w][v].cost = cost;
    }
    init(n,s);
    dijkstra(n,s);
    cout<<dist[d]<<" "<<costs[d]<<endl;
    return 0;
}
