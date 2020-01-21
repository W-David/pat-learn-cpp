#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
    string id;
    int scope;
    int localId;
    Student(string _id,int _scope,int _localId):id(_id),scope(_scope),localId(_localId){};
};
vector<Student> students;
auto cmp = [](Student stuA,Student stuB){
    return stuA.id == stuB.id ?
           stuA.id.compare(stuB.id) < 0 : stuA.scope > stuB.scope;
};
int main() {
    int n; cin>>n;
    for(int i = 1;i <= n;i++){
        int m; cin>>m;
        for(int j = 0;j < m;j++){
            string id; int scope;
            cin>>id>>scope;
            students.push_back(Student(id,scope,i));
        }
    }
    sort(students.begin(),students.end(),cmp);
    int studentsNum = students.size();
    int rank = 1,localRank[n+1],localCount[n+1],localPreScope[n+1];
    for(int i = 1;i <= n;i++){
        localRank[i] = 1;
        localCount[i] = 0;
    }
    Student first = students[0];
    cout<<studentsNum<<endl;
    cout<<first.id<<" "<<1<<" "<<first.localId<<" "<<1<<endl;
    localCount[first.localId]++;
    localPreScope[first.localId] = first.scope;
    for(int i = 1;i < studentsNum;i++){
       Student student = students[i],preStudent = students[i-1];
       int localId = student.localId;
       localCount[localId]++;
       if(student.scope < preStudent.scope) rank = i+1;
       if(student.scope < localPreScope[localId]) localRank[localId] = localCount[localId];
       localPreScope[localId] = student.scope;
       cout<<student.id<<" "<<rank<<" "<<localId<<" "<<localRank[localId]<<endl;
    }
    return 0;
}
