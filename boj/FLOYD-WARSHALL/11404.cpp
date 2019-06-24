//플로이드 기본문제
//최단거리를 구할때도 사용 가능하고 두 정점이 연결되어있는지 확인할때도 사용 가능
// d[i,k] = min(d[i,k],d[i,j]+d[j,k]);

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll inf = 1e9;
ll d[111][111];
int n,m;

int main(){
    //freopen("input.txt","r",stdin);
    for(int i=0;i<101;i++){
        for(int j=0;j<101; j++) d[i][j]=inf;
        d[i][i]=0;
    }
    scanf(" %d %d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,c; scanf(" %d %d %d",&u,&v,&c);
        u--;v--;
        d[u][v]=min(d[u][v],(ll)c);
    }

    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                d[i][k]=min(d[i][k],d[i][j]+d[j][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(d[i][j]==inf) d[i][j]=0;
            printf("%lld ",d[i][j]);
        }
        puts("");
    }
}