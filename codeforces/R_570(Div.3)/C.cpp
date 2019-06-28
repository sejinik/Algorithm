//이분탐색으로 mid값을 a판 한다고 생각하고 찾아가면 된다
//하지만 long long 써야한다
//곱할때 값이 넘어가가는거 생각안하고 틀렸다
//이분탐색 기본문제이다!

#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll q;
ll k,n,a,b;
bool ok(ll mid){
    ll ret = mid*a;
    ret+=(n-mid)*b;
    return (ret<k);
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf(" %lld",&q);
    while(q--){
        scanf(" %lld %lld %lld %lld",&k,&n,&a,&b);
        ll l=(ll)0,r=n;
        ll ans =-1;
        while(l<=r){
            ll mid = (l+r)/2;
            if(ok(mid)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%lld\n",ans);
    }
}