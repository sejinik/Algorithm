#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,l,ans;
vector<pair<int,int>> vt;
bool cmp (const pair<int,int> &a, const pair<int,int>&b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %d %d",&n,&l);
    vt.resize(n);
    for(int i=0;i<n;i++) scanf(" %d %d",&vt[i].first,&vt[i].second);
    sort(vt.begin(),vt.end(),cmp);
    int last=-1;
    for(int i=0;i<n;i++){
        if(vt[i].second-1<=last) continue;
        if(last >= vt[i].first) vt[i].first = last+1;
        int dist = vt[i].second-vt[i].first;
        int cnt = dist/l;
        if(dist%l != 0 ) cnt++;
        ans+=cnt;
        last = vt[i].first+(cnt*l)-1;
    }
    printf("%d\n",ans);
}