//그리디 알고리즘
//그냥 그대로 앞부터 덮어가면 된다
//벡터로 구현하다가 구현 오류가 많아서 많이 틀렸다
//변수를 더 잡더라도 정확하게 구현을 하자
//마지막으로 덮은 곳을 last에 두고 last와 다음 웅덩이의 시작지점을 비교했다
//만약 last가 더 크다면 웅덩이의 시작지점을 last+1로 바꾼다 

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