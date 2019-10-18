// 도수를 mid값으로 생각해보자
// 최대 32번 봐야하고 볼때마다 최대 NlogN연산을 한다고 생각해보자
// mid값까지의 도수중 선호도가 높은 n개를 정해보는 것이다
// 이분탐색을 통해 찾을 수 있다
// 오래걸린다

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
ll n,m,k;
vector<pair<ll,ll>> vt;
bool check(ll mid){
    vector<ll> temp;
    for(int i=0;i<k;i++){
        if(vt[i].first <= mid) temp.push_back(vt[i].second);
        else break;
    }
    if(temp.size()<n) return false;

    sort(temp.rbegin(),temp.rend());
    ll ret=0;
    for(int i=0;i<n;i++) ret+=temp[i];
    return (ret>=m);
}
int main(){
    scanf(" %lld %lld %lld",&n,&m,&k);
    for(int i=0;i<k;i++) {
        ll a,b; scanf(" %lld %lld",&a,&b);
        vt.push_back({b,a});
    }
    sort(vt.begin(),vt.end());
    ll s=1,e=1e13,ans= 1e13;
    while(s<=e){
        ll mid = (s+e)/2;
        if(check(mid)){
            ans = min(ans,mid);
            e = mid-1;
        }
        else s = mid+1;
    }
    if(ans==1e13) puts("-1");
    else printf("%lld\n",ans);
}