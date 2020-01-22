#include <bits/stdc++.h>
using namespace std;
long long toDec(const string& s,long long radix){
    long long sum = 0;
    for(char i : s) sum *= radix,sum += (isdigit(i) ? i-'0': i-'a'+10);
    return sum;
}
int main() {
    string s = "12345";
    long long i = toDec(s,10);
    printf("Dec is: %d",i);
    return 0;
}
