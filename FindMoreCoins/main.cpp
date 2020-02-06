#include <bits/stdc++.h>
using namespace std;
int lis[10005],n,k;
vector<int> vc;
bool dfs(int i,int sum){
    vc.push_back(lis[i]);
    if(sum > k) vc.pop_back();
    if(i == n) return sum == k;
    if(dfs(i+1,sum)) return true;
    return dfs(i+1, sum + lis[i]);
}
int main() {
    cin>>n>>k;
    for(int i = 0;i < n;i++) cin>>lis[i];
    sort(lis,lis+n);
    if(dfs(0,0)){
        int size = vc.size();
        for(int i = 0;i < size-1;i++) cout<<vc[i]<<" ";
        cout<<vc[size-1]<<endl;
    }else{
        cout<<"No Solution"<<endl;
    }
    return 0;
}
