#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,c;cin>>n;
    priority_queue<int,vector<int>,greater<>> pq;
    while(n--){
        cin>>c;
        pq.push(c);
    }
    int minSum = 0;
    while(pq.size() > 1){
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        minSum += a + b;
        pq.push(a+b);
    }
    cout<<minSum<<endl;
    return 0;
}
