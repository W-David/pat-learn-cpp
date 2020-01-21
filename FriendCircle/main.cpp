#include <iostream>
using namespace std;

int size[30005];
int pre[30005];

int find(int v){
    while(v != pre[v]){
        pre[v] = pre[pre[v]];
        v = pre[v];
    }
    return v;
}
bool      connected(int v,int w){
    return find(v) == find(w);
}
void unionNode(int v,int w){
    int vroot = find(v),wroot = find(w);
    if(vroot == wroot) return;
    if(size[vroot] > size[wroot]) {
        pre[wroot] = vroot;
        size[vroot] += size[wroot];
    }else{
        pre[vroot] = wroot;
        size[wroot] += size[vroot];
    }
}
int main() {
    int n,m; cin>>n>>m;
    for(int i = 1;i <= n;i++){
        pre[i] = i;
        size[i] = 1;
    }
    for(int i = 0;i < m;i++){
        int num; cin>>num;
        int first; cin>>first;
        for(int j = 1;j < num;j++){
           int nd; cin>>nd;
           unionNode(first,nd);
        }
    }
    int max = 0;
    for(int i = 1;i <= n;i++){
        if(size[i] > max) max = size[i];
    }
    cout<<max;
    return 0;
}
