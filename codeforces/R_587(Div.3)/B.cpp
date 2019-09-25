// 수식이 존재하는데 정렬해서 큰 수부터 앞에서 채워야만 답을 가질 수 있다

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll n,ans;
 
int main(){
    scanf(" %lld",&n);
    vector<pair<ll,int>> vt(n);
    for(int i=0;i<n;i++) {
        ll x; scanf(" %lld",&x);
        vt.push_back({x,i});
    }
    sort(vt.begin(),vt.end());
    reverse(vt.begin(),vt.end());
 
    for(ll i=0;i<n;i++){
        ans+=((i*vt[i].first)+1);
    }
    printf("%lld\n",ans);
    for(int i=0;i<n;i++) printf("%d ",vt[i].second+1);
}