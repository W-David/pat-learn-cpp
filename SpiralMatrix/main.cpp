#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int lis[10005];
int main() {
    int N,m{},n{};
    scanf("%d",&N);
    for(int i = 0;i < N;i++) scanf("%d",&lis[i]);
    sort(lis,lis+N,greater<int>());
    for(n = (int)sqrt(N);n >= 1 && (N % n);n--);
    m = N / n;
    int matrix[m][n];
    memset(matrix,0,sizeof(matrix));
    int x = 0,y = 0,k = 0,pos = 0;
    while(k < N){
        matrix[x][y] = lis[k++];
        for(int i = pos;(i+1) % 4 != pos;i = (i+1) % 4){
            int nx = x + dx[i],ny = y + dy[i];
            if((0 <= nx && nx < m) && (0 <= ny && ny < n) && !matrix[nx][ny]){
                pos = i,x = nx,y = ny;
                break;
            }
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            printf("%d%s",matrix[i][j],j == n - 1 ? "\n" : " ");
        }
    }
    return 0;
}
