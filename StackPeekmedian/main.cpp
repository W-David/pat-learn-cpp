#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>  s;
    int n;cin>>n;
    string op;
    while(n--){
       cin>>op;
       if(op == "Pop"){
           if(s.empty()) cout<<"Invalid"<<endl;
           else {
               cout<<s.back()<<endl;
               s.pop_back();
           }
       }else if(op == "Push"){
           int c;cin>>c;
           s.push_back(c);
       }else {
           if(s.empty()) cout<<"Invalid"<<endl;
           else {
               vector<int> aux(s);
               sort(aux.begin(),aux.end());
               int size = aux.size();
               int m = size % 2 ? aux[size/2] : aux[size/2 -1];
               cout<<m<<endl;
           }
       }
    }
    return 0;
}
