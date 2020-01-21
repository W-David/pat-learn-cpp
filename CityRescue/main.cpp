#include <iostream>
#include <stack>
using namespace std;

int city[500][500];
int teams[500];
int pathTeams[500];
int shortPathNum[500];

int visited[500];
int dist[500];
int pre[500];

int INF = 10000;

void dijkstra(int N,int S){
   for(int i = 0;i < N;i++) {
       visited[i] = false;
       dist[i] = city[S][i];
       pre[i] = S;
       pathTeams[i] = i == S ? teams[S] : teams[i] + teams[S];
       shortPathNum[i] = 1;
   }
   visited[S] = true;
   for(int n = 0;n < N;n++){
       int k = -1,min = INF;
       for(int j = 0;j < N;j++){
            if(!visited[j] && dist[j] < min){
                min = dist[j];
                k = j;
            }
       }
       if(k == -1) break;
       visited[k] = true;
       for(int i = 0;i < N;i++){
           if(!visited[i] && dist[k] + city[k][i] <= dist[i]){
               if(dist[k] + city[k][i] < dist[i]){
                   dist[i] = dist[k] + city[k][i];
                   pre[i] = k;
                   pathTeams[i] = pathTeams[k] + teams[i];
                   shortPathNum[i] = shortPathNum[k];
               } else {
                   shortPathNum[i] += shortPathNum[k];
                   if(pathTeams[k] + teams[i] > pathTeams[i]){
                       pathTeams[i] = pathTeams[k] + teams[i];
                       pre[i] = k;
                   }
               }
           }
       }
   }
}

int main() {
    int N,M,S,D;
    cin>>N>>M>>S>>D;
    for(int i = 0;i < N;i++) cin>>teams[i];
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            city[i][j] = i == j ? 0 : INF;
    for(int i = 0;i < M;i++){
        int v,w,len;
        cin>>v>>w>>len;
        city[v][w] = city[w][v] = len;
    }
    dijkstra(N,S);
    cout<<shortPathNum[D]<<" "<<pathTeams[D]<<endl;
    stack<int> path;
    for(int x = D;x != S;x = pre[x]) path.push(x);
    cout<<S;
    while(!path.empty()) {
        cout<<" "<<path.top();
        path.pop();
    }
    return 0;
}
