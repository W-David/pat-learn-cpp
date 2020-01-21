#include <iostream>
using namespace std;

bool visited[1005];
int main() {
    int n,p; cin>>n>>p;
    for(int i = 0;i < n;i++){
        int c;cin>>c;
        int s = c % p;
        if(visited[s]) while(visited[s]) s = (s+1) % p;
        visited[s] = true;
        cout<<s<<(i == n-1 ? "\n" : " ");
    }
    return 0;
}
