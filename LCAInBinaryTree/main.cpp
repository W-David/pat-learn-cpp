#include <bits/stdc++.h>
using namespace std;
int m,n,inOrderMap[10005],inLis[10005],preLis[10005];
typedef struct node* nodePtr;
map<int,bool> exist;
map<int,nodePtr> pos;
struct node{
    int data;
    nodePtr left,right,parent;
};
nodePtr createBT(int pl,int pe,int il,int ie,nodePtr parent){
    nodePtr nd = new node;
    nd->data = preLis[pl];
    nd->parent = parent;
    if(pl == pe){
        nd->left = nd->right = nullptr;
    }else if(pl + 1 == pe){
        bool lf = preLis[pe] == inLis[il];
        nodePtr cd = new node;
        cd->data = preLis[pe];
        cd->left = cd->right = nullptr;
        cd->parent = nd;
        pos[cd->data] = cd;
        nd->left = lf ? cd : nullptr;
        nd->right = lf ? nullptr : cd;
    }else{
        int p = inOrderMap[nd->data] - il;
        nd->left = createBT(pl+1,pl+p,il,p-1,nd);
        nd->right = createBT(pl+p+1,pe,p+1,ie,nd);
    }
    pos[nd->data] = nd;
    return nd;
}
int main() {
    int a,b;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inLis[i]);
        inOrderMap[inLis[i]] = i;
        exist[inLis[i]] = true;
    }
    for (int i = 0; i < n; i++) scanf("%d", &preLis[i]);
    nodePtr root = createBT(0, n - 1, 0, n - 1, nullptr);
    for(int i = 0;i < m;i++) {
        scanf("%d %d",&a,&b);
        bool ae = exist[a],be = exist[b];
        if(!ae && !be) printf("ERROR: %d and %d are not found.\n",a,b);
        else if(!ae) printf("ERROR: %d is not found.\n",a);
        else if(!be) printf("ERROR: %d is not found.\n",b);
        else{
            vector<int> va,vb;
            for(nodePtr nd = pos[a];nd != nullptr;nd = nd->parent) va.push_back(nd->data);
            for(nodePtr nd = pos[b];nd != nullptr;nd = nd->parent) vb.push_back(nd->data);
            int sa = va.size(),sb = vb.size(),ms = min(sa,sb),s = 1;
            while(s <= ms && va[sa-s] == vb[sb-s]) s++;
            if(s > ms) printf("%d is an ancestor of %d.\n",ms == sa ? a : b,ms == sb ? a : b);
            else printf("LCA of %d and %d is %d.\n",a,b,va[sa-s+1]);
        }
    }
}
