#include <bits/stdc++.h>
using namespace std;
int lt[100],rt[100],lis[100],mp[100];
queue<int> que;
static int cnt = 0;
void inOrder(int node){
    if(node == -1) return;
    inOrder(lt[node]);
    mp[node] = lis[cnt++];
    inOrder(rt[node]);
}
void levelOrder(int root){
    que.push(root);
    while(!que.empty()){
        int it = que.front();
        cout<<(it == root ? "" : " ")<<mp[it];
        if(lt[it] != -1) que.push(lt[it]);
        if(rt[it] != -1) que.push(rt[it]);
        que.pop();
    }
}
int main() {
    int n; cin>>n;
    for(int i = 0;i < n;i++) cin>>lt[i]>>rt[i];
    for(int i = 0;i < n;i++) cin>>lis[i];
    sort(lis,lis+n);
    inOrder(0);
    levelOrder(0);
    return 0;
}
