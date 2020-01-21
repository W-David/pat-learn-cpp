#include <iostream>
using namespace std;
int main() {
    int n = 8;
    char s[15] = "ACDBCB";
    int a = 0,b = n-1;
    while(a <= b){
        bool left = false;
        for(int i = 0;a + i <= b;++i){
            if(s[a+i] == s[b-i]) continue;
            left = s[a + i] < s[b - i];
            break;
        }
        if(left) putchar(s[a++]);
        else putchar(s[b--]);
    }
    return 0;
}
