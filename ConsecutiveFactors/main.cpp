#include <bits/stdc++.h>
using namespace std;
const int m = 100;
int main() {
    int n;cin>>n;
    int front{n},maxCnt{1};
    for(int i = 2;i < m;i++){
        int cnt{0};
        for(int tp = n,start = i;tp % start == 0;tp = tp / start,start++) cnt++;
        if(cnt > maxCnt){
            maxCnt = cnt;
            front = i;
        }
    }
    cout<<maxCnt<<endl<<front;
    for(int i = 1;i < maxCnt;i++) cout<<"*"<<front+i;
    return 0;
}
