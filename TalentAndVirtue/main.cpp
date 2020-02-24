#include <bits/stdc++.h>
using namespace std;
int m,l,h;
struct people{
    int id,talent,virtue,grade,rank;
};
vector<people> lis;
bool cmp(people a,people b){
    return a.rank == b.rank ?
           a.grade == b.grade ?
           a.virtue == b.virtue ? a.id < b.id
           : a.virtue > b.virtue
           : a.grade > b.grade
           : a.rank < b.rank;
}
int getRank(int virtue,int talent){
    if(virtue >= h && talent >= h) return 1;
    if(virtue >= h && talent < h) return 2;
    if(virtue < h && talent < h && virtue >= talent) return 3;
    return 4;
}
int main() {
    scanf("%d %d %d",&m,&l,&h);
    for(int i = 0;i < m;i++){
        people peo;
        scanf("%d %d %d",&peo.id,&peo.virtue,&peo.talent);
        if(peo.virtue < l || peo.talent < l) continue;
        peo.grade = peo.virtue + peo.talent;
        peo.rank = getRank(peo.virtue,peo.talent);
        lis.push_back(peo);
    }
    sort(lis.begin(),lis.end(),cmp);
    printf("%d\n",lis.size());
    for(people peo: lis){
        printf("%08d %d %d\n",peo.id,peo.virtue,peo.talent);
    }
    return 0;
}
