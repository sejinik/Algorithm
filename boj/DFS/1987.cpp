//DFS + 비트마스크를 이용했다
//이미 지나간 알파벳은 지나갈 수 없다
//따라서 알파벳은 비트를 이용해 체크한다
//그리고 DFS를 이용해 최대한 가본다

#include <iostream>
#include <algorithm>
using namespace std;
int n,m,ans;
char map[22][22];
bool check[22][22];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void dfs(int x,int y,int alpha,int dist){
    int num = map[x][y]-'A';
    if(alpha&(1<<num)) return;
     
    check[x][y]=true;
    alpha|=(1<<num);

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx && nx <n && 0<=ny && ny <m){
            if(!check[nx][ny]) dfs(nx,ny,alpha,dist+1);
        }
    }
    check[x][y]=false;
    ans = max(ans,dist);
}

int main(){
    freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %1c",&map[i][j]);
        }
    }
    dfs(0,0,0,1);
    printf("%d\n",ans);
}