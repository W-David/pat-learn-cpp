#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
string record[100];
int main() {
    int n; cin>>n;
    cin.ignore();
    for(int i = 0;i < n;i++){
        getline(cin,record[i]);
        reverse(record[i].begin(),record[i].end());
    }
    int minLen = INF;
    for(int i = 0;i < n;i++) minLen = minLen > record[i].size() ? record[i].size() : minLen;
    string kuchiguse{};
    for(int i = 0;i < minLen;i++){
        char cur = record[0][i];
        bool f = false;
        for(int j = 1;j < n;j++) if(record[j][i] != cur) {f = true;break;}
        if(f) break;
        else kuchiguse += cur;
    }
    reverse(kuchiguse.begin(),kuchiguse.end());
    if(kuchiguse.empty()) cout<<"nai"<<endl;
    else cout<<kuchiguse<<endl;
    return 0;
}
