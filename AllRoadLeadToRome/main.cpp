#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxN 205
using namespace std;
map<string,int> indexOf;
map<int,string> nameOf;
int happiness[maxN];
int graph[maxN][maxN];
int marked[maxN],minCost[maxN],pre[maxN];
int maxHappy[maxN]{-1},minCnt[maxN]{INF},pathCnt[maxN]{0};
int main() {
    int n,k,happy,cost;
    char start[5],name[5],other[5];
    memset(graph,0x3f,sizeof(graph));
    scanf("%d %d %s",&n,&k,start);
    for(int i = 1;i < n;i++) {
        scanf("%s %d",name,&happy);
        happiness[i] = happy;
        indexOf[name] = i;
        nameOf[i] = name;
    }
    for(int i = 0 ;i < k;i++){
        scanf("%s %s %d",name,other,&cost);
        int v = indexOf[name],w = indexOf[other];
        graph[v][w] = graph[w][v] = cost;
    }
    //Dijkstra
    int endId = indexOf["ROM"];
    for(int i = 1;i < n;i++) minCost[i] = graph[0][i];
    maxHappy[0] = minCnt[0] = 0;
    pathCnt[0] = 1;
    for(int i = 0;i < n;i++){
        int ks = -1,min = INF;
        for(int j = 0;j < n;j++){
            if(!marked[j] && minCost[j] < min) ks = j,min = minCost[j];
        }
        if(ks == -1) break;
        marked[ks] = 1;
        for(int j = 0;j < n;j++){
            if(marked[j]) continue;
            if(minCost[ks] + graph[ks][j] < minCost[j]){
                pre[j] = ks;
                minCnt[j] = minCnt[ks] + 1;
                pathCnt[j] = pathCnt[ks];
                minCost[j] = minCost[ks] + graph[ks][j];
                maxHappy[j] = maxHappy[ks] + happiness[j];
            }else if(minCost[ks] + graph[ks][j]  == minCost[j]){
                pathCnt[j] += pathCnt[ks];
                if(maxHappy[ks] + happiness[j]> maxHappy[j]){
                    pre[j] = ks;
                    minCnt[j] = minCnt[ks] + 1;
                    maxHappy[j] = maxHappy[ks] + happiness[j];
                }else if(maxHappy[ks] == maxHappy[pre[j]]){
                    if(minCnt[ks]  + 1 < minCnt[j]){
                        pre[j] = ks;
                        minCnt[j] = minCnt[ks] + 1;
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n",pathCnt[endId],minCost[endId],maxHappy[endId],maxHappy[endId]/minCnt[endId]);
    stack<int> path;
    for(int x = endId;x != 0;x = pre[x]) path.push(x);
    printf("%s",start);
    while(!path.empty()) printf("->%s",nameOf[path.top()].c_str()),path.pop();
    return 0;
}
