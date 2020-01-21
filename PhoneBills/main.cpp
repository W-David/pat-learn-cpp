#include <bits/stdc++.h>
using namespace std;
int mp[25] = {0};
struct record{
    string name;
    int d{},h{},m{},time{},status{};
    bool operator< (const record& that) const{ return name == that.name ? time < that.time : name < that.name;}
}records[1005];
map<string,vector<pair<record,record>>> bill;
int absToll(const record& rec){
    int toll = mp[rec.h] * rec.m + mp[24]*60* rec.d;
    for(int i = 0;i < rec.h;i++) toll += mp[i] * 60;
    return toll;
}
int main(){
    int n,month = 0;
    char status[25];
    for(int i = 0;i < 24;i++){
        cin>>mp[i];
        mp[24] += mp[i];
    }
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>records[i].name;
        scanf("%d:%d:%d:%d %s",&month,&records[i].d,&records[i].h,&records[i].m,status);
        records[i].status = strcmp(status,"on-line") == 0 ? 1 : 0;
        records[i].time = records[i].d * 60 *24 + records[i].h * 60 + records[i].m;
    }
    sort(records,records+n);
    for(int i = 1;i < n;i++){
        if(records[i].name == records[i-1].name && records[i].status == 0&& records[i-1].status == 1){
            pair<record,record> cp = make_pair(records[i-1],records[i]);
            bill[records[i].name].push_back(cp);
        }
    }
    for(auto &it: bill){
        vector<pair<record,record>> vc = it.second;
        printf("%s %02d\n",it.first.c_str(),month);
        int tollSum = 0;
        for(auto &item:vc){
            int atoll = absToll(item.second) - absToll(item.first);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",item.first.d,item.first.h,item.first.m,item.second.d,item.second.h,item.second.m,item.second.time - item.first.time,atoll / 100.0);
            tollSum += atoll;
        }
        printf("Total amount: $%.2f\n",tollSum /100.0);
    }
    return 0;
}
