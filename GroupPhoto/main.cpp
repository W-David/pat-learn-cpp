#include <bits/stdc++.h>
using namespace std;
struct people{
    char name[10];
    int height;
}lis[10005];
bool cmp(people a,people b){
    return a.height == b.height ? strcmp(a.name,b.name) < 0 : a.height > b.height;
}
void formatRow(string* rowLis,people* start,int num){
    int mid  = num / 2,k = 1;
    rowLis[mid] = start[0].name;
    for(int i = 1;mid - i >= 0 || mid + i < num;i++){
        if(mid - i >= 0) rowLis[mid-i] = start[k++].name;
        if(mid + i < num) rowLis[mid+i] = start[k++].name;
    }
}
void outputRow(string* rowLis,int num){
    for(int i = 0;i < num;i++) printf("%s%s",rowLis[i].c_str(),i == num - 1 ? "\n" : " ");
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i < n;i++){
        scanf("%s %d",&lis[i].name,&lis[i].height);
    }
    sort(lis,lis+n,cmp);
    int num = n / k, mx = num + n % k;
    string lastRow[mx],beforeRow[k-1][num];
    formatRow(lastRow,lis,mx);
    for(int i = 0,start = mx;i < k-1;i++,start += num){
        formatRow(beforeRow[i],lis+start,num);
    }
    outputRow(lastRow,mx);
    for(int i = 0;i < k - 1;i++) outputRow(beforeRow[i],num);
    return 0;
}
