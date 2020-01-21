#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,string> database;

map<string,string>::iterator query(string uid){
    return database.find(uid);
}

void add(string uid,string pw){
    database[uid] = pw;
}

int main() {
    int n;
    cin>>n;
    for(int i = 0;i < n;i++) {
        string op,uid,pw;
        cin>>op>>uid>>pw;
        map<string,string>::iterator it;
        it = query(uid);
        if(op == "L"){
            if(it == database.end()) cout<<"ERROR: Not Exist";
            else if(it->second != pw) cout<<"ERROR: Wrong PW";
            else cout<<"Login: OK";
        } else {
            if(it == database.end()) {
                cout<<"New: OK";
                add(uid,pw);
            }
            else cout<<"ERROR: Exist";
        }
        cout<<endl;
    }
}
