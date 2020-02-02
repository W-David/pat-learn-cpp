#include <bits/stdc++.h>
using namespace std;
int key[100005],nex[100005];
map<int,int> addr;
vector<int> vc;
int main() {
    int n,h,a,k,nx;
    cin>>n>>h;
    for(int i = 0;i < n;i++){
        cin>>a>>k>>nx;
        addr[k] = a; key[a] = k;nex[a] = nx;
    }
    for(int i = h;i != -1;i = nex[i]) vc.push_back(key[i]);
    sort(vc.begin(),vc.end());
    int size = vc.size();
    if(size == 0) printf("0 -1\n");
    else{
        printf("%d %05d\n",size,addr[vc.front()]);
        for(int i = 0;i < size-1;i++){
            printf("%05d %d %05d\n",addr[vc[i]],vc[i],addr[vc[i+1]]);
        }
        printf("%05d %d -1\n",addr[vc[size-1]],vc[size-1]);
    }
    return 0;
}
