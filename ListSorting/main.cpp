#include <bits/stdc++.h>
using namespace std;
struct Stu{
    int id,grade;
    char name[9];
}student[100005];
auto cmp1 = [](const Stu& a,const Stu& b){return a.id < b.id;};
auto cmp2 = [](const Stu& a,const Stu& b){return strcmp(a.name,b.name) == 0 ? a.id < b.id : strcmp(a.name,b.name) < 0;};
auto cmp3 = [](const Stu& a,const Stu& b){return a.grade == b.grade ? a.id < b.id : a.grade < b.grade;};
int main() {
    int n,c;
    scanf("%d %d",&n,&c);
    for(int i = 0;i < n;i++) scanf("%d %s %d",&student[i].id,student[i].name,&student[i].grade);
    switch(c){
        case 1: sort(student,student+n,cmp1);break;
        case 2: sort(student,student+n,cmp2);break;
        case 3: sort(student,student+n,cmp3);break;
        default: break;
    }
    for(int i = 0;i < n;i++){
        printf("%06d %s %d\n",student[i].id,student[i].name,student[i].grade);
    }
    return 0;
}
