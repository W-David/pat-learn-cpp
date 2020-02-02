#include <bits/stdc++.h>
using namespace std;
int w,weight[100],marked[100],parent[100];
map<int,vector<int>> nonLeafNode;
auto cmp = [](int a,int b){return weight[a] > weight[b];};
auto isLeaf =[](int node){return nonLeafNode.find(node) == nonLeafNode.end();};
void dfs(int node,int sum){
    marked[node] = 1;
    sum += weight[node];
    if((sum < w && isLeaf(node)) || sum > w) return;
    if(sum == w && isLeaf(node)){
        stack<int> s;
        for(int i = node;i != 0;i = parent[i]) s.push(i);
        cout<<weight[0];
        while(!s.empty()) cout<<" "<<weight[s.top()],s.pop();
        cout<<endl;
        return;
    }
    for(auto it : nonLeafNode[node]){
        if(!marked[it]) dfs(it,sum);
    }
    marked[node] = 0;
}
int main() {
    int n,m,node,cnt;
    cin>>n>>m>>w;
    for(int i = 0;i < n;i++) cin>>weight[i];
    while(m--){
        cin>>node>>cnt;
        vector<int> vc(cnt);
        for(int i = 0;i < cnt;i++) {
            cin>>vc[i];
            parent[vc[i]] = node;
        }
        sort(vc.begin(),vc.end(),cmp);
        nonLeafNode[node] = vc;
    }
    dfs(0,0);
    return 0;
}
