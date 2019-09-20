#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
char arr[111][111];
vector<pair<int,int>> wvt;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool check[111][111];
bool unsafe[111][111];

bool inner(int x,int y){
    return (0<= x && x<n && 0<=y && y<m);
}

void bfs(int _x,int _y){
    memset(check,0,sizeof(check));
    queue<pair<int,int>> q;
    q.push({_x,_y});
    check[_x][_y]=true;
    unsafe[_x][_y]=true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        check[x][y]=true;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(inner(nx,ny)){
                if(arr[nx][ny]=='.' && !check[nx][ny]){
                    check[nx][ny]=true;
                    unsafe[nx][ny]=true;
                    q.push({nx,ny});
                } else if(arr[nx][ny]=='+'){
                    while(inner(nx,ny)){
                        if(arr[nx][ny] =='.' && !check[nx][ny]){
                            check[nx][ny]=true;
                            unsafe[nx][ny]=true;
                            q.push({nx,ny});
                            break;
                        } else if(arr[nx][ny]=='#'){
                            check[nx-dx[i]][ny-dy[i]] =true;
                            q.push({nx-dx[i],ny-dy[i]});
                            break;
                        } else if(arr[nx][ny]=='+' && !check[nx][ny]){
                            nx+=dx[i]; ny+=dy[i];
                        } else break;
                    }
                }
            }
        }
    }
}


int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='W') wvt.push_back({i,j});
        }
    }
    for(int i=0;i<wvt.size();i++) bfs(wvt[i].first,wvt[i].second);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.' && !unsafe[i][j]) printf("P");
            else printf("%c",arr[i][j]);
        }
        puts("");
    }
}