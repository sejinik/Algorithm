#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int n,low_depth;
vector<vector<int>> Graph,depth;
vector<pair<char,ll>> arr;
vector<int> p;

void make_depth(int now,int parent,int dep){
    p[now]=parent;
    depth[dep].push_back(now);
    low_depth=max(low_depth,dep);
    for(int i=0;i<Graph[now].size();i++){
        int next = Graph[now][i];
        if(next != parent) make_depth(next,now,dep+1);
    }
}

void solve(int dep){
    if(dep==0) return;
    for(int i=0;i<depth[dep].size();i++){
        int now = depth[dep][i];
        int parent = p[now];
        if (arr[now].first=='S'){
            if(arr[parent].first=='S') arr[parent].second+=arr[now].second;
            else {
                arr[parent].second-=arr[now].second;
                if(arr[parent].second<=0){
                    arr[parent].first='S';
                    arr[parent].second=-arr[parent].second;
                }
            }
        }
    }
    solve(dep-1);
}


int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d",&n);
    Graph.resize(n);
    arr.resize(n);
    depth.resize(n);
    p.resize(n);
    for(int i=1;i<n;i++){
        char c; ll cnt; int next;
        scanf(" %c %lld %d",&c,&cnt,&next);
        next--;
        Graph[i].push_back(next);
        Graph[next].push_back(i);
        arr[i]={c,cnt};
    }
    make_depth(0,-1,0);
    solve(low_depth);
    printf("%lld\n",arr[0].second);
}