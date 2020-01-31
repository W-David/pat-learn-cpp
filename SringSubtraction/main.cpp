#include <bits/stdc++.h>
using namespace std;
int main() {
    char s1[10005],ch;
    map<char,bool> s2;
    cin.getline(s1,10005);
    while((ch = cin.get()) != '\n') s2[ch] = true;
    char *p = s1;
    while(*p){
        auto it = s2.find(*p);
        if(it == s2.end()) cout<<*p;
        p++;
    }
    return 0;
}
