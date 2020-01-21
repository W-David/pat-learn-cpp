#include <iostream>
using namespace std;

int maze[1001][1001];
bool marked[1001];
int path[2005];
int n,c;
int count;

void explore(int v){
   marked[v]  = true;
   count++;
   for(int w = 1;w <= n;w++){
       if(!marked[w] && maze[v][w]){
           path[c++] = w;
           explore(w);
           path[c++] = v;
       }
   }
}

int main() {
    int m,s;
    cin>>n>>m>>s;
    for(int i = 0;i < m;i++){
        int v,w;
        cin>>v>>w;
        maze[v][w] = maze[w][v] = true;
    }
    explore(s);
    cout<<s;
    for(int i = 0;path[i] != 0;i++) cout<<" "<<path[i];
    if(count < n) cout<<" "<<0;
    return 0;
}
