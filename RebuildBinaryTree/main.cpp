#include <bits/stdc++.h>
using namespace std;
int dfs(char* pre,char* in,int n){
    if(n == 0) return 0;
    for(int i = 0;i < n;++i){
        if(in[i] == pre[0]){
            return max(dfs(pre+1,in,i),dfs(pre+i+1,in+i+1,n-i-1)) + 1;
        }
    }
}
int main(){
    int n;cin>>n;
    char pre[55],in[55];
    cin>>pre>>in;
    int depth = dfs(pre,in,n);
    cout<<depth<<endl;
    return 0;
}
