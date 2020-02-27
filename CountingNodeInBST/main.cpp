#include <bits/stdc++.h>
using namespace std;
typedef struct node* nodePtr;
int maxDepth = -1,num[1005]{0};
struct node{
    int data,depth;
    nodePtr left,right;
    node(int data,int depth):data(data),left(nullptr),right(nullptr),depth(depth){}
};
nodePtr insert(nodePtr nd,int depth,int data){
    if(nd == nullptr) {
        num[depth]++;
        maxDepth = max(maxDepth,depth);
        return new node(data,depth);
    }
    if(data < nd->data) nd->left = insert(nd->left,nd->depth+1,data);
    else nd->right = insert(nd->right,nd->depth+1,data);
    return nd;
}
int main() {
    int n,c;
    scanf("%d",&n);
    nodePtr root = nullptr;
    for(int i = 0;i < n;i++) {
        scanf("%d",&c);
        root = insert(root,1,c);
    }
    int n1 = num[maxDepth],n2 = num[maxDepth-1];
    printf("%d + %d = %d\n",n1,n2,n1+n2);
    return 0;
}

