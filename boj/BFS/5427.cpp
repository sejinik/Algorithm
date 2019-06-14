//BFS를 이용해 푸는 문제
//불과 사람의 BFS를 만든다
//그리고 각 초마다 불 => 사람 순서로 BFS를 돌린다
//사람이 들어있는 큐가 끝나면 끝
//마지막으로 테두리를 보며 나갔는지 확인!

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 987654321
int n,w,h;
queue<pair<int,int>> Q1,Q2;
char map[1010][1010];
bool check[1010][1010];
int dist[1010][1010];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool isInner(int x,int y){
    return (0<=x && x<h && 0<=y && y<w);
}

int Answer(){
    int ans = INF;
    for(int i=0;i<w;i++) ans = min({ans,dist[0][i],dist[h-1][i]});
    for(int i=0;i<h;i++) ans = min({ans,dist[i][0],dist[i][w-1]});
    return ans;
}

void init(){
    while(!Q1.empty()) Q1.pop();
    while(!Q2.empty()) Q2.pop();
    memset(check,0,sizeof(check));
    memset(map,0,sizeof(map));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i][j]=INF;
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    while(n--){
        scanf(" %d %d",&w,&h);
        init();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                scanf(" %1c",&map[i][j]);
                if(map[i][j]=='@'){
                    Q2.push({i,j}); 
                    dist[i][j]=1;
                    check[i][j]=true;
                } else if(map[i][j]=='*'){
                    Q1.push({i,j});
                    check[i][j]=true;
                }
            }
        }
        while(!Q2.empty()){                           
            int S1 = Q1.size();
            while(S1--){
                int x = Q1.front().first;
                int y = Q1.front().second;
                Q1.pop();

                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(isInner(nx,ny) && !check[nx][ny] && map[nx][ny] !='#'){
                        map[nx][ny]='*';
                        check[nx][ny]=true;
                        Q1.push({nx,ny});
                    }
                }
            } 
            int S2 = Q2.size();
            while(S2--){
                int x = Q2.front().first;
                int y = Q2.front().second;
                Q2.pop();

                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(isInner(nx,ny) && !check[nx][ny] && map[nx][ny]=='.'){
                        check[nx][ny]=true;
                        dist[nx][ny]=dist[x][y]+1;
                        Q2.push({nx,ny});
                    }
                }
            }                 
        }
    int ans = Answer();
    if(ans==INF) puts("IMPOSSIBLE");
    else printf("%d\n",ans);
    }
}