#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n,t,r,c;
int d[505][505][2];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
char arr[505][505];

bool inner(int x,int y){
    return (0<=x && x<n && 0<=y && y<n);
}

vector<pair<int,int>> isWarp(int x,int y){
    vector<pair<int,int>> warpList;
    for(int i=x-1;i>=0;i--) {
        if(arr[i][y]=='#'){
            warpList.push_back({i,y}); break;
        }
    }
    for(int i=x+1;i<n;i++) {
        if(arr[i][y]=='#'){
            warpList.push_back({i,y}); break;
        }
    }
    for(int i=y-1;i>=0;i--){
        if(arr[x][i]=='#'){
            warpList.push_back({x,i}); break;
        }
    }
    for(int i=y+1;i<n;i++){
        if(arr[x][i]=='#'){
            warpList.push_back({x,i}); break;
        }
    }
    return warpList;
}

int main() { 
    //freopen("input.txt","r",stdin);

    memset(d,-1,sizeof(d));
    scanf(" %d %d %d %d",&n,&t,&r,&c); r--; c--;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %1c",&arr[i][j]);
        }
    }

    priority_queue<pair<pair<int,int>,pair<int,int>>> pq;
    pq.push({{0,0},{0,0}});
    while(!pq.empty()){
        int cost = -pq.top().first.first;
        int status = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(d[x][y][status] != -1) continue;
        d[x][y][status]=cost;

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int ncost = -cost-1;
            if(inner(nx,ny) && d[nx][ny][0]==-1) pq.push({{ncost,0},{nx,ny}});
        }            
        

        int ncost = -cost-1;
        if(status==0) ncost-=t;
        vector<pair<int,int>> warpList = isWarp(x,y);
        for(auto position : warpList){
            int nx = position.first;
            int ny = position.second;
            if(d[nx][ny][1] ==-1) pq.push({{ncost,1},{nx,ny}});
        }
    }

    if(d[r][c][0]==-1) d[r][c][0]=1e9;
    if(d[r][c][1]==-1) d[r][c][1]=1e9;
    printf("%d\n",min(d[r][c][0],d[r][c][1]));
}   