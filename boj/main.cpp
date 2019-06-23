#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int n,m,s,t,cnt;
int d[505],arr[505];
vector<vector<pair<int,int>>> graph;
vector<pair<pair<int,int>,int>> road;
vector<vector<int>> pre;
set<pair<int,int>> check;
void _remove(int u,int v){
    if(u==-1) return;
    for(int i=0;i<pre[u].size();i++) _remove(pre[u][i],u);
    check.insert({u,v});

}
int dijk(){
    memset(d,-1,sizeof(d));
    priority_queue<pair<pair<int,int>,int>> pq;
    pq.push({{0,s},-1});
    while(!pq.empty()){
        int pos = pq.top().first.second;
        int cost = -pq.top().first.first;
        int pr = pq.top().second;
        pq.pop();
        if(cost==d[pos]) pre[pos].push_back(pr);
        if(d[pos] != -1) continue;
        pre[pos].push_back(pr);
        d[pos]=cost;
        for(int i=0;i<graph[pos].size();i++){
            int next = graph[pos][i].first;
            int ncost = -cost -graph[pos][i].second;
            if(d[next]==-1)pq.push({{ncost,next},pos});
        }
    }
    return d[t];
}
int main(){
    freopen("input.txt","r",stdin);
    while(scanf(" %d %d",&n,&m)){
        if(n==0 && m==0) return 0;
        check.clear();
        road.clear();
        pre.clear();
        memset(arr,0,sizeof(arr));
        scanf("%d %d",&s,&t); cnt=0;
        graph.clear(); graph.resize(n); pre.resize(n);
        for(int i=0;i<m;i++){
            int u,v,c; scanf(" %d %d %d",&u,&v,&c);
            graph[u].push_back({v,c});
            road.push_back({{u,v},c});
        }
        int ans = dijk();
        for(int i=0;i<pre[t].size();i++) _remove(pre[t][i],t);
        graph.clear(); graph.resize(n);
        for(int i=0;i<road.size();i++){
            int u =road[i].first.first;
            int v = road[i].first.second;
            int c = road[i].second;
            if(check.count({u,v})) continue;
            graph[u].push_back({v,c});
        }
        ans = dijk();
        printf("%d\n",ans);
    }
}