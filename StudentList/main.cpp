#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct vc{
    vector<string> vmp;
}mp[2505];
void store(int n){
    for(int i=0;i < n;i++){
        string studentId;cin>>studentId;
        int c;cin>>c;
        while(c--){
            int courseId;cin>>courseId;
            mp[courseId].vmp.push_back(studentId);
        }
    }
}
void solve(int m){
    for(int i=1;i <= m;i++){
       cout<<i<<" "<<mp[i].vmp.size()<<endl;
       sort(mp[i].vmp.begin(),mp[i].vmp.end());
       for(auto &it : mp[i].vmp) cout<<it<<endl;
    }
}
int main() {
    int n,m; cin>>n>>m;
    store(n);
    solve(m);
    return 0;
}
