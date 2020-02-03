#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main() {
    int m,n,c;
    cin>>m>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&c);
            mp[c]++;
        }
    }
    int max = -1,ans = 0;
    for(auto &it: mp){
        if(it.second > max) {
            ans = it.first;
            max = it.second;
        }
    }
    printf("%d\n",ans);
    return 0;
}
