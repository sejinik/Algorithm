#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 1e9;
int n,t,r,c;

//d[x][y][k] => (x,y) 정점에 k의 상태로 갈 때의 최단거리
// k==0 일반모드 , k==1 변신모드
int d[505][505][2];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
char arr[505][505];

// 그래프 범위를 넘어가는지 확인
bool inner(int x,int y){
    return (0<=x && x<n && 0<=y && y<n);
}

// 내가 갈 수 있는 워프 리스트를 반환 해 준다
vector<pair<int,int>> isWarp(int x,int y){
    vector<pair<int,int>> warpList;

    // 위 쪽 방향의 가까운 워프를 찾는다
    for(int i=x-1;i>=0;i--) {
        if(arr[i][y]=='#'){
            warpList.push_back({i,y}); break;
        }
    }
    // 아래 쪽 방향의 가까운 워프를 찾는다
    for(int i=x+1;i<n;i++) {
        if(arr[i][y]=='#'){
            warpList.push_back({i,y}); break;
        }
    }

    // 왼쪽 방향의 가까운 워프를 찾는다
    for(int i=y-1;i>=0;i--){
        if(arr[x][i]=='#'){
            warpList.push_back({x,i}); break;
        }
    }

    // 오른쪽 방향의 가까운 워프를 찾는다
    for(int i=y+1;i<n;i++){
        if(arr[x][i]=='#'){
            warpList.push_back({x,i}); break;
        }
    }
    return warpList;
}

int main() { 
    //freopen("input.txt","r",stdin);

    // 최단거리 배열을 -1로 초기화해준다
    // -1이라는 수는 최단거리에서 나올 수 없으므로 방문여부를 판단한다
    memset(d,-1,sizeof(d));
    scanf(" %d %d %d %d",&n,&t,&r,&c); r--; c--;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %1c",&arr[i][j]);
        }
    }

    // 우선순위 큐를 이용해 그리디적으로 가장 비용이 적게드는 곳부터 본다
    // C++ 에서 pq는 최대힙이기 때문에 cost를 음수로 저장해 최소힙처럼 사용할 수 있다
    priority_queue<pair<pair<int,int>,pair<int,int>>> pq;

    // 시작점을 넣어준다
    pq.push({{0,0},{0,0}});
    //내가 갈 수 있는 정점들이 있다면 계속 탐색 해준다
    while(!pq.empty()){
        int cost = -pq.top().first.first;
        int status = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        //(x,y)에 status의 상태로 이미 방문한 적이 있다면 패스
        if(d[x][y][status] != -1) continue;

        // 처음오는 곳이라면 cost만큼의 비용으로 값을 넣어준다
        d[x][y][status]=cost;

        // status가 0일 때 4방향 탐색 
        // status가 1일 때 0의 턴을 소모해 status=0으로 변신 후 4방향 탐색
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int ncost = -cost-1;
            // 4방향 중 방문하지 않은 곳을 pq에 넣어준다
            if(inner(nx,ny) && d[nx][ny][0]==-1) pq.push({{ncost,0},{nx,ny}});
        }            
        
        // status가 1일 때 1의 턴을 소모
        int ncost = -cost-1;
        //status가 0이라면 t의 턴을 소모해 status=1로 변신
        if(status==0) ncost-=t;
        vector<pair<int,int>> warpList = isWarp(x,y);
        // 가까운 워프 중 갈 수있는곳 중 방문하지 않은곳을 pq에 넣어준다
        for(auto position : warpList){
            int nx = position.first;
            int ny = position.second;
            if(d[nx][ny][1] ==-1) pq.push({{ncost,1},{nx,ny}});
        }
    }

    // 목표지점의 값이 -1이라면 갈 수 없다는 뜻이다
    // 나올 수 없는 INF 값으로 바꿔준다
    if(d[r][c][0]==-1) d[r][c][0]=INF;
    if(d[r][c][1]==-1) d[r][c][1]=INF;

    //일반모드, 변신모드 중 턴이 적게 소모되는 값을 반환해 준다
    printf("%d\n",min(d[r][c][0],d[r][c][1]));
}   