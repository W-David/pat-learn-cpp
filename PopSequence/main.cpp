#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int main(){
    int m,n,k,c;
    cin>>m>>n>>k;
    bool ans;
    int p;
    while(k--){
        p = 1;ans = true;
        while(!s.empty()) s.pop();
        for(int i = 0;i < n;i++){
            cin>>c;
            while(s.size() <= m && ans){
                if(s.empty() || c != s.top()) s.push(p++);
                else {s.pop();break;}
            }
            if(s.size() > m) ans = false;
        }
        string res = ans ? "YES" : "NO";
        cout<<res<<endl;
    }
    return 0;
}