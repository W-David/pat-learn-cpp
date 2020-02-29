#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> lis,sorted,aux;
void OnceInsertSort(vector<int>& vc,int cnt){
    if(cnt >= n) return;
    int tmp = vc[cnt],i;
    for(i = cnt - 1;i >= 0 && vc[i] > tmp;i--) vc[i+1] = vc[i];
    vc[i+1] = tmp;
}
void merge(vector<int>& vc,int lo,int mid,int hi){
    int i = lo,j = mid + 1;
    for(int k = lo;k <= hi;k++) aux[k] = vc[k];
    for(int k = lo;k <= hi;k++){
        if(i > mid) vc[k] = aux[j++];
        else if(j > hi) vc[k] = aux[i++];
        else if(aux[i] < aux[j]) vc[k] = aux[i++];
        else vc[k] = aux[j++];
    }
}
void OnceMergeSort(vector<int>& vc,int k){
    if(k > n) return;
    int i = 0;
    while(i < n - 2*k + 1){ // i + 2*k -1 <= n-1
        merge(vc,i,i+k-1,i+2*k-1);
        i += 2*k;
    }
    if(i < n-k){ //i+k-1 < n-1
        merge(vc,i,i+k-1,n-1);
    }
}
bool isInsertSorted(vector<int>& insertLis){
    for(int k = 1;k < n;k++) {
        OnceInsertSort(insertLis,k);
        if(insertLis == sorted) return k;
    }
    return 0;
}
bool isMergeSorted(vector<int>& mergeLis){
    for(int k = 1;k < n;k *= 2){
        OnceMergeSort(mergeLis,k);
        if(mergeLis == sorted) return k;
    }
    return 0;
}
void outputLis(vector<int> vc){
    for(int i = 0;i < n-1;i++) cout<<vc[i]<<" ";
    cout<<vc[n-1]<<endl;
}
int main() {
    cin>>n;
    lis.resize(n),sorted.resize(n),aux.resize(n);
    for(int i = 0;i < n;i++) cin>>lis[i];
    for(int i = 0;i < n;i++) cin>>sorted[i];
    vector<int> insertLis(lis),mergeLis(lis);
    int k;
    if((k = isInsertSorted(insertLis))){
        cout<<"Insertion Sort"<<endl;
        OnceInsertSort(insertLis,k+1);
        outputLis(insertLis);
    }else{
        cout<<"Merge Sort"<<endl;
        k = isMergeSorted(mergeLis);
        isMergeSorted(mergeLis);
        OnceMergeSort(mergeLis,k*2);
        outputLis(mergeLis);
    }
    return 0;
}
