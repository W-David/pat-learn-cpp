#include <bits/stdc++.h>
using namespace std;
int preLis[10005],inLis[10005],m{},n{};
typedef struct node* nodePtr;
struct node{
    int key;
    nodePtr left,right;
};
vector<int> va,vb;
nodePtr createBST(int lp,int rp,int li,int ri){
    int cur = preLis[lp];
    nodePtr nd = new node;
    nd->key = cur;
    if(lp == rp) {
        nd->left = nd->right = nullptr;
    }else if(lp + 1 == rp){
        nodePtr cnd = new node;
        cnd->key = preLis[rp];
        cnd->left = cnd->right = nullptr;
        nd->left = cnd->key < nd->key ? cnd : nullptr;
        nd->right = cnd->key < nd->key  ? nullptr : cnd;
    }else{
        int p = lower_bound(inLis + li,inLis + ri,cur) - (inLis + li);
        nd->left = createBST(lp+1,lp+p,li,p-1);
        nd->right = createBST(lp+p+1,rp,p+1,ri);
    }
    return nd;
}
nodePtr findKey(nodePtr np,int key,vector<int>& vc) {
    if (np == nullptr) return nullptr;
    vc.push_back(np->key);
    if (key < np->key) return findKey(np->left, key,vc);
    else if(key > np->key) return findKey(np->right, key,vc);
    else return np;
}
int main() {
    scanf("%d %d",&m,&n);
    for(int i = 0;i < n;i++) {
        scanf("%d",&preLis[i]);
        inLis[i] = preLis[i];
    }
    sort(inLis,inLis+n);
    nodePtr root = createBST(0,n-1,0,n-1);
    int a,b;
    while(m--){
        scanf("%d %d",&a,&b);
        va.clear(),vb.clear();
        bool ans_a = findKey(root,a,va);
        bool ans_b = findKey(root,b,vb);
        if(!ans_a && !ans_b) printf("ERROR: %d and %d are not found.\n",a,b);
        else if(!ans_a)      printf("ERROR: %d is not found.\n",a);
        else if(!ans_b)      printf("ERROR: %d is not found.\n",b);
        else{
            int sa = va.size(),sb = vb.size(),ms = min(sa,sb),same{};
            while(va[same] == vb[same] && same < ms) same++;
            if(same == ms){
                if(ms == sa) printf("%d is an ancestor of %d.\n",a,b);
                else         printf("%d is an ancestor of %d.\n",b,a);
            }else{
                printf("LCA of %d and %d is %d.\n",a,b,va[same-1]);
            }
        }
    }
    return 0;
}
