#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    double c,sum{};
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        scanf("%lf",&c);
        sum += c * (i+1) * (n-i);
    }
    printf("%.2f",sum);
    return 0;
}
