#include <bits/stdc++.h>
using namespace std;
struct Richer{
    char name[10]{};
    int age{},worth{};
}richerList[100005];
bool cmp(const Richer &a,const Richer &b){
    return a.worth == b.worth ? (a.age == b.age ? strcmp(a.name,b.name) < 0 : a.age < b.age) : a.worth > b.worth;
};
int main() {
    int n,k,m,a,b;
    scanf("%d %d",&n,&k);
    for(int i = 0;i < n;i++){
        scanf("%s %d %d",&richerList[i].name,&richerList[i].age,&richerList[i].worth);
    }
    sort(richerList,richerList+n,cmp);
    for(int i = 1;i <= k;i++){
        scanf("%d %d %d",&m,&a,&b);
        printf("Case #%d:\n",i);
        vector<Richer> vc;
        for(int j = 0;j < n;j++){
            if(richerList[j].age >= a && richerList[j].age <= b && vc.size() < m) vc.push_back(richerList[j]);
        }
        if(vc.empty()) {
            printf("None\n");
            continue;
        }
        for(auto &it:vc){
            printf("%s %d %d\n",it.name,it.age,it.worth);
        }
    }
    return 0;
}
