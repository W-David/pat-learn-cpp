#include <iostream>
#define MIN -10005;
using namespace std;

int heap[1005];
void insert(int v,int k){
    while(heap[k/2] > v){
        heap[k] = heap[k/2];
        k /= 2;
    }
    heap[k] = v;
}
int main() {
    int N,M; cin>>N>>M;
    heap[0] = MIN;
    for(int i = 1;i <= N;i++) {
        int v; cin>>v;
        insert(v,i);
    }
    for(int i = 0;i < M;i++){
        int c; cin>>c;
        while(c != 1){
            cout<<heap[c]<<" ";
            c /= 2;
        }
        cout<<heap[1]<<endl;
    }
    return 0;
}
