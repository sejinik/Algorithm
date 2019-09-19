#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll n,k;
vector<pair<ll,pair<ll,ll>>> vt;

bool solve(ll mid){
    ll atk =k;
    ll hp = mid;
    for(int i=0;i<n;i++){
        if(vt[i].first==1){
            ll cnt = vt[i].second.second/atk;
            if(vt[i].second.second%atk) cnt++;
            cnt--;
            hp-=(cnt*vt[i].second.first);
            if(hp<=0) return false;
        } else {
            atk+=vt[i].second.first;
            hp+=vt[i].second.second;
            if(hp>mid) hp=mid;
        }
    }
    return true;
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %lld %lld",&n,&k);
    for(int i=0;i<n;i++){
        ll a,b,c; scanf(" %lld %lld %lld",&a,&b,&c);
        vt.push_back({a,{b,c}});
    }
    ll l=1,r=1e18,ans=1e18;
    while(l<=r){
        ll mid = (l+r)/2;
        if(solve(mid)){
            ans = min(ans,mid);
            r = mid-1;
        } else l = mid+1;
    }
    printf("%lld\n",ans);
}
