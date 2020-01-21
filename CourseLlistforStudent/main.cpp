#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,vector<int>> mp;
int main() {
    int n,k;cin>>n>>k;
    while(k--){
        int cid,cnt;cin>>cid>>cnt;
        while(cnt--){
            string name;cin>>name;
            mp[name].push_back(cid);
        }
    }
    while(n--){
        string name;cin>>name;
        cout<<name<<" "<<mp[name].size();
        sort(mp[name].begin(),mp[name].end());
        for(auto &it: mp[name]){
            cout<<" "<<it;
        }
        cout<<endl;
    }
    return 0;
}
