#include <bits/stdc++.h>
using namespace std;
typedef struct node* nodePtr;
struct node{
    int data;
    nodePtr left,right;
    node(int data):data(data),left(nullptr),right(nullptr){}
};
int height(nodePtr np){
    if(np == nullptr) return 0;
    return max(height(np->left),height(np->right)) + 1;
}
int factor(nodePtr np){
    if(np == nullptr) return 0;
    return height(np->left) - height(np->right);
}
nodePtr rightRotate(nodePtr np){
    nodePtr left = np->left;
    np->left = left->right;
    left->right = np;
    return left;
}
nodePtr leftRotate(nodePtr np){
    nodePtr right = np->right;
    np->right = right->left;
    right->left = np;
    return right;
}
nodePtr leftRightRotate(nodePtr np){
    np->left = leftRotate(np->left);
    return rightRotate(np);
}
nodePtr rightLeftRotate(nodePtr np){
    np->right = rightRotate(np->right);
    return leftRotate(np);
}
nodePtr insert(nodePtr np,int data){
    if(np == nullptr) return new node(data);
    if(data < np->data){
        np->left = insert(np->left,data);
        if(factor(np) == 2) {
            np = data < np->left->data ? rightRotate(np) : leftRightRotate(np);
        }
    }else{
        np->right = insert(np->right,data);
        if(factor(np) == -2){
            np = data > np->right->data ? leftRotate(np) : rightLeftRotate(np);
        }
    }
    return np;
}
void levelTraverse(nodePtr root){
    queue<nodePtr> que;
    que.push(root);
    while(!que.empty()){
        nodePtr np = que.front();
        printf("%s%d",(np == root ? "" : " "),np->data);
        if(np->left) que.push(np->left);
        if(np->right) que.push(np->right);
        que.pop();
    }
}
bool isComplete(nodePtr root){
    queue<nodePtr> que;
    que.push(root);
    while(que.front()){
        que.push(que.front()->left);
        que.push(que.front()->right);
        que.pop();
    }
    while(!que.empty()){
        if(que.front()) return false;
        que.pop();
    }
    return true;
}
int main() {
    int n,data;
    scanf("%d",&n);
    nodePtr root{};
    for(int i = 0;i < n;i++){
        scanf("%d",&data);
        root = insert(root,data);
    }
    levelTraverse(root);
    string ans = isComplete(root) ? "YES" : "NO";
    printf("\n%s",ans.c_str());
    return 0;
}
