#include <iostream>
#define INF 1000;
using namespace std;
int n,cost[105][105],visited[105],minCost[105];
int main(){
    cin>>n;
    int m = (n * (n-1)) / 2;
    int v,w,c,cn;
//    for(int i = 1;i <= n;i++) cost[i][i] = 0;
    for(int i = 0;i < m;i++){
        cin>>v>>w>>c>>cn;
        cost[v][w] = cost[w][v] = cn ? 0 : c;
    }
    visited[1] = 1;
    for(int i = 1;i <= n;i++) minCost[i] = cost[1][i];
    int totalMinCost = 0;
    for(int t = 1;t < n;t++){
        int k = -1,min = INF;
        for(int j = 1;j <= n;j++){
            if(!visited[j] && minCost[j] < min) k = j, min = minCost[j];
        }
        if(k == -1) break;
        visited[k] = 1;
        totalMinCost += min;
        for(int i = 1;i <= n;i++){
            if(!visited[i] && cost[k][i] < minCost[i]) minCost[i] = cost[k][i];
        }
    }
    cout<<totalMinCost<<endl;
}