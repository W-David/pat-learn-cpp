#include <bits/stdc++.h> //这个库包了目前c++所有的头文件。
#define INF 0x3f3f3f3f  //设置无穷大
using namespace std;
int n,m,s,d;
struct node{
    int dis,cos;
}city[505][505];//结构体存储路径，花费.
bool vis[505];// 节点是否被访问过
int cost[505],dist[505],path[505];//记录从起点到每个节点的花费，路径长度,path数组以前驱记录的形式记忆路径。
int main() {
    scanf("%d %d %d %d",&n,&m,&s,&d);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            city[i][j].dis = i == j ? 0 : INF;
            city[i][j].cos = i == j ? 0 : INF;
        }
    }//初始化每个节点的数据，INF即初始每个节点之间都是不可达的，花费也无穷大。
    int w,v,dis,cos;
    for(int i = 0;i < m;i++){
        scanf("%d %d %d %d",&w,&v,&dis,&cos);
        city[w][v].dis = city[v][w].dis = dis;
        city[w][v].cos = city[v][w].cos = cos;
    }//读入数据
    for(int i = 0;i < n;i++){
        dist[i] = city[s][i].dis;
        cost[i] = city[s][i].cos;
        path[i] = s;
        vis[i] = false;
    }//cost,dist都以起点数据做初始化，初始所有节点前驱节点都是起点。
    vis[s] = true;
    for(int i = 0;i < n;i++){
        int k = -1,min = INF;
        for(int j = 0;j < n;j++){
            if(!vis[j] && dist[j] < min){
                k = j;
                min = dist[j];
            }
        }//dijkstra算法的正常步骤，先找到一条连接到未访问节点的最短路径。
        if(k == -1) break;
        vis[k] = true;//将找到的这个节点设为已访问。
        for(int j = 0;j < n;j++){
            if(!vis[j] && dist[k] + city[k][j].dis <= dist[j]){//dijkstra里的“放松”过程，以找到的节点为中继，更新到其他节点的路径。
                if(dist[k] + city[k][j].dis < dist[j]){
                    dist[j] = dist[k] + city[k][j].dis;//放松路径
                    path[j] = k;//记录路径
                    cost[j] = cost[k] + city[k][j].cos;
                }else if(cost[k] + city[k][j].cos < cost[j]){//如果路径长度相同但是花费更低，更新花费和路径。
                    cost[j] = cost[k] + city[k][j].cos;
                    path[j] = k;//更新路径
                }
            }
        }
    }
    stack<int> sta;
    for(int i = d;i != s;i = path[i]) sta.push(i);//使用栈实现路径回溯。
    printf("%d",s);
    while(!sta.empty()) printf(" %d",sta.top()),sta.pop();
    printf(" %d %d\n",dist[d],cost[d]);
    return 0;
}
