#include <bits/stdc++.h>
using namespace std;
int lis[10005],n,k;
vector<int> vc;
int main() {
    cin>>n>>k;
    for(int i = 0;i < n;i++) cin>>lis[i];
    sort(lis,lis+n);
    return 0;
}
