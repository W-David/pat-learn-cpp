#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    stack<double> sta;
    getline(cin,s);
    int len = s.size();
    bool err = false;
    for(int i = len-1;i >= 0;i--){
        if(s[i] == ' ') continue;
        if(isdigit(s[i])){
            double mul = 10,num = s[i] - '0';
            for(i--;i >=0 ;i--){
                if(isdigit(s[i])){
                    num += (s[i] - '0') * mul;
                    mul *= 10;
                }else if(s[i] == '.'){
                    num /= mul;
                    mul = 1;
                }else if(s[i] == '-'){
                    num = -num;
                }else break;
            }
            sta.push(num);
        }else{
            double a = sta.top();sta.pop();
            double b = sta.top();sta.pop();
            if(b == 0 && s[i] == '/') err = true;
            double r = 0.0;
            switch(s[i]){
                case '+': r = a+b;break;
                case '-': r = a-b;break;
                case '*': r = a*b;break;
                case '/': r = a/b;break;
            }
            sta.push(r);
        }
    }
    if(err) printf("ERROR\n");
    else printf("%.1f\n",sta.top());
    return 0;
}
