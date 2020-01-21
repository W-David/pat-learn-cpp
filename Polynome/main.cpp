#include <iostream>
using namespace std;

int polya[1005];
int polyb[1005];
int polyAdd[1005];
int polyMultiply[2005];

void inputPoly(int poly[]){
   int n; cin>>n;
   while(n-- > 0) {
       int factor,index; cin>>factor>>index;
       poly[index] = factor;
   }
}
void addPoly(){
    for(int i = 0;i <= 1000;i++)
        polyAdd[i] = polya[i] + polyb[i];
}

void multiplyPoly(){
    for(int i = 0;i <= 1000;i++){
        for(int j = 0;j <= 1000;j++){
            if(polya[i] == 0 || polyb[j] == 0) continue;
            polyMultiply[i+j] = polya[i] * polyb[j];
        }
    }
}
int main(){
    inputPoly(polya);
    inputPoly(polyb);
    addPoly();
    multiplyPoly();
    int r = 0; while(polyMultiply[r] == 0) r++;
    if(r > 2000) cout<<0<<" "<<0<<endl;
    else {
        for(int i = 2000;i > r;i--)
            if(polyMultiply[i] != 0) cout<<polyMultiply[i]<<" "<<i<<" ";
        cout<<polyMultiply[r]<<" "<<r<<endl;
    }
    int k = 0; while(polyAdd[k] == 0) k++;
    if(k > 1000) cout<<0<<" "<<0<<endl;
    else {
        for(int i = 1000;i > k;i--)
            if(polyAdd[i] != 0) cout<<polyAdd[i]<<" "<<i<<" ";
        cout<<polyAdd[k]<<" "<<k<<endl;
    }
    return 0;
}
