#include <iostream>
#include <map>
using namespace std;

map<int,int> mp;

int main(){
    int n; cin>>n;
    for(int i = 0;i < n;i++){
        int c;cin>>c;
        map<int,int>::iterator it = mp.find(c);
        if(it == mp.end()) mp[c] = 1;
        else (it->second)++;
    }
    map<int,int>::iterator iter = mp.begin();
    while(iter != mp.end()){
        cout<<iter->first<<":"<<iter->second<<endl;
        iter++;
    }
}