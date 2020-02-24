#include <bits/stdc++.h>
using namespace std;
int n;
void onceInsertSort(vector<int> &vc,int cnt){
    int tmp = vc[cnt],j;
    for(j = cnt-1;j >= 0 && vc[j] > tmp;j--) vc[j+1] = vc[j];
    vc[j+1] = tmp;
}
void sink(vector<int> &vc,int k,int num){
    int tmp = vc[k],j;
    for(j = 2 * k + 1;j < num && tmp < vc[j];j = 2 * k + 1){
        if(j < num -1 && vc[j] < vc[j+1]) j++;
        vc[k] = vc[j];
        k = j;
    }
    vc[k] = tmp;
}
void swap(vector<int> &vc,int v,int w){
    int temp = vc[v];
    vc[v] = vc[w];
    vc[w] = temp;
}
void onceHeapSort(vector<int> &vc,int cnt){
    swap(vc,0,n-cnt);
    sink(vc,0,n-cnt);
}
void outputLis(vector<int> vc){
    printf("%d",vc.front());
    for(int i = 1;i < n;i++) printf(" %d",vc[i]);
    printf("\n");
}
int main() {
    int cur;
    scanf("%d",&n);
    vector<int> insertLis(n),heapLis(n),sortedLis(n);
    for(int i = 0;i < n;i++) {
        scanf("%d",&cur);
        insertLis[i] = heapLis[i] = cur;
    }
    for(int i = 0;i < n;i++) scanf("%d",&sortedLis[i]);
    for(int i = n/2-1;i >=0;i--) sink(heapLis,i,n); // create heap struct
    for(int i = 1;i < n;i++){
        onceInsertSort(insertLis,i);
        onceHeapSort(heapLis,i);
//        outputLis(insertLis);
//        outputLis(heapLis);
        if(sortedLis == insertLis) {
            printf("%s\n","Insertion Sort");
            onceInsertSort(insertLis,i+1);
            outputLis(insertLis);
            break;
        }
        if(sortedLis == heapLis) {
            printf("%s\n","Heap Sort");
            onceHeapSort(heapLis,i+1);
            outputLis(heapLis);
            break;
        }
    }
    return 0;
}
