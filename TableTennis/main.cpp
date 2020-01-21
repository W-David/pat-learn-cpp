#include <bits/stdc++.h>
using namespace std;
int open = 8 * 3600,close = 21 * 3600;
struct Player{
    int aTime,pTime,sTime,isVip;
}player[10005];
struct Table{
    int isVip = 0,nextAbleTime = open,count = 0;
}table[105];
auto arriveCmp = [](Player a,Player b){return a.aTime < b.aTime;};
auto serveCmp = [](Player a,Player b){return a.sTime == b.sTime ? a.aTime > b.aTime : a.sTime < b.sTime;};
void formatOutput(int time){printf("%02d:%02d:%02d ",time/3600,time%3600/60,time%60);}
int main() {
    int n,k,M;
    scanf("%d",&n);
    bool vis[n];
    memset(vis,false, sizeof(vis));
    for(int i = 0;i < n;i++){
        int h,m,s;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&player[i].pTime,&player[i].isVip);
        player[i].pTime *= 60;
        player[i].aTime = h * 3600 + m * 60 + s;
        player[i].sTime = min(player[i].sTime,120);
    }
    scanf("%d %d",&k,&M);
    while(M--){
        int vid;
        scanf("%d",&vid);
        table[vid].isVip = 1;
    }
    sort(player,player+n,arriveCmp);
    int i = 0;
    while(i < n){
        if(vis[i]) {i++;continue;}
        int aimTime = table[1].nextAbleTime,aimTable = 1,aimPlayer = i;
        for(int t = 1;t <= k;t++){
            if(table[t].nextAbleTime <= player[i].aTime){
                aimTable = t;
                aimTime = player[i].aTime;
                if(player[i].isVip){
                    for(int tt = t;tt <= k;tt++){
                        if(table[tt].isVip && table[tt].nextAbleTime <= player[i].aTime){
                            aimTable = tt;
                            break;
                        }
                    }
                }
                break;
            }
            if(table[t].nextAbleTime < aimTime){
                aimTime = table[t].nextAbleTime;
                aimTable = t;
            }
        }
        if(table[aimTable].isVip && !player[i].isVip){
            for(int ii = i+1;ii < n;ii++){
                if(player[ii].isVip && player[ii].aTime <= aimTime && !vis[ii]){
                    aimPlayer = ii;break;
                }
            }
        }
        if(aimTime < close){
            table[aimTable].count++;
            table[aimTable].nextAbleTime = aimTime + player[aimPlayer].pTime;
        }
        vis[aimPlayer] = true;
        player[aimPlayer].sTime = aimTime;
        if(aimPlayer == i) i++;
    }
    sort(player,player+n,serveCmp);
    for(int i = 0;i < n;i++){
        if(player[i].sTime >= close) continue;
        formatOutput(player[i].aTime);
        formatOutput(player[i].sTime);
        printf("%.0f\n",round((player[i].sTime - player[i].aTime) / 60.0));
    }
    printf("%d",table[1].count);
    for(int i = 2;i <= k;i++){
        printf(" %d",table[i].count);
    }
    return 0;
}
