#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
map<int,int> mp;
struct cmp{
    bool operator() (pr a,pr b){
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    }
};
int main() {
    int n,k,c;
    scanf("%d %d",&n,&k);
    scanf("%d",&c);
    mp[c]++;
    for(int i = 1;i < n;i++){
        scanf("%d",&c);
        printf("%d:",c);
        priority_queue<pr,vector<pr>,cmp> pq(mp.begin(),mp.end());
        for(int j = 0;j < k && !pq.empty();j++){
            printf(" %d",pq.top() ),pq.pop();
        }
        printf("\n");
        mp[c]++;
    }
    return 0;
}
