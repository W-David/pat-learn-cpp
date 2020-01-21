#include <bits/stdc++.h>
using namespace std;
int main() {
    char in[25];
    stack<char> s;
    map<char,int> prior;
    prior['/'] = prior['*'] = 1;
    prior['+'] = prior['-'] = 0;
    bool isF = true;
    scanf("%s",in);
    for(int i = 0;char ch = in[i];++i) {
        if(((i == 0 || in[i-1] == '(') && (ch == '+' || ch == '-'))
        || (ch == '.' || (ch >= '0' && ch <= '9'))){
            if(!isF) cout<<" ";
            if(ch != '+') cout<<ch;
            while(in[i+1] == '.' || (in[i+1] >= '0' && in[i+1] <= '9')){
                i++;cout<<in[i];
            }
            isF = false;
        }else{
            if(s.empty() || ch == '(') s.push(ch);
            else if(ch == ')'){
                while(!s.empty() && s.top() != '('){
                    cout<<" "<<s.top();s.pop();
                }
                s.pop();
            }else{
                while(!s.empty() && s.top() != '(' && prior[ch] <= prior[s.top()]){
                    cout<<" "<<s.top();s.pop();
                }
                s.push(ch);
            }
        }
    }
    while(!s.empty()){
        cout<<" "<<s.top();
        s.pop();
    }
    return 0;
}
