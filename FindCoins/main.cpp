#include <bits/stdc++.h>
using namespace std;
int n,s,cnt[1505];
int main() {
    cin>>n>>s;
    int c;
    while(n--){
       cin>>c;
       cnt[c]++;
    }
    for(int i = 1;i < s;i++){
        if(i == s-i && cnt[i] <= 1) continue;
        if(cnt[i] && cnt[s-i]){
            cout<<i<<" "<<s-i<<endl;
            return 0;
        }
    }
    cout<<"No Solution"<<endl;
    return 0;
}
