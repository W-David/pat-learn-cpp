#include <bits/stdc++.h>
using namespace std;
int n,m,k,quato[105],choose[40005][5];
vector<int> admitted[105];
struct adm{
    int id,ge,gi,ga;
}adlis[40005],mp[40005];
auto cmp = [](adm &a,adm &b){return a.ga == b.ga ? a.ge >b.ge : a.ga > b.ga;};
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i < m;i++) scanf("%d",&quato[i]);
    for(int i = 0;i < n;i++){
        scanf("%d %d",&adlis[i].ge,&adlis[i].gi);
        adlis[i].id = i,adlis[i].ga = adlis[i].ge + adlis[i].gi;
        mp[i] = adlis[i];
        for(int j = 0;j < k;j++) scanf("%d",&choose[i][j]);
    }
    sort(adlis,adlis+n,cmp);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < k;j++){
            int scid = choose[adlis[i].id][j],lastId = admitted[scid].empty() ? -1 : admitted[scid].back();
            if(quato[scid] > 0 || (adlis[i].ga == mp[lastId].ga && adlis[i].ge == mp[lastId].ge)){
                admitted[scid].push_back(adlis[i].id);
                quato[scid]--;
                break;
            }
        }
    }
    for(int i = 0;i < m;i++){
        if(!admitted[i].empty()){
            sort(admitted[i].begin(),admitted[i].end());
            int size = admitted[i].size();
            printf("%d",admitted[i].front());
            for(int j = 1;j < size;j++) printf(" %d",admitted[i][j]);
        }
        printf("\n");
    }
    return 0;
}