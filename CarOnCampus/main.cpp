#include <bits/stdc++.h>
using namespace std;
struct Record{
    int time{},status;
    Record(int h,int m,int s,const string &status){
        this->status = status == "in" ? 0 : 1;this->time = h * 3600 + m * 60 + s;
    }
};
map<string,int> stayTime;
map<string,vector<Record>> records;
int stayCount[86400];
auto cmp = [](Record a,Record b){return a.time < b.time;};
int main(){
    int n,k,h,m,s,lst{};
    scanf("%d %d",&n,&k);
    char plate[8],status[5];
    while(n--){
        scanf("%s %d:%d:%d %s",plate,&h,&m,&s,status);
        stayTime[plate] = 0;
        Record record(h,m,s,status);
        auto it = records.find(plate);
        if(it == records.end()){
            vector<Record> vc;
            vc.push_back(record);
            records[plate] = vc;
        }else{
            it->second.push_back(record);
        }
    }
    for(auto &it: records){
        vector<Record> vc = it.second;
        sort(vc.begin(),vc.end(),cmp);
        int size = vc.size();
        for(int i =0;i < size-1;i++){
            if(vc[i].status == 0 && vc[i+1].status == 1){
                for(int j = vc[i].time;j < vc[i+1].time;j++) stayCount[j]++;
                stayTime[it.first] += vc[i+1].time - vc[i].time;
                lst = max(lst,stayTime[it.first]);
            }
        }
    }
    while(k--){
        scanf("%d:%d:%d",&h,&m,&s);
        int time = h * 3600 + m * 60 + s;
        printf("%d\n",stayCount[time]);
    }
    for(auto it:stayTime) {
        if(it.second == lst) printf("%s ",it.first.c_str());
    }
    printf("%02d:%02d:%02d\n",lst/3600,lst%3600/60,lst%60);
    return 0;
}
