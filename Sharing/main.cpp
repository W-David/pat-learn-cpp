#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int nextPtr[N];
int main() {
    int headA,headB,n,addr,nx,fs = -1;
    char dt;
    scanf("%d %d %d",&headA,&headB,&n);
    while(n--){
        scanf("%d %c %d",&addr,&dt,&nx);
        nextPtr[addr] = nx;
    }
    bool vis[N] = {false};
    for(int i = headA;nextPtr[i] != -1;i = nextPtr[i]) vis[i] = true;
    for(int i = headB;nextPtr[i] != -1;i = nextPtr[i]){
        if(vis[i]) {fs = i;break;}
    }
    if(fs == -1) printf("-1\n");
    else printf("%05d",fs);
    return 0;
}
