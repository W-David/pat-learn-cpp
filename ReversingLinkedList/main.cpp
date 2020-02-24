#include <bits/stdc++.h>
#define max_n 100005
using namespace std;
int dat[max_n],nex[max_n],lisNex[max_n],lisAddr[max_n];
int main() {
    int head,n,k,addr;
    scanf("%d %d %d",&head,&n,&k);
    for(int i = 0;i < n;i++){
        scanf("%d",&addr);
        scanf("%d %d",&dat[addr],&nex[addr]);
    }
    for(int i = head,cnt = 0;i != -1;i = nex[i],cnt++){
        lisNex[cnt] = nex[i];
        lisAddr[cnt] = i;
    }
    head = lisAddr[k-1];
    for(int s = 0;s + k <= n;s += k){
        int en = s + 2 * k <= n ? lisNex[s+2*k-2] : lisNex[s+k-1];
        for(int i = k-1;i > 0;i--){
            nex[lisAddr[s+i]] = lisAddr[s+i-1];
        }
        nex[lisAddr[s]] = en;
    }
    for(int i = head;i != -1;i = nex[i]){
        if(nex[i] == -1) printf("%05d %d -1\n",i,dat[i]);
        else printf("%05d %d %05d\n",i,dat[i],nex[i]);
    }
    return 0;
}
