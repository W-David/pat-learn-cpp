#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,m;
    scanf("%d%d",&n,&k);
    map<string,int> vl;
    char uid[18];
    int d;
    while(n--){
        scanf("%s %d",uid,&d);
        if(d < k) d = k;
        vl[uid] += d;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%s",uid);
        auto it = vl.find(uid);
        if(it == vl.end()) printf("No Info\n");
        else printf("%d\n",it->second);
    }
    return 0;
}
