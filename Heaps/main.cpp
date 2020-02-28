#include <bits/stdc++.h>
using namespace std;
int lis[1005],num{},n{};
typedef struct node* nodePtr;
bool increase(int a,int b){return lis[a] < lis[b];} // max heap
bool decrease(int a,int b){return lis[a] > lis[b];} // min heap
bool isHeap(bool (*func)(int,int)){
    for(int i = 1;i < n/2;i++) if(func(i,i*2) || func(i,i*2+1)) return false;
    if(n % 2 == 0) return !func(n/2,n);
    return !func(n/2,n-1) && !func(n/2,n);
}
void postOrderTraverse(int i){
    if(i > n) return;
    postOrderTraverse(i*2) ;
    postOrderTraverse(i*2+1);
    printf("%d%c",lis[i],num++ < n-1 ? ' ' : '\n');
}
int main() {
    int m;
    scanf("%d %d",&m,&n);
    while(m--){
        fill(lis+1,lis+1+n,0),num = 0;
        for(int i = 1;i <= n;i++) scanf("%d",&lis[i]);
        if(isHeap(decrease)) printf("Min Heap\n");
        else if(isHeap(increase)) printf("Max Heap\n");
        else printf("Not Heap\n");
        postOrderTraverse(1);
    }
    return 0;
}
