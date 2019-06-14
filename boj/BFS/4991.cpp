//BFS + next_permutation() 이용한 문제
//dist[a][b][c][d] 로 거리 배열을 잡는다
// (a,b) => (c,d) 를 뜻한다
//모든 정점에서 BFS를 돌린다
//쓰레기의 위치의 모든경우의 수를 찾는다 (next_permutation())
//거리를 더해서 최소값을 찾는다

//옛날에도 이번에도 쓰레기의 위치를 정하고 
//그 다음에 dist[a][b]를 잡고 BFS를 돌렸다가 시간초과! 받았다 굿

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define INF 1e5
int dist[22][22][22][22];
bool check[22][22][22][22];
char map[22][22];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector<pair<int,int>> Dirty;
int Rx,Ry,n,m;

bool isInner(int x,int y){
    return (0<=x && x<n && 0<=y && y<m);
}
void BFS(int a,int b){
    queue<pair<int,int>> q;
    check[a][b][a][b]=true;
    dist[a][b][a][b]=0;
    q.push({a,b});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isInner(nx,ny) && !check[a][b][nx][ny] && map[nx][ny] != 'x'){
                check[a][b][nx][ny]=true;
                dist[a][b][nx][ny]=dist[a][b][x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
void init(){
    memset(check,0,sizeof(check));
    memset(map,0,sizeof(map));
    Dirty.clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int q=0;q<n;q++){
                for(int w=0;w<m;w++){
                    dist[i][j][q][w]=INF;
                }
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf(" %d %d",&m,&n) != -1){
        if(n==0 && m==0) break;
        init();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf(" %1c",&map[i][j]);
                if(map[i][j]=='o')Rx=i,Ry=j;
                else if(map[i][j]=='*') Dirty.push_back({i,j});
            }
        }
        if(Dirty.size()==0){
            puts("0"); continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                BFS(i,j);
            }
        }
        int ans=INF;
        sort(Dirty.begin(),Dirty.end());
        do{
            int temp=dist[Rx][Ry][Dirty[0].first][Dirty[0].second];
            int size =Dirty.size()-1;
            for(int i=0;i<size;i++) temp+=dist[Dirty[i].first][Dirty[i].second][Dirty[i+1].first][Dirty[i+1].second];
            ans = min(ans,temp);
        }while(next_permutation(Dirty.begin(),Dirty.end()));
        if(ans==1e5) puts("-1");
        else printf("%d\n",ans) ;
    }
}