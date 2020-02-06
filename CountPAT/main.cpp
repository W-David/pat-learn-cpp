#include <bits/stdc++.h>
using namespace std;
int main() {
    char s[100005];
    scanf("%s",s);
    long long p = 0,pa = 0,pat = 0;
    for(int i = 0;s[i];i++){
        if(s[i] == 'P') p++;
        else if(s[i] == 'A') pa += p;
        else pat += pa;
    }
    printf("%d",pat%1000000007);
    return 0;
}
