#include <bits/stdc++.h>
using namespace std;
typedef struct node *nodePtr;
struct node{
    int val;
    nodePtr left{},right{};
    explicit node(int val){this->val =val;}
};
int getHeight(nodePtr np){
    if(np == nullptr) return 0;
    return max(getHeight(np->left),getHeight(np->right)) + 1;
}
int getFactor(nodePtr np){
    if(np == nullptr) return 0;
    return getHeight(np->left) - getHeight(np->right);
}
nodePtr rotateRight(nodePtr np){
    nodePtr left = np->left;
    np->left = left->right;
    left->right = np;
    return left;
}
nodePtr rotateLeft(nodePtr np){
    nodePtr right = np->right;
    np->right = right->left;
    right->left = np;
    return right;
}
nodePtr rotateLeftRight(nodePtr np){
    np->left = rotateLeft(np->left);
    return rotateRight(np);
}
nodePtr rotateRightLeft(nodePtr np){
    np->right = rotateRight(np->right);
    return rotateLeft(np);
}
nodePtr insert(int val,nodePtr np){
    if(np == nullptr) return new node(val);
    if(val < np->val) {
        np->left = insert(val,np->left);
        if(getFactor(np) == 2) np = val < np->left->val ? rotateRight(np) : rotateLeftRight(np);
    }else{
        np->right = insert(val,np->right);
        if(getFactor(np) == -2) np = val > np->right->val ? rotateLeft(np) : rotateRightLeft(np);
    }
    return np;
}
int main() {
    int n,v;cin>>n;
    nodePtr root{};
    for(int i = 0;i < n;i++) {
        cin>>v;
        root = insert(v,root);
    }
    cout<<root->val<<endl;
    return 0;
}
