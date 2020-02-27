#include <bits/stdc++.h>
using namespace std;
int lis[1005];
void output(int i){
    vector<int> vc;
    for(int j = i;j;j /= 2) vc.push_back(lis[j]);
    for(int j = vc.size()-1;j > 0;j--) cout<<vc[j]<<" ";
    cout<<vc[0]<<endl;
}
bool increase(int i,int j) {return lis[i] < lis[j];} //judge maxHeap
bool decrease(int i,int j) {return lis[i] > lis[j];} //judge minHeap
bool isHeap(int n,bool (*func)(int,int)){
    for(int i = 1;i < n/2;i++) if(func(i,i*2) || func(i,i*2+1)) return false;
    if(n % 2 == 0) return !func(n/2,n);
    return !func(n/2,n-1) && !func(n/2,n);
}
int main(){
    int n,x{1};
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>lis[i];
    while(pow(2,x) < n) x++;
    int p = int(pow(2,x) - 1);
    if(pow(2,x+1) > n){
        int np = n - (n+1) / 2;
        for(int i = p;i > np;i--) output(i);
    }
    for(int i = n;i > p;i--) output(i);
    bool isMinHeap = isHeap(n,decrease),isMaxHeap = isHeap(n,increase);
    if(isMinHeap) cout<<"Min Heap"<<endl;
    else if(isMaxHeap) cout<<"Max Heap"<<endl;
    else cout<<"Not Heap"<<endl;
    return 0;
}