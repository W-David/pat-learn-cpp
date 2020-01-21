#include <bits/stdc++.h>
using namespace std;
struct Msg{
    string data;
    int prior;
    Msg(string data,int prior){
        this->data = data;
        this->prior = prior;
    }
    bool operator< (const Msg& right) const {
        return prior < right.prior;
    }
};
int main() {
    int n;cin>>n;
    cin.ignore();
    vector<Msg> vc;
    make_heap(vc.begin(),vc.end());
    while(n--){
        string s;
        getline(cin,s);
        if(s[0] == 'P'){
            int len = s.length();
            Msg msg(s.substr(4,len-6),s[len-1] - '0');
            vc.push_back(msg);
            push_heap(vc.begin(),vc.end());
            sort_heap(vc.begin(),vc.end());
        }else{
            if(vc.empty()) cout<<"EMPTY QUEUE!"<<endl;
            else{
                pop_heap(vc.begin(),vc.end());
                cout<<vc.back().data<<endl;
                vc.pop_back();
                sort_heap(vc.begin(),vc.end());
            }
        }
    }
    return 0;
}
