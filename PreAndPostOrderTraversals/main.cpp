#include <bits/stdc++.h>
using namespace std;
const int max_n = 35;
int preLis[max_n],postLis[max_n];
int ans = 1,num = 0,n;
map<int,int> pos;
typedef struct node* nodePtr;
struct node{
    int data;
    nodePtr left,right;
};
nodePtr createBT(int prel,int prer,int postl,int postr){
    nodePtr nd = new node;
    nd->data = preLis[prel];
    if(prel == prer){
        nd->left = nd->right = nullptr;
    }else if(prel + 1 == prer){
        ans = 0;
        nd->left = createBT(prel+1,prer,postl,postl);
        nd->right = nullptr;
    }else{
        int p = pos[preLis[prel+1]] - postl;
        nd->left = createBT(prel+1,prel+1+p,postl,postl+p);
        nd->right = createBT(prel+1+p+1,prer,postl+p+1,postr-1);
    }
    return nd;
}
void inOrderTraverse(nodePtr nd){
    if(nd == nullptr) return;
    inOrderTraverse(nd->left);
    printf("%d%c",nd->data,(num++ < n-1 ? ' ' : '\n')) ;
    inOrderTraverse(nd->right);
}
int main(){
    scanf("%d,",&n);
    for(int i = 0;i < n;i++) scanf("%d",&preLis[i]);
    for(int i = 0;i < n;i++) {
        scanf("%d",&postLis[i]);
        pos[postLis[i]] = i;
    }
    nodePtr root = createBT(0,n-1,0,n-1);
    printf("%s\n",ans ? "Yes" : "No");
    inOrderTraverse(root);
    return 0;
}