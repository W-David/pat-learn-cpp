#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int max_n = 505;
int n,pos,dis;
struct street{int len{INF},time{INF};};
street Map[max_n][max_n];
int disVis[max_n],teVis[max_n],dist[max_n]{INF},te[max_n]{INF},disPre[max_n],tePre[max_n],sht[max_n],cnt[max_n];
void dijkstra(){
    for(int i = 0;i < n;i++) {
        dist[i] = Map[pos][i].len;
        sht[i] = te[i] = Map[pos][i].time;
        disPre[i] = tePre[i] = pos;
    }
    teVis[pos] = disVis[pos] = 1;
    for(int c = 0;c < n;c++){
        int md = -1,mt = -1,minD = INF,minT = INF;
        for(int i = 0;i < n;i++){
            if(!disVis[i] && dist[i] < minD){md = i,minD = dist[i];}
            if(!teVis[i] && te[i] < minT){mt = i,minT = te[i];}
        }
        if(md == -1 && mt == -1) break;
        else if(md == -1) teVis[mt] = 1;
        else if(mt == -1) disVis[md] = 1;
        else disVis[md] = teVis[mt] = 1;
        for(int i = 0;i < n;i++){
            if(disVis[i] && teVis[i]) continue;
            if(!disVis[i] && dist[md] + Map[md][i].len <= dist[i]){
                if(dist[md] + Map[md][i].len < dist[i]){
                    disPre[i] = md;
                    sht[i] = sht[md] + Map[md][i].time;
                    dist[i] = dist[md] + Map[md][i].len;
                }else if(sht[md] + Map[md][i].time < sht[i]){
                    disPre[i] = md;
                    sht[i] = sht[md] + Map[md][i].time;
                }
            }
            if(!teVis[i] && te[mt] + Map[mt][i].time <= te[i]){
                if(te[mt] + Map[mt][i].time < te[i]){
                    tePre[i] = mt;
                    cnt[i] = cnt[mt] + 1;
                    te[i] = te[mt] + Map[mt][i].time;
                }else if(cnt[mt] + 1 < cnt[i]){
                    tePre[i] = mt;
                    cnt[i] = cnt[mt] + 1;
                }
            }
        }

    }
}
int main(){
    int m,v,w,one;
    scanf("%d %d",&n,&m);
    while(m--){
        street ste;
        scanf("%d %d %d %d %d",&v,&w,&one,&ste.len,&ste.time);
        if(one) Map[v][w] = ste;
        else Map[v][w] = Map[w][v] = ste;
    }
    scanf("%d %d",&pos,&dis);
    dijkstra();
    stack<int> Distance,Time;
    for(int i = dis;i != pos;i = disPre[i]) Distance.push(i);
    for(int i = dis;i != pos;i = tePre[i]) Time.push(i);
    if(Distance == Time){
        printf("Distance = %d; Time = %d: %d",dist[dis],te[dis],pos);
        while(!Distance.empty()) printf(" -> %d",Distance.top()),Distance.pop();
    }else{
        printf("Distance = %d: %d",dist[dis],pos);
        while(!Distance.empty()) printf(" -> %d",Distance.top()),Distance.pop();
        printf("\nTime = %d: %d",te[dis],pos);
        while(!Time.empty()) printf(" -> %d",Time.top()),Time.pop();
    }
    return 0;
}