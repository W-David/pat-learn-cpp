#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    cin.ignore();
    string s;
    map<string,int> mp;
    while(n--){
        getline(cin,s);
        int len = s.length();
        int k = 0;
        while(k < len){
            for(;s[k] != '#';k++);
            string cs;
            int i = k+1;
            for(;s[i] != '#';i++){
                if(isalnum(s[i])) cs += isupper(s[i]) ? tolower(s[i]) : s[i];
                else if(cs[cs.size()-1]!= ' ') cs += ' ';
            }
            k = i+1;
            cout<<cs<<endl;
            mp[cs] += 1;
        }
    }
    return 0;
}
