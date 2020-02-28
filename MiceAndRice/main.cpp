#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    vector<int> weight,order,Rank;
    cin>>n>>m;
    weight.resize(n),order.resize(n),Rank.resize(n);
    for(int i = 0;i < n;i++) cin>>weight[i];
    for(int i = 0;i < n;i++) cin>>order[i];
    while(order.size() > 1){
        int sz = order.size();
        int r = sz/m + 1;
        if(sz%m) r++;
        vector<int> aux;
        aux.clear();
        for(int i = 0;i < sz;){
            int k = 0,max = -1;
            for(int j = 0;j < m && i < sz;j++,i++){
                int cur = order[i];
                Rank[cur] = r;
                if(weight[cur] > max) max = weight[cur],k = cur;
            }
            aux.push_back(k);
        }
        order = aux;
    }
    Rank[order[0]] = 1;
    cout<<Rank[0];
    for(int i = 1;i < n;i++) cout<<" "<<Rank[i];
    return 0;
}
