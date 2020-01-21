#include<iostream>
#include<vector>
using namespace std;

vector<int> vc;

int partition(int lo,int hi){
    int pivot = vc[lo];
    while(lo < hi){
        while(lo < hi && vc[hi] >= pivot) --hi;
        vc[lo] = vc[hi];
        while(lo < hi && vc[lo] <= pivot) ++lo;
        vc[hi] = vc[lo];
    }
    vc[lo] = pivot;
    return lo;
}
void quickSort(int lo,int hi){
    if(lo >= hi) return;
    int p = partition(lo,hi);
    quickSort(lo,p-1);
    quickSort(p+1,hi);
}

int main(){
    int n; cin>>n;
    for(int i = 0;i < n;i++){
        int c; cin>>c;
        vc.push_back(c);
    }
    quickSort(0,n-1);
    for(int i = 0;i < n - 1;i++){
        cout<<vc[i]<<" ";
    }
    cout<<vc[n-1]<<endl;
}
