#include <bits/stdc++.h>
using namespace std;
vector<int> preList,mirrorPreList,postList,mirrorPostList;
int n;
struct Node{
    int data;
    Node *left,*right;
    explicit Node(int data){this->data = data;this->right = nullptr;this->left = nullptr;}
};
void insert(Node* &root,int i){
    if(root == nullptr) {
        Node *node = new Node(i);
        root = node;
    }
    else if(i < root->data) insert(root->left,i);
    else insert(root->right,i);
}
void preOrder(Node *node){
    if(node == nullptr) return;
    preList.push_back(node->data);
    preOrder(node->left);
    preOrder(node->right);
}
void mirrorPreOrder(Node *node){
    if(node == nullptr) return;
    mirrorPreList.push_back(node->data);
    mirrorPreOrder(node->right);
    mirrorPreOrder(node->left);
}
void postOrder(Node *root){
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    postList.push_back(root->data);
}
void mirrorPostOrder(Node *root){
    if(root == nullptr) return;
    mirrorPostOrder(root->right);
    mirrorPostOrder(root->left);
    mirrorPostList.push_back(root->data);
}
void output(vector<int> vc){
    cout<<vc.front();
    for(int i =1;i < n;i++) cout<<" "<<vc[i];
}
int main() {
    cin>>n;
    vector<int> lis(n);
    for(int i = 0;i < n;i++) cin>>lis[i];
    Node *root = nullptr;
    for(int i = 0;i < n;i++) insert(root,lis[i]);
    preOrder(root),mirrorPreOrder(root);
    if(lis == preList){
        cout<<"YES"<<endl;
        postOrder(root);
        output(postList);
    }else if(lis == mirrorPreList){
        cout<<"YES"<<endl;
        mirrorPostOrder(root);
        output(mirrorPostList);
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
