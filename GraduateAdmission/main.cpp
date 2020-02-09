#include <bits/stdc++.h>
using namespace std;
int n,m,k,quota[105];
struct Record{
    int ge,gi;
    double ga;
    Record(int ge,int gi){this->ge =ge;this->gi = gi;this->ga = (ge + gi)/2;}
};
int choose[40005][5];
map<int,Record> mp;
vector<int> school[105];
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i < m;i++) scanf("%d",&quota[i]);
    for(int i = 0;i < n;i++){
        Record record;
        scanf("%d %d",&(record.ge),&(record.gi));
        for(int j = 0;j < k;j++) scanf("%d",&(record.ap[i]));
        mp[i] = record;
    }
    for(int i = 0;i < k;i++){
        for(auto &it: mp) school[it.second.ap[i]].push_back(it.first);

    }
    return 0;
}
