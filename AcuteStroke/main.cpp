#include <bits/stdc++.h>
using namespace std;
int brain[1300][130][65];
int dx[6] = {1,-1,0,0,0,0},dy[6] = {0,0,1,-1,0,0},dz[6] = {0,0,0,0,1,-1};
int m,n,l,t;
struct position{
    int x,y,z;
    position(int x,int y,int z):x(x),y(y),z(z){}
};
int bfs(int x,int y,int z){
    int cnt = 0;
    queue<position> q;
    q.push(position(x,y,z));
    brain[x][y][z] = 0;
    while(!q.empty()){
        position pos = q.front();q.pop();
        cnt++;
        for(int i = 0;i < 6;i++){
            int nx = pos.x + dx[i],ny = pos.y + dy[i],nz = pos.z + dz[i];
            if((0 <= nx && nx < m) && (0 <= ny && ny < n) && (0 <= nz && nz < l) && brain[nx][ny][nz]){
                brain[nx][ny][nz] = 0;
                q.push(position(nx,ny,nz));
            }
        }
    }
    return cnt < t ? 0 : cnt;
}
int main() {
    scanf("%d %d %d %d",&m,&n,&l,&t);
    for(int z = 0;z < l;z++){
        for(int x = 0;x < m;x++){
            for(int y = 0;y < n;y++) scanf("%d",&brain[x][y][z]);
        }
    }
    int sum = 0;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < l;k++) if(brain[i][j][k]) sum += bfs(i,j,k);
        }
    }
    printf("%d\n",sum);
    return 0;
}