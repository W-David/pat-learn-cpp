#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using  namespace std;

struct Student{
    int id,score;
    string name;
};
Student list[100005];
auto cmp1 = [](Student stu1,Student stu2){return stu1.id < stu2.id;};
auto cmp2 = [](Student stu1,Student stu2){return stu1.name == stu2.name ? stu1.id < stu2.id : stu1.name < stu2.name;};
auto cmp3 = [](Student stu1,Student stu2){return stu1.score == stu2.score ? stu1.id < stu2.id : stu1.score < stu2.score;};
int main() {
    int n,c; cin>>n>>c;
    for(int i = 0;i < n;i++) {
        cin>>list[i].id>>list[i].name>>list[i].score;
    }
    if(c == 1) sort(list,list+n,cmp1);
    else if(c == 2) sort(list,list+n,cmp2);
    else sort(list,list+n,cmp3);
    for(int i = 0;i < n;i++){
        Student student = list[i];
        printf("%06d ",student.id);
        cout<<student.name<<" "<<student.score<<endl;
    }
    return 0;
}
