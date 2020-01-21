#include <bits/stdc++.h>
using namespace std;
vector<string> name;
map<string,int> nameIndex;
const static int maxn = 2020;
int gang[maxn][maxn];
int weightSum = 0,maxWeight = 0,head = 0,cnt = 0;
int weight[maxn] = {0},vis[maxn] = {0};
void save(const string& s){
    auto it = nameIndex.find(s);
    if(it == nameIndex.end()){
        name.push_back(s);
        nameIndex[s] = name.size() - 1;
    }
}
void dfs(int v){
    cnt++;
    vis[v] = 1;
    for(int w = 0;w < name.size();w++){
        if(!gang[v][w]) continue;
        weightSum += gang[v][w];
        gang[v][w] = gang[w][v] = 0;
        if(!vis[w]) dfs(w);
    }
    if(weight[v] > maxWeight){
        maxWeight = weight[v];
        head = v;
    }
}
int main() {
    int n,limit,len{};
    cin>>n>>limit;
    string nameA,nameB;
    while(n--){
        cin>>nameA>>nameB>>len;
        save(nameA),save(nameB);
        int v = nameIndex[nameA],w = nameIndex[nameB];
        weight[v] += len,weight[w] += len;
        gang[v][w] += len,gang[w][v] += len;
    }
    vector<pair<string,int> > vc;
    for(int i = 0;i < name.size();i++){
        weightSum = maxWeight = head = cnt = 0;
        if(!vis[i]) dfs(i);
        if(cnt > 2 && weightSum > limit) vc.emplace_back(name[head],cnt);
    }
    sort(vc.begin(),vc.end());
    cout<<vc.size()<<endl;
    for(auto &it:vc) cout<<it.first<<" "<<it.second<<endl;
    return 0;
}
