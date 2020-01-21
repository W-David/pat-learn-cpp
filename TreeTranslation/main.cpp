#include <iostream>
#include <string>
#define Null -1
#define MaxSize 10
using namespace std;

struct TreeNode{
    char data;
    int left,right;
}TreeOne[MaxSize],TreeTwo[MaxSize];

int createTree(struct TreeNode treeNode[]){
    int n; cin>>n;
    if(n == 0) return Null;
    bool visited[n];
    for(int i = 0;i < n;i++){
        cin>>treeNode[i].data;
        char left,right; cin>>left>>right;
        if(left == '-') treeNode[i].left = Null;
        else {
            treeNode[i].left = left - '0';
            visited[treeNode[i].left] = true;
        }
        if(right == '-') treeNode[i].right = Null;
        else {
           treeNode[i].right = right - '0';
           visited[treeNode[i].right] = true;
        }
    }
    int root = 0;
    while(visited[root]) root++;
    return root;
}
bool isTranslation(int nodeOne,int nodeTwo){
    TreeNode inodeOne = TreeOne[nodeOne],inodeTwo = TreeOne[nodeTwo];
    if(nodeOne == Null && nodeTwo == Null) return true;
    if(nodeOne == Null || nodeTwo == Null) return false;
    if(inodeOne.data != inodeTwo.data) return false;
    return (isTranslation(inodeOne.left,inodeTwo.left) && isTranslation(inodeOne.right,inodeTwo.right))
           || (isTranslation(inodeOne.left,inodeTwo.right) && isTranslation(inodeOne.right,inodeTwo.left));
}
int main() {
    int rootOne = createTree(TreeOne);
    int rootTwo = createTree(TreeTwo);
    string judge = isTranslation(rootOne,rootTwo) ? "Yes" : "No";
    cout<<judge<<endl;
    return 0;
}
