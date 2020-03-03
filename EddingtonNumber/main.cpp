#include <bits/stdc++.h>
using namespace std;
int mp[100005]{0};
int main() {
    int n,ans{};
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&mp[i]);
    sort(mp+1,mp+n+1,greater<int>());
    for(ans = 1;ans <= n && mp[ans] > ans;ans++);
    printf("%d",ans - 1);
    return 0;
}
