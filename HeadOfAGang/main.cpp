#include <bits/stdc++.h>
using namespace std;
vector<string> name;
map<string,int> index;
int gang[1005][1005];
int weightSum = 0,maxWeight = -1,head = -1,cnt = 0;
int weight[1005] = {0},vis[1005] = {0};
void save(const string& s){
    auto it = index.find(s);
    if(it == index.end()){
        name.push_back(s);
        index[s] = name.size() - 1;
    }
}
void dfs(int v){
    cnt++;
    vis[v] = 1;
    if(weight[v] > maxWeight){
        maxWeight = weight[v];
        head = v;
    }
    for(int w = 0;w < name.size();w++){
        if(!gang[v][w]) continue;
        weightSum += gang[v][w];
        gang[v][w] = gang[w][v] = 0;
        if(!vis[w]) dfs(w);
    }
}
int main() {
    int n,limit,len{};
    cin>>n>>limit;
    string nameA,nameB;
    while(n--){
        cin>>nameA>>nameB>>len;
        save(nameA),save(nameB);
        int v = index[nameA],w = index[nameB];
        weight[v] += len,weight[w] += len;
        gang[v][w] += len,gang[w][v] += len;
    }
    vector<pair<string,int>> vc;
    for(int i = 0;i < name.size();i++){
        weightSum = 0,maxWeight = -1,head = -1,cnt = 0;
        if(!vis[i]) dfs(i);
        if(cnt > 2 && weightSum > limit) vc.emplace_back(name[head],cnt);
    }
    sort(vc.begin(),vc.end());
    cout<<vc.size()<<endl;
    for(auto &it:vc) cout<<it.first<<" "<<it.second<<endl;
    return 0;
}
