#include <bits/stdc++.h>
using namespace std;
struct node{
    int left,right;
};
int sz[10],root;
vector<int> inOrderLis;
map<int,node> tree;
int size(int i){
    if(i == -1) return 0;
    return size(tree[i].left) + size(tree[i].right) + 1;
}
void levelTraverse(){
    queue<int> que;
    que.push(root);
    while(!que.empty()){
        int cur = que.front();
        if(cur == root) cout<<cur;
        else cout<<" "<<cur;
        if(tree[cur].right != -1) que.push(tree[cur].right);
        if(tree[cur].left != -1) que.push(tree[cur].left);
        que.pop();
    }
    cout<<endl;
}
void inOrderTraverse(int nd){
    if(nd == -1) return;
    inOrderTraverse(tree[nd].right);
    inOrderLis.push_back(nd);
    inOrderTraverse(tree[nd].left);
}
int main() {
    int n;cin>>n;
    char l,r;
    for(int i = 0;i < n;i++){
        cin>>l>>r;
        node nd;
        nd.left = l == '-' ? -1 : l - '0';
        nd.right = r == '-' ? -1 : r - '0';
        tree[i] = nd;
    }
    for(int i = 0;i < n;i++) sz[i] = size(i);
    int max_v = -1;
    for(int i = 0;i < n;i++) if(sz[i] > max_v) root = i,max_v = sz[i];
    levelTraverse();
    inOrderTraverse(root);
    cout<<inOrderLis.front();
    for(int i = 1;i < n;i++) cout<<" "<<inOrderLis[i];
    return 0;
}
