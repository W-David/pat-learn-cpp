#include <iostream>
using namespace std;

int s1[100005];
int s2[100005];
int n;
int main() {
    cin>>n;
    int mid = (2*n+1)/2;
    for(int i = 0;i < n;i++) cin>>s1[i];
    for(int j = 0;j < n;j++) cin>>s2[j];
    int i = 0,j = 0,k = 0,c = 0;
    while(true){
        int a = s1[i],b = s2[j];
        if(a < b) i++,k++,c = 0;
        else if(a > b) j++,k++,c = 1;
        else i++,j++;k++;
        if(k == mid) {
            cout<<(c ? s2[j] : s1[i])<<endl;
            break;
        }
    }
    return 0;
}
