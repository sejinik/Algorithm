#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
const int MAXN = 200020;
int n;
ll ans,dp[MAXN];
vector<vector<int>> Graph;
int sz[MAXN];

int calSz(int x,int p=-1){
    sz[x]=1;
    for(int i=0;i<Graph[x].size();i++){
        int next = Graph[x][i];
        if(next!=p) sz[x]+=calSz(next,x);
    }
    return sz[x];
}

ll calDp(int x,int p=-1){
    dp[x]=sz[x];
    for(int i=0;i<Graph[x].size();i++){
        int next = Graph[x][i];
        if(next!=p) dp[x]+=calDp(next,x);
    }
    return dp[x];
}

void solve(int x,int p=-1){
    ans = max(ans,dp[x]);
    for(int i=0;i<Graph[x].size();i++){
        int next = Graph[x][i];
        if(next!=p){
            dp[x]-=dp[next];
            dp[x]-=sz[next];
            sz[x]-=sz[next];
            dp[next]+=dp[x];
            dp[next]+=sz[x];
            sz[next]+=sz[x];
            solve(next,x);
            sz[next]-=sz[x];
            dp[next]-=sz[x];
            dp[next]-=dp[x];
            sz[x]+=sz[next];    
            dp[x]+=sz[next];
            dp[x]+=dp[next];
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    Graph.resize(n);
    for(int i=0;i<n-1;i++){
        int u,v; scanf(" %d %d",&u,&v);
        u--;v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    calSz(0);
    calDp(0);
    solve(0);
    printf("%lld\n",ans);
}