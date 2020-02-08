#include <bits/stdc++.h>
using namespace std;
int lis[1005]{},levelLis[1005]{},n,lx = 0;
void inOrder(int root){
    if(root > n) return;
    inOrder(root * 2);
    levelLis[root] = lis[lx++];
    inOrder(root*2 + 1);
}
int main() {
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&lis[i]);
    sort(lis,lis+n);
    inOrder(1);
    printf("%d",levelLis[1]);
    for(int i = 2;i <= n;i++) printf(" %d",levelLis[i]);
    return 0;
}
