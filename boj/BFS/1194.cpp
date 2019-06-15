//BFS + 비트마스크 이용해서 푸는 문제
//BFS를 돌리며 내가 가진 열쇠를 비트를 이용해 표현한다
//dist[x][y][가지고있는 열쇠]
//이렇게 출발위치에서 다 돌리고 
//출구에서 열쇠의 모든경우의 최소값을 찾아본다

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
int dist[55][55][1<<6];
bool check[55][55][1<<6];
char map[55][55];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int Fx,Fy;
vector<pair<int,int>> key;

bool isInner(int x, int y){
    return(0<=x && x<n && 0<=y && y<m);
}
int main() {
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %1c",&map[i][j]);
            if(map[i][j]=='0') Fx=i,Fy=j;
            else if(map[i][j]=='1') key.push_back({i,j});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<(1<<6);k++){
                dist[i][j][k]=1e5;
            }
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{Fx,Fy},0});
    dist[Fx][Fy][0]=0;
    check[Fx][Fy][0]=0;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int k = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isInner(nx,ny) && !check[nx][ny][k]){
                if(map[nx][ny]=='#') continue;
                if('A'<= map[nx][ny] && map[nx][ny]<='F'){
                    int c = map[nx][ny]-'A';
                    if(k&(1<<c)){
                        check[nx][ny][k]=true;
                        dist[nx][ny][k]= dist[x][y][k]+1;
                        q.push({{nx,ny},k});
                    }
                } 
                else if('a'<=map[nx][ny] && map[nx][ny]<='f'){
                    int  c = map[nx][ny]-'a';
                    int nk = k | (1<<c);
                    check[nx][ny][nk]=true;
                    dist[nx][ny][nk]=dist[x][y][k]+1;
                    q.push({{nx,ny},nk});
                }
                else{
                    check[nx][ny][k]=true;
                    dist[nx][ny][k]=dist[x][y][k]+1;
                    q.push({{nx,ny},k});
                }
            }
        }
    }
    int ans = 1e5;
    int size = key.size();
    for(int i=0;i<size;i++){
        int x = key[i].first;
        int y = key[i].second;
        for(int j=0;j<(1<<6);j++) ans = min(ans,dist[x][y][j]);
    }
    if(ans==1e5) puts("-1");
    else printf("%d\n",ans);
}