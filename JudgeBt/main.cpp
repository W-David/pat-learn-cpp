#include <iostream>
#include <string>
#define Null -1
using namespace std;

int rawBt[1025];
int testBt[1025];
void initBt(int bt[]){
    for(int i = 1;i <= 1024;i++) bt[i] = -1;
}
void insert(int bt[],int v,int k){
    if(bt[k] == Null) bt[k] = v;
    else if(bt[k] < v) insert(bt,v,2*k);
    else insert(bt,v,2*k+1);
}
int main(){
    while(true){
        int n;cin>>n;
        if(n == 0) break;
        int m;cin>>m;
        initBt(rawBt);
        for(int i = 0;i < n;i++){
            int c;cin>>c;
            insert(rawBt,c,1);
        }
        for(int i = 0;i < m;i++){
            initBt(testBt);
            for(int j = 0;j < n;j++){
                int c;cin>>c;
                insert(testBt,c,1);
            }
            bool flag = false;
            for(int k = 1;k <= 1024;k++){
                if(rawBt[k] != testBt[k]) {
                    flag = true;
                    break;
                }
            }
            string judge = flag ? "No" : "Yes";
            cout<<judge<<endl;
        }
        return 0;
    }
}
