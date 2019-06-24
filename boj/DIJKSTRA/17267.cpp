//다익스트라를 이용하는 문제다
//왼쪽 오른쪽으로 최대 L,R만큼 갈 수 있다
//그럼 왼쪽으로갈때 가중치 100 , 오른쪽으로 갈 때 10억을 주자
//그리고 다익스트라를 돌려 모든정점에 최단거리를 구한다
//그 후 각정점마다 10억으로 나누고 100으로 나눠 값을 본다
//그럼 그게 왼쪽 오른쪽으로 간 횟수다
//결국 그 값들과 L,R을 비교하면 갈 수 있는지 없는지 확인 가능하다!

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define ll long long 
ll n,m,l,r;
ll L = 1e2;
ll R = 1e9;
ll d[1010][1010];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int map[1010][1010],Rx,Ry;

int main(){
    //freopen("input.txt","r",stdin);
    memset(d,-1,sizeof(d));
    scanf(" %lld %lld %lld %lld",&n,&m,&l,&r);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %1d",&map[i][j]);
            if(map[i][j]==2) Rx=i,Ry=j;
        }
    }
    priority_queue<pair<ll,pair<int,int>>> pq;
    pq.push({(ll)0,{Rx,Ry}});
    while(!pq.empty()){
        ll cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(d[x][y] != -1) continue;
        d[x][y]=cost;

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            ll ncost = -cost;
            if(i==0) ncost -= R;
            if(i==1) ncost -= L;
            if(0<=nx && nx<n && 0<=ny && ny<m && (map[nx][ny] !=1)){
                if(d[nx][ny]==-1) pq.push({ncost,{nx,ny}});
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]==-1) continue;
            ll rcnt = d[i][j]/R;
            ll lcnt = (d[i][j]%R)/L;
            if(rcnt<=r && lcnt<=l) ans++;
        }
    }
    printf("%d\n",ans);
}