#include <bits/stdc++.h>
using namespace std;
int dt[100005],nx[100005],pre[100005],mp[10005];
int main() {
    int head,n,addr,rd,rn;
    int first{1},rmHead{},rmLast{},nt{};
    scanf("%d %d",&head,&n);
    for(int i = 0;i < n;i++) {
        scanf("%d %d %d",&addr,&rd,&rn);
        dt[addr] = rd,nx[addr] = rn,pre[rn] = addr;
    }
    for(int i = head;i != -1;i = nt){
        nt = nx[i];
        if(!mp[abs(dt[i])]) mp[abs(dt[i])] = 1;
        else {
            nx[pre[i]] = nx[i];
            if(first) {
                first = 0,rmHead = rmLast = i;
                nx[rmHead] = -1;
            }else{
                nx[rmLast] = i;
                rmLast = i;
                nx[i] = -1;
            }
        }
    }
    for(int i = head;i != -1;i = nx[i]){
        if(nx[i] == -1) printf("%05d %d -1\n",i,dt[i]);
        else printf("%05d %d %05d\n",i,dt[i],nx[i]);
    }
    for(int i = rmHead;i != -1;i = nx[i]){
        if(nx[i] == -1) printf("%05d %d -1\n",i,dt[i]);
        else printf("%05d %d %05d\n",i,dt[i],nx[i]);
    }
    return 0;
}
