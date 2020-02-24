#include <bits/stdc++.h>
using namespace std;
struct moonCake{
    double inventory,price;
};
vector<moonCake> vc;
auto cmp = [](moonCake a,moonCake b){return a.price > b.price;};
int main() {
    int n;
    double demand,cp;
    cin>>n>>demand;
    vc.resize(n);
    for(int i = 0;i < n;i++) cin>>vc[i].inventory;
    for(int i = 0;i < n;i++){
        cin>>cp;
        vc[i].price = cp / vc[i].inventory;
    }
    sort(vc.begin(),vc.end(),cmp);
    double ans{};
    for(moonCake &mc: vc){
        if(demand == 0) break;
        double cd = demand < mc.inventory ? demand : mc.inventory;
        demand -= cd;
        ans += cd * mc.price;
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
