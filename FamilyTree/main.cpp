#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    cin.ignore();
    string familyTree[1005];
    map<string,string> parent;
    string rs;
    getline(cin,rs);
    parent[rs] = rs;
    familyTree[0] = rs;
    for(int i = 1;i < n;i++){
        string s;
        getline(cin,s);
        int spaceCnt = count(s.begin(),s.end(),' ');
        int level = spaceCnt / 2;
        s = s.substr(spaceCnt);
        parent[s] = familyTree[level-1];
        familyTree[level] = s;
    }
    string result,t = "True",f = "False";
    for(int i = 0;i < m;i++){
        string x,a,b,connect,c,y;
        cin>>x>>a>>b>>connect>>c>>y;
        switch(connect[0]){
            case 'p':
                result = parent[y] == x ? t : f;
                break;
            case 'c':
                result = parent[x] == y ? t : f;
                break;
            case 's':
                result = parent[x] == parent[y] ? t : f;
                break;
            case 'a':
                while(parent[y] != y && parent[y] != x) y = parent[y];
                result = parent[y] == y ? f : t;
                break;
            case 'd':
                while(parent[x] != x && parent[x] != y) x = parent[x];
                result = parent[x] == x ? f : t;
                break;
        }
        cout<<result<<endl;
    }
    return 0;
}
