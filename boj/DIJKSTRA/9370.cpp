//다익스트라를 이용한 문제
//거의 최단 경로와 같은 방법으로 풀었다
//각 정점마다 최단거리일 때 지나가는 경로를 저장하고
//다익스트라를 매번 돌려 확인한다
//시간제한이 3초여서 통과가 가능한데 최적화를 해야한다
//다른 사람들은 시간이 1초도 안걸리니까 무조건 확인을 해봐야하는 문제

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int T,n,m,t,s,g,h;
int d[2020];
vector<vector<pair<int,int>>> Graph;
vector<vector<int>> Passed;
vector<int>ans;

bool f(int u,int v){
    if(u==-1) return false;
    if((u==g&&v==h) || (u==h&&v==g)) return true;
    for(int i=0;i<Passed[u].size();i++) {
       if(f(Passed[u][i],u)) return true;
    }
    return false;
}
void dijk(int to){
    memset(d,-1,sizeof(d));
    Passed.clear();
    Passed.resize(n);
    priority_queue<pair<pair<int,int>,int>> pq;
    pq.push({{0,s},-1});
    while(!pq.empty()){
        int pos = pq.top().first.second;
        int cost = -pq.top().first.first;
        int pre = pq.top().second;
        pq.pop();

        if(d[pos]==cost) Passed[pos].push_back(pre);
        if(d[pos] != -1) continue;
        d[pos]=cost;
        Passed[pos].push_back(pre);
        for(int i=0;i<Graph[pos].size();i++){
            int next = Graph[pos][i].first;
            int ncost = -cost - Graph[pos][i].second;
            if(d[next]==-1) pq.push({{ncost,next},pos});
        }
    }
    if(d[to]==-1) return;
    for(int i=0;i<Passed[to].size();i++){
        if(f(Passed[to][i],to)) {
            ans.push_back(to); return;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&T);
    while(T--){
        Graph.clear();
        scanf(" %d %d %d",&n,&m,&t);
        Graph.resize(n);
        scanf("%d %d %d",&s,&g,&h);
        s--;g--;h--;
        for(int i=0;i<m;i++){
            int u,v,c; scanf(" %d %d %d",&u,&v,&c);
            u--; v--;
            Graph[u].push_back({v,c});
            Graph[v].push_back({u,c});
        }
        ans.clear();
        for(int i=0;i<t;i++){
            int e; scanf(" %d",&e); e--;
            dijk(e);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]+1);
        puts("");
    }
}