//트리에 관한 문제이다
//모든 정점은 흰색이고 정점을 골라 검은색으로 칠할 수 있다
//처음에는 아무 정점을 고르고 그 다음부터는 검은색과 연결된 정점을 고른다
//그 때 고른 정점과 연결된 흰 정점의 수가 내 점수이고 내 점수의 최댓값을 구하는 문제이다
//처음 접근한 방법은 리프노드 수를 보고 리프가 적은 곳을 루트로 정해서 자식의 수를 구하고 합하는 방식이였다
//근데 리프노드 수가 같을때 예외가 발생해서 자식수가 많은곳을 찾아야하는데 너무 복잡해졌다..!
//문제 해설을 보니 root를 계속 새로 정하며 dfs를 돌리면 해결 가능했다!
//똑같이 자식수를 미리 구하고 루트를 한 정점으로 찍어둔다
//그 후 dp[x] = x가 루트일 때로 정의하고 처음 정해준 root를 기준으로 값을 넣어둔다
// 그리고 dfs를 돌며 방문하는 정점을 root로 바꿔보는 것이다
// v->to로 갈때 루트가 v에서 to로 바뀐다면
// dp[v]에서는 더이상 dp[to]를 서브트리로 가지지 않으므로 뺴준다
// 그리고 dp[v]에는 sz[v]가있는데 sz[v]도 바뀌게된다 따라서 sz[to]도 함께 빼준다
// 그리고 바뀐 sz[v]를 위해 sz[v]에서도 sz[to]를 빼준다
// 그럼 dp[v]의 값은 to가 루트일 때로 변하게 된다
// 마찬가지로 dp[to]의 값도 바뀌어야 한다. 미리 dp[v]를 구했고 dp[v]는 to가 root일 때 값이므로
// 그대로 대해주면 된다. dp[to]+=dp[v], dp[to]에는 sz[to]가 들어가므로 sz[v]도 더해주고
// 마지막으로 sz[to]에 sz[v]를 더해 to의 사이즈값을 바꿔주고 dfs를 통해 to가 루트일때 값을 비교해준다
// 비교 후에는 다시 값을 원래대로 돌려주고 다른 자식에게도 똑같이 dfs를 타고 들어가본다
// dfs+dp를 이용한 재밌는 문제였는데 어렵다..!! 트리는 어려운거같다

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
    //freopen("input.txt","r",stdin);
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