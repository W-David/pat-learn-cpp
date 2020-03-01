#include <bits/stdc++.h>
using namespace std;
const int max_n = 20;
int lchild[max_n],rchild[max_n],parent[max_n]{0},levelLis[max_n];
queue<int> que;
int main() {
    int n,root{},k{},f{1};
    string l,r;
    cin>>n;
    memset(parent,-1,sizeof(parent));
    for(int i = 0;i < n;i++){
        cin>>l>>r;
        lchild[i] = l == "-" ? -1 : stoi(l);
        rchild[i] = r == "-" ? -1 : stoi(r);
        parent[lchild[i]] = parent[rchild[i]] = i;
    }
    for(root = 0;parent[root] != -1;root = parent[root]);
    que.push(root);
    while(!que.empty()){
        int cur = que.front();
        if(cur == -1){
            if(k < n) f = 0;
            break;
        }
        levelLis[k++] = cur;
        que.push(lchild[cur]);
        que.push(rchild[cur]);
        que.pop();
    }
    if(f) printf("YES %d\n",levelLis[n-1]);
    else printf("NO %d\n",root);
    return 0;
}
