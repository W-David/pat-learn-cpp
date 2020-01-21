#include <iostream>
#include <stack>
using namespace std;
stack<int> s1,s2;
int main() {
    int n,m; cin>>n>>m;
    if(n < m) swap(n,m);
    char c;
    while(true){
        cin>>c;
        if(c == 'T') break;
        else if(c == 'A'){
            int i; cin>>i;
            if(s2.size() == m && s1.size() == m) cout<<"ERROR:Full"<<endl;
            else if(s2.size() == m) {
                while(!s2.empty()) s1.push(s2.top()),s2.pop();
                s2.push(i);
            }
            else s2.push(i);
        } else {
            if(s1.empty() && s2.empty()) cout<<"ERROR:Empty"<<endl;
            else if(s1.empty()) {
                while(!s2.empty()) {s1.push(s2.top()),s2.pop();}
                cout<<s1.top()<<endl,s1.pop();
            }
            else cout<<s1.top()<<endl,s1.pop();
        }
    }
    return 0;
}
