#include <bits/stdc++.h>
using namespace std;
int lis[100005];
int main() {
    long long n,p;
    scanf("%lld %lld",&n,&p);
    for(int i = 0;i < n;i++)
        scanf("%d",&lis[i]);
    sort(lis,lis+n);
    int j = 0,count = 0;
    for(int i = 0;i < n && j < n;i++){
        for(j = i + count;j < n && lis[j]<= lis[i] * p;j++)
            count = max(count,j-i+1);
    }
    printf("%d",count);
    return 0;
}
