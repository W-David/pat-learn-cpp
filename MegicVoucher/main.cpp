#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> md;
vector<int> vc;
stack<int> s;
auto cmp = [](int a,int b){return a > b;};

void format(vector<int> v,int d){
    while(v.back() < 0) {
        s.push(v.back());
        v.pop_back();
    }
    while(d-- > 0) v.push_back(0);
    while(!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
}
int main(){
    int n; cin>>n;
    for(int i = 0;i < n;i++){
        int c; cin>>c;
        md.push_back(c);
    }
    int m; cin>>m;
    for(int i = 0;i < m;i++){
        int c; cin>>c;
        vc.push_back(c);
    }
    sort(md.begin(),md.end(),cmp);
    sort(vc.begin(),vc.end(),cmp);
    int r = md.size() - vc.size();
    if(r > 0) format(vc,r);
    else format(md,-r);
    int ms = md.size();
    int maxRepay = 0;
    for(int i =0;i < ms;i++){
        int singleRepay = md[i] * vc[i];
        if(singleRepay > 0) maxRepay += singleRepay;
    }
    cout<<maxRepay;
}