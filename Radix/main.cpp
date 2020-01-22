#include <bits/stdc++.h>
using namespace std;
long long toDec(const string& s,long long radix){
    long long sum = 0;
    for(char i : s) sum *= radix,sum += (isdigit(i) ? i-'0': i-'a'+10);
    return sum;
}
long long findRadix(long long num,const string& s){
    long long lo = 2,hi = max(num,lo);
    while(lo <= hi){
        long long mid = (lo+hi) / 2;
        long long tmp = toDec(s,mid);
        if(tmp == num) return mid;
        if(tmp < 0 || tmp > num) hi = mid-1;
        else lo = mid + 1;
    }
    return -1;
}
int main() {
    string a,b;
    int tag;
    long long radix;
    cin>>a>>b>>tag>>radix;
    if(tag == 2) swap(a,b);
    long long num= toDec(a,radix);
    long long ans = findRadix(num,b);
    if(ans == -1) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}
