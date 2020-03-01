#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct user{
    int rk{},id{},cnt{},score{},sub{0},allow{0};
    int problem[6]{-1,-1,-1,-1,-1,-1};
}lis[10005];
int n,k,m,profect[6];
bool cmp(user a,user b){
    return a.score == b.score ? a.cnt == b.cnt ? a.id < b.id : a.cnt > b.cnt : a.score > b.score;
}
void outputScore(user u){
    for(int i = 1;i <= k;i++){
        int cur = u.problem[i];
        if(cur == -1) printf(" -");
        else printf(" %d",cur);
    }
    printf("\n");
}
int main() {
    scanf("%d %d %d",&n,&k,&m);
    for(int i = 1;i <= k;i++) scanf("%d",&profect[i]);
    for(int i = 0;i < m;i++){
        int id,pid,pscore;
        scanf("%d %d %d",&id,&pid,&pscore);
//        pscore = pscore < 0 ? 0 : pscore;
        if(!lis[id].sub) lis[id].id = id,lis[id].sub = 1;
        lis[id].problem[pid] = max(lis[id].problem[pid],pscore);
        if(pscore == profect[pid]) lis[id].cnt++;
    }
    for(int i = 1;i <= n;i++){
        for(int pid = 1;pid <= k;pid++) lis[i].score += lis[i].problem[pid] < 0 ? 0 : lis[i].problem[pid];
    }
    sort(lis+1,lis+n+1,cmp);
    printf("1 %05d %d",lis[1].id,lis[1].score);
    lis[1].rk = 1;
    outputScore(lis[1]);
    for(int i = 2;i <= n;i++){
        if(!lis[i].sub) continue;
        if(lis[i].score == lis[i-1].score) lis[i].rk = lis[i-1].rk;
        else lis[i].rk = i;
        printf("%d %05d %d",lis[i].rk,lis[i].id,lis[i].score);
        outputScore(lis[i]);
    }
    return 0;
}
