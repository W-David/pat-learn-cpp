#include <bits/stdc++.h>
using namespace std;
int n,m,k,quota[105];
struct Record{int ge,gi,ga,ap[5];};
map<int,Record> mp;
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i < m;i++) scanf("%d",&quota[i]);
    for(int i = 0;i < n;i++){
        Record record;
        scanf("%d %d",&(record.ge),&(record.gi));
        for(int j = 0;j < k;j++) scanf("%d",&(record.ap[i]));
        mp[i] = record;
    }
    
    return 0;
}
