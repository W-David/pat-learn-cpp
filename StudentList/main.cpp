#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char Sid[40005][5];
vector<int> course[2505];
int main() {
    int sc,cc;
    scanf("%d %d",&sc,&cc);
    for(int i = 1;i <= sc;i++){
        int cnt,cid;
        scanf("%s %d",Sid[i],&cnt);
        for(int k = 0;k < cnt;k++){
            scanf("%d",&cid);
            course[cid].push_back(i);
        }
    }
    for(int i = 1;i <= cc;i++){
        auto cv = course[i];
        printf("%d %d\n",i,cv.size());
        sort(cv.begin(),cv.end(),[](int a,int b){return strcmp(Sid[a],Sid[b]) < 0;});
        for(auto &it : cv) printf("%s\n",Sid[it]);
    }
    return 0;
}
