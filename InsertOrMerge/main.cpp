#include <bits/stdc++.h>
using namespace std;
const int max_n = 105;
int lis[max_n],sorted[max_n];
int main(){
    int n,p,f;
    cin>>n;
    for(int i = 0;i < n;i++) cin>>lis[i];
    for(int i = 0;i < n;i++) cin>>sorted[i];
    for(p = 1;p < n && sorted[p-1] <= sorted[p];p++);
    for(f = p;f < n && lis[f] == sorted[f];f++);
    if(f == n){
        cout<<"Insertion Sort"<<endl;
        sort(sorted,sorted+p+1);
    }else{
        cout<<"Merge Sort"<<endl;
        int m = p * 2;
        for(int i = 0;i < n / m;i++){
            sort(sorted + i * m,sorted + (i+1) * m);
        }
        sort(sorted + n / m * m,sorted + n);
    }
    for(int i = 0;i < n -1;i++)  cout<<sorted[i]<<" ";
    cout<<sorted[n-1]<<endl;
    return 0;
}