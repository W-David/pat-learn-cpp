#include <bits/stdc++.h>
using namespace std;
int lis[100005]{},indexOf[100005]{},cnt{};
void swap(int i,int j){
    int t = lis[i];lis[i] = lis[j];lis[j] = t;
    indexOf[lis[i]] = i;
    indexOf[lis[j]] = j;
    cnt++;
}
int main() {
    int n,c;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&lis[i]);
        indexOf[lis[i]] = i;
    }
    while(true){
        while(indexOf[0] != 0) swap(indexOf[0],indexOf[indexOf[0]]);
        for(c = 0;c < n;c++){
            if(lis[c] != c) {swap(0,indexOf[c]);break;}
        }
        if(c == n) break;
    }
    printf("%d\n",cnt);
    return 0;
}
